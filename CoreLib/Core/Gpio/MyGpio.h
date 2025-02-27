#pragma once
#include <memory>


enum my_gpio_pin_t{PIN_0, PIN_1, PIN_2, PIN_3, PIN_4, PIN_5, PIN_6, PIN_7, 
        PIN_8, PIN_9, PIN_10, PIN_11, PIN_12, PIN_13, PIN_14, PIN_15, 
        PIN_16, PIN_17, PIN_18, PIN_19, PIN_20, PIN_21, PIN_22, PIN_23, 
        PIN_24, PIN_25, PIN_26, PIN_27, PIN_28, PIN_29, PIN_30, PIN_31, 
        PIN_32, PIN_33, PIN_34, PIN_35, PIN_36, PIN_37, PIN_38, PIN_39};


class iOutput{
        virtual ~iOutput()= default;
        [[nodiscard]] virtual bool init(void)=0;
        [[nodiscard]] virtual bool set(const bool state);
};

// class OutputPin{
// private:
//         std::unique_ptr<iOutputCore> output_core;
// public:
//         OutputPin(const my_gpio_pin_t pin,const bool invert = false);
//         ~OutputPin()= default;
//         void set(void);
//         void clear(void);
//         void toggle(void);
// };

