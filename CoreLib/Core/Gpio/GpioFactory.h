#pragma once
#include <memory>
#include "MyGpio.h"


class GpioFactory{
private:
        GpioFactory() = default;
public:
        static std::unique_ptr<iOutput> createOutput(const my_gpio_pin_t pin, const bool invert);
}

/*
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


class GpioFactoryManager {
private:
        static std::unique_ptr<iGpioFactory> _factory;
public:
        static std::unique_ptr<iGpioFactory> getFactory();
};
*/

