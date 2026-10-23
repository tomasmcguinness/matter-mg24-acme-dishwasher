#pragma once

#include <stdint.h>

// CLK on EXP10 (PA07), which is otherwise free.
#ifndef ROTARY_ENCODER_CLK_PORT
#define ROTARY_ENCODER_CLK_PORT SL_GPIO_PORT_A
#endif
#ifndef ROTARY_ENCODER_CLK_PIN
#define ROTARY_ENCODER_CLK_PIN 7
#endif

// DT on EXP9 (PB00), shared with the blue LED, which the app doesn't use. The blue LED lights
// while this contact is closed.
#ifndef ROTARY_ENCODER_DT_PORT
#define ROTARY_ENCODER_DT_PORT SL_GPIO_PORT_B
#endif
#ifndef ROTARY_ENCODER_DT_PIN
#define ROTARY_ENCODER_DT_PIN 0
#endif

// SW on EXP13 (PD02), shared with the red LED. That LED was the Silabs network status LED, which
// RotaryEncoder::Init() disconnects. The red LED lights while the knob is pressed.
#ifndef ROTARY_ENCODER_SW_PORT
#define ROTARY_ENCODER_SW_PORT SL_GPIO_PORT_D
#endif
#ifndef ROTARY_ENCODER_SW_PIN
#define ROTARY_ENCODER_SW_PIN 2
#endif

// Whether SW physically shares its pin with LED0 (the Silabs status LED), as on BRD2601B. When it
// does, RotaryEncoder::Init() disconnects LED0 so the base application's status blink doesn't
// fight the switch reading. Boards that wire the encoder elsewhere (e.g. BRD2703A's MikroBUS
// socket) must set this to 0, so LED0 is left alone.
#ifndef ROTARY_ENCODER_SW_SHARES_LED0
#define ROTARY_ENCODER_SW_SHARES_LED0 1
#endif

// Quadrature steps per click of the knob. KY-040 style encoders do a full cycle (4) per detent;
// some do half a cycle (2).
#ifndef ROTARY_ENCODER_STEPS_PER_DETENT
#define ROTARY_ENCODER_STEPS_PER_DETENT 4
#endif

// Swaps the turn direction, if clockwise selects the previous program.
#ifndef ROTARY_ENCODER_REVERSE
#define ROTARY_ENCODER_REVERSE 0
#endif

/**
 * Rotary encoder with push switch, read with GPIO interrupts.
 *
 * All callbacks run in interrupt context, so they must only hand the event on (e.g. post it to
 * the app task).
 */
class RotaryEncoder
{
public:
    // direction is +1 for clockwise and -1 for counter-clockwise, one call per detent.
    using TurnCallback  = void (*)(int8_t direction);
    using ClickCallback = void (*)();

    // A click is reported when the knob is released.
    static void Init(TurnCallback onTurn, ClickCallback onClick);
};
