#pragma once
#include "GpioFactory.h"
#include "Esp32Gpio.h"

std::unique_ptr<iOutput> GpioFactory::createOutput(const my_gpio_pin_t pin, const bool invert) {
ifdef ESP32
        return std::make_unique<Esp32GpioOutput>(pin, invert);
#endif
}
