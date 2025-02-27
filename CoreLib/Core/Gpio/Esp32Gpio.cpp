#pragma once
#include "Esp32Gpio.h"

[[nodiscard]] esp_err_t Esp32GpioBase::init(void)
{
    esp_err_t status{ESP_OK};

    status |= gpio_config(&_cfg);

    return status;
}

[[nodiscard]] bool Esp32GpioOutput::init(void)
{
    esp_err_t status{Esp32GpioBase::init()};

    if (ESP_OK == status)
    {
        status |= set(_inverted_logic);
    }

    return status==ESP_OK ? true : false;
}

[[nodiscard]] bool Esp32GpioOutput::set(const bool state)
{
    esp_err_t status{ESP_OK};
    _state = state;
    status = gpio_set_level(_pin,
                            _inverted_logic ? !state : state)

    return status==ESP_OK ? true : false;
}

