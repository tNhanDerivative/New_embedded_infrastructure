#pragma once
#include <driver/gpio.h>
#include <esp_err.h>
#include <map>
#include<MyGpio.h>

/*
gpio_num_t esp32_pin = GPIO_MAP.at(my_pin);
*/
static const std::map<my_gpio_pin_t, gpio_num_t> GPIO_MAP = {
        {PIN_0, GPIO_NUM_0},
        {PIN_1, GPIO_NUM_1},
        {PIN_2, GPIO_NUM_2},
        {PIN_3, GPIO_NUM_3},
        {PIN_4, GPIO_NUM_4},
        {PIN_5, GPIO_NUM_5},
        {PIN_6, GPIO_NUM_6},
        {PIN_7, GPIO_NUM_7},
        {PIN_8, GPIO_NUM_8},
        {PIN_9, GPIO_NUM_9},
        {PIN_10, GPIO_NUM_10},
        {PIN_11, GPIO_NUM_11},
        {PIN_12, GPIO_NUM_12},
        {PIN_13, GPIO_NUM_13},
        {PIN_14, GPIO_NUM_14},
        {PIN_15, GPIO_NUM_15},
        {PIN_16, GPIO_NUM_16},
        {PIN_17, GPIO_NUM_17},
        {PIN_18, GPIO_NUM_18},
        {PIN_19, GPIO_NUM_19},
        {PIN_20, GPIO_NUM_20},
        {PIN_21, GPIO_NUM_21},
        {PIN_22, GPIO_NUM_22},
        {PIN_23, GPIO_NUM_23},
        {PIN_24, GPIO_NUM_24},
        {PIN_25, GPIO_NUM_25},
        {PIN_26, GPIO_NUM_26},
        {PIN_27, GPIO_NUM_27},
        {PIN_28, GPIO_NUM_28},
        {PIN_29, GPIO_NUM_29},
        {PIN_30, GPIO_NUM_30},
        {PIN_31, GPIO_NUM_31},
        {PIN_32, GPIO_NUM_32},
        {PIN_33, GPIO_NUM_33},
        {PIN_34, GPIO_NUM_34},
        {PIN_35, GPIO_NUM_35},
        {PIN_36, GPIO_NUM_36},
        {PIN_37, GPIO_NUM_37},
        {PIN_38, GPIO_NUM_38},
        {PIN_39, GPIO_NUM_39}
};

class Esp32GpioBase
{
protected:
        const gpio_num_t _pin;
        const bool _inverted_logic = false;
        const gpio_config_t _cfg;
public:
        Esp32GpioBase(const gpio_num_t pin,
                const gpio_config_t& config, 
                const bool invert_logic = false) : _pin{pin}, _cfg{config}
        {
        };
        ~Esp32GpioBase()= default;
        [[nodiscard]] esp_err_t init(void);
};

class Esp32GpioOutput : public Esp32GpioBase, public iOutput{
private:
        bool _state = false;
public:
        Esp32GpioOutput(const gpio_num_t pin,
                const gpio_config_t& config,
                const bool invert_logic = false) : 
                Esp32GpioBase(pin, 
                        gpio_config_t{
                            .pin_bit_mask   = static_cast<uint64_t>(1) << pin,
                            .mode           = GPIO_MODE_OUTPUT,
                            .pull_up_en     = GPIO_PULLUP_DISABLE,
                            .pull_down_en   = GPIO_PULLDOWN_ENABLE,
                            .intr_type      = GPIO_INTR_DISABLE
                        }, 
                        invert_logic)
        {
        };
        ~Esp32GpioOutput()= default;
        [[nodiscard]] bool init(void);
        [[nodiscard]] bool set(const bool state);
}

/*
implementation:
bool set(const bool state); // return converted esp32 errors in future
bool toggle(void);              // return converted esp32 errors in future
bool state(void) { return _state; }
*/

