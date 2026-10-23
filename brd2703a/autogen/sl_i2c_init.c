/***************************************************************************//**
 * @file
 * @brief I2C driver instance initialization
 *******************************************************************************
 * # License
 * <b>Copyright 2025 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 ******************************************************************************/

#include "sl_clock_manager.h"
#include "sl_hal_gpio.h"
#include "sl_i2c.h"

// Include instance config 
#include "sl_i2c_qwiic_config.h"


// Handles
static sl_i2c_handle_t sl_i2c_qwiic_handle_instance;
sl_i2c_handle_t *sl_i2c_qwiic_handle = &sl_i2c_qwiic_handle_instance;
// Frequency mapping

#if SL_I2C_QWIIC_FREQ_MODE == 0
#define SL_I2C_QWIIC_MAX_FREQ      SL_I2C_FREQ_STANDARD_MODE
#elif SL_I2C_QWIIC_FREQ_MODE == 1
#define SL_I2C_QWIIC_MAX_FREQ      SL_I2C_FREQ_FAST_MODE
#elif SL_I2C_QWIIC_FREQ_MODE == 2
#define SL_I2C_QWIIC_MAX_FREQ      SL_I2C_FREQ_FASTPLUS_MODE
#endif


// Peripheral driver mapping - using peripheral number from config

#ifndef SL_I2C_QWIIC_PERIPHERAL_NO
#error "SL_I2C_QWIIC_PERIPHERAL_NO is not defined. Please update your board config file."
#endif

#if (SL_I2C_QWIIC_PERIPHERAL_NO == 0)
#define SL_I2C_QWIIC_PERIPHERAL_DRIVER    SL_PERIPHERAL_I2C0
#elif (SL_I2C_QWIIC_PERIPHERAL_NO == 1)
#define SL_I2C_QWIIC_PERIPHERAL_DRIVER    SL_PERIPHERAL_I2C1
#elif (SL_I2C_QWIIC_PERIPHERAL_NO == 2)
#define SL_I2C_QWIIC_PERIPHERAL_DRIVER    SL_PERIPHERAL_I2C2
#elif (SL_I2C_QWIIC_PERIPHERAL_NO == 3)
#define SL_I2C_QWIIC_PERIPHERAL_DRIVER    SL_PERIPHERAL_I2C3
#else
#error "Invalid I2C peripheral number for instance QWIIC. SL_I2C_QWIIC_PERIPHERAL_NO must be 0, 1, 2, or 3."
#endif



sl_i2c_init_params_t init_qwiic = { 
  .i2c_peripheral = SL_I2C_QWIIC_PERIPHERAL_DRIVER,
  .operating_mode = SL_I2C_QWIIC_OPERATING_MODE,
  .frequency_mode = SL_I2C_QWIIC_MAX_FREQ,
  .sda_gpio = (sl_gpio_t){.port = SL_I2C_QWIIC_SDA_PORT, .pin = SL_I2C_QWIIC_SDA_PIN},
  .scl_gpio = (sl_gpio_t){.port = SL_I2C_QWIIC_SCL_PORT, .pin = SL_I2C_QWIIC_SCL_PIN},
};

void sl_i2c_init_instances(void)
{
  sl_status_t status;
  // Initialize the I2C driver
  status = sl_i2c_init(sl_i2c_qwiic_handle, &init_qwiic);
  EFM_ASSERT(SL_STATUS_OK == status);
}