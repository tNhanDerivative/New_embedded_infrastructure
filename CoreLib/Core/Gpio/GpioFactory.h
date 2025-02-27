#pragma once
#include <memory>
#include "MyGpio.h"


class iGpioFactory {
public:
        virtual ~iGpioFactory() = default;
        virtual std::unique_ptr<iOutputCore> createOutput(const my_gpio_pin_t pin, const bool invert) = 0;
};

class Esp32GpioFactory : public iGpioFactory {
public:
        ~Esp32GpioFactory() override = default;
        std::unique_ptr<iOutputCore> createOutput(my_gpio_pin_t pin, const bool invert) override;
};