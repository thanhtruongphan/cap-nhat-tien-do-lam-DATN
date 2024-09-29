#ifndef CONTROL_MOTORS_H
#define CONTROL_MOTORS_H

#include <Arduino.h>  // Thư viện Arduino cần thiết

// #include "diffbot_base_config.h"
// #include <motor_controller_interface.h>

namespace diffbot {

    class MotorController {
    public:
        // Hàm khởi tạo nhận các chân điều khiển
        MotorController(uint8_t dir_pin1, uint8_t dir_pin2, uint8_t pwm_pin);
        
        // Hàm khởi tạo, gọi trong setup()
        void begin();
        
        // Hàm đặt tốc độ, giá trị có thể là âm hoặc dương
        void setSpeed(int value);

    private:
        uint8_t dir_pin1_;  // Chân điều khiển hướng 1
        uint8_t dir_pin2_;  // Chân điều khiển hướng 2
        uint8_t pwm_pin_;   // Chân điều khiển PWM
    };

}

#endif // CONTROL_MOTORS_H
