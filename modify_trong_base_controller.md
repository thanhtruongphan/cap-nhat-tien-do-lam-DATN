# sửa code ```l298_motor_driver.cpp```
* code:
```
#include "l298_motor_driver.h"
#include "stm32f4xx_hal.h" // Thay đổi nếu bạn đang dùng STM32 series khác

namespace diffbot {

    class L298MotorController {
    public:
        L298MotorController(GPIO_TypeDef* gpioPort1, uint16_t in1, GPIO_TypeDef* gpioPort2, uint16_t in2, TIM_HandleTypeDef* htim, uint32_t channel);
        void setSpeed(int value);

    private:
        GPIO_TypeDef* in1Port; // Cổng cho in1
        uint16_t in1Pin; // Chân in1
        GPIO_TypeDef* in2Port; // Cổng cho in2
        uint16_t in2Pin; // Chân in2
        TIM_HandleTypeDef* pwmTimer; // Tham chiếu đến Timer PWM
        uint32_t pwmChannel; // Kênh PWM
    };

    L298MotorController::L298MotorController(GPIO_TypeDef* gpioPort1, uint16_t in1, GPIO_TypeDef* gpioPort2, uint16_t in2, TIM_HandleTypeDef* htim, uint32_t channel) :
        in1Port(gpioPort1), in1Pin(in1), in2Port(gpioPort2), in2Pin(in2), pwmTimer(htim), pwmChannel(channel) 
    {
        HAL_GPIO_WritePin(in1Port, in1Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(in2Port, in2Pin, GPIO_PIN_RESET);
        // Cài đặt PWM ban đầu
        __HAL_TIM_SET_COMPARE(pwmTimer, pwmChannel, 0);
    }

    void L298MotorController::setSpeed(int value) {
        if (value > 0) {
            HAL_GPIO_WritePin(in1Port, in1Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(in2Port, in2Pin, GPIO_PIN_RESET);
            value = (value > 100) ? 100 : value; // Giới hạn giá trị PWM nếu cần
        } else if (value < 0) {
            HAL_GPIO_WritePin(in1Port, in1Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(in2Port, in2Pin, GPIO_PIN_SET);
            value = -value; 
            value = (value > 100) ? 100 : value; // Giới hạn giá trị PWM nếu cần
        } else {
            HAL_GPIO_WritePin(in1Port, in1Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(in2Port, in2Pin, GPIO_PIN_RESET); 
            value = 0; // Đặt tốc độ về 0
        }
        __HAL_TIM_SET_COMPARE(pwmTimer, pwmChannel, value); // Cài đặt PWM
    }
}
```
>>> ![image](https://github.com/user-attachments/assets/21ed5758-7ebf-4be7-9516-6ca96eecf237)
>>> ![image](https://github.com/user-attachments/assets/7908d37d-dcf5-4437-be53-a11286cb0f5a)
>>> ![image](https://github.com/user-attachments/assets/19737a16-5718-424c-ab37-5bc0d416a6a9)

* text:
    ```
    TIM_HandleTypeDef htimX; // Khai báo Timer
    // Cấu hình Timer ở đây
    
    // Tạo đối tượng L298MotorController
    diffbot::L298MotorController motorController(GPIOA, GPIO_PIN_12, GPIOA, GPIO_PIN_13, &htimX, TIM_CHANNEL_1);
    motorController.setSpeed(50); // Đặt tốc độ động cơ
    ```

# sửa code ```l298_motor_driver.cpp```
* code:
```
#ifndef L298_MOTOR_DRIVER_H
#define L298_MOTOR_DRIVER_H

#include "stm32f4xx_hal.h" // Bao gồm HAL cho STM32

namespace diffbot {

    class L298MotorController 
    {
    public:
        // Khởi tạo với các cổng GPIO và Timer PWM
        L298MotorController(GPIO_TypeDef* gpioPort1, uint16_t in1, GPIO_TypeDef* gpioPort2, uint16_t in2, TIM_HandleTypeDef* htim, uint32_t channel);

        // Hàm điều chỉnh tốc độ
        void setSpeed(int value);

    private:
        GPIO_TypeDef* in1Port; // Cổng GPIO cho chân in1
        uint16_t in1Pin; // Chân GPIO cho in1
        GPIO_TypeDef* in2Port; // Cổng GPIO cho chân in2
        uint16_t in2Pin; // Chân GPIO cho in2
        TIM_HandleTypeDef* pwmTimer; // Cấu trúc điều khiển PWM cho động cơ
        uint32_t pwmChannel; // Kênh PWM được sử dụng
    };

} 

#endif // L298_MOTOR_DRIVER_H
```
>>> ![image](https://github.com/user-attachments/assets/1cbacd05-788e-4838-923d-a1d5a0dd1f15)
>>> ![image](https://github.com/user-attachments/assets/fd8e19bb-5997-4d5e-a91f-354d83ad87fc)

