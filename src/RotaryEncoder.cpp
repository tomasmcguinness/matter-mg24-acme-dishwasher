#include "RotaryEncoder.h"

#include "sl_gpio.h"
#include "sl_led.h"
#include "sl_sleeptimer.h"

extern "C" {
#include "sl_simple_led_instances.h"
}

#include <lib/support/logging/CHIPLogging.h>

namespace {

// Contact bounce gives several edges per press, so the switch is read once it has been still this long.
constexpr uint32_t kSwitchSettleMs = 30;

const sl_gpio_t kClk = { ROTARY_ENCODER_CLK_PORT, ROTARY_ENCODER_CLK_PIN };
const sl_gpio_t kDt  = { ROTARY_ENCODER_DT_PORT, ROTARY_ENCODER_DT_PIN };
const sl_gpio_t kSw  = { ROTARY_ENCODER_SW_PORT, ROTARY_ENCODER_SW_PIN };

// Indexed by (previous CLK/DT state << 2) | current state. Valid single steps give +1 or -1;
// no change, and invalid jumps of both lines at once (bounce), give 0.
const int8_t kQuadratureTable[16] = { 0, -1, 1, 0, 1, 0, 0, -1, -1, 0, 0, 1, 0, 1, -1, 0 };

// Both lines high: the encoder is resting in a detent.
constexpr uint8_t kRestState = 0b11;

RotaryEncoder::TurnCallback sOnTurn;
RotaryEncoder::ClickCallback sOnClick;

uint8_t sState;
int8_t sSteps;

sl_sleeptimer_timer_handle_t sSettleTimer;
bool sIsPressed;

#if ROTARY_ENCODER_SW_SHARES_LED0
// Stands in for the Silabs status LED, whose pin the switch now uses.
sl_status_t NoLedInit(void *)
{
    return SL_STATUS_OK;
}
void NoLedAction(void *) {}
sl_led_state_t NoLedGetState(void *)
{
    return SL_LED_CURRENT_STATE_OFF;
}
const sl_led_t kNoLed = { nullptr, NoLedInit, NoLedAction, NoLedAction, NoLedAction, NoLedGetState };
#endif

bool Read(const sl_gpio_t & gpio)
{
    bool value = false;
    sl_gpio_get_pin_input(&gpio, &value);
    return value;
}

uint8_t ReadState()
{
    return static_cast<uint8_t>((Read(kClk) ? 0b10 : 0) | (Read(kDt) ? 0b01 : 0));
}

void OnRotation(uint8_t, void *)
{
    const uint8_t state = ReadState();
    sSteps              = static_cast<int8_t>(sSteps + kQuadratureTable[(sState << 2) | state]);
    sState              = state;

    if (sSteps >= ROTARY_ENCODER_STEPS_PER_DETENT || sSteps <= -ROTARY_ENCODER_STEPS_PER_DETENT)
    {
        int8_t direction = sSteps > 0 ? 1 : -1;
        sSteps           = 0;
        sOnTurn(ROTARY_ENCODER_REVERSE ? static_cast<int8_t>(-direction) : direction);
    }
    else if (state == kRestState)
    {
        // Back in a detent without a full step: bounce or a partial turn, so start again.
        sSteps = 0;
    }
}

void OnSwitchSettled(sl_sleeptimer_timer_handle_t *, void *)
{
    // Pressed pulls the line low.
    const bool pressed = !Read(kSw);
    if (pressed == sIsPressed)
    {
        return;
    }
    sIsPressed = pressed;

    // A click is reported when the knob is released.
    if (!pressed)
    {
        sOnClick();
    }
}

void OnSwitch(uint8_t, void *)
{
    sl_sleeptimer_restart_timer_ms(&sSettleTimer, kSwitchSettleMs, OnSwitchSettled, nullptr, 0, 0);
}

void ConfigureInput(const sl_gpio_t & gpio, sl_gpio_interrupt_flag_t flags, sl_gpio_irq_callback_t callback)
{
    // In this mode DOUT selects the pull direction, so 1 is a pull-up.
    sl_gpio_set_pin_mode(&gpio, SL_GPIO_MODE_INPUT_PULL, true);

    int32_t interrupt = SL_GPIO_INTERRUPT_UNAVAILABLE;
    if (sl_gpio_configure_external_interrupt(&gpio, &interrupt, flags, callback, nullptr) != SL_STATUS_OK)
    {
        ChipLogError(AppServer, "[encoder] no free GPIO interrupt for P%c%u", 'A' + gpio.port, gpio.pin);
    }
}

} // namespace

void RotaryEncoder::Init(TurnCallback onTurn, ClickCallback onClick)
{
    sOnTurn  = onTurn;
    sOnClick = onClick;

#if ROTARY_ENCODER_SW_SHARES_LED0
    // The Silabs base application looks this up on every status LED update. Without this, its
    // writes would switch the switch pin's pull-up to a pull-down and fake clicks.
    sl_simple_led_array[0] = &kNoLed;
#endif

    ConfigureInput(kClk, SL_GPIO_INTERRUPT_RISING_FALLING_EDGE, OnRotation);
    ConfigureInput(kDt, SL_GPIO_INTERRUPT_RISING_FALLING_EDGE, OnRotation);
    ConfigureInput(kSw, SL_GPIO_INTERRUPT_RISING_FALLING_EDGE, OnSwitch);

    sState = ReadState();

    ChipLogProgress(AppServer, "[encoder] ready");
}
