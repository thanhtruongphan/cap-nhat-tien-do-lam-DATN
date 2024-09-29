#include "controller_motors.h"

diffbot::MotorController::MotorController(uint8_t dir_pin1, uint8_t dir_pin2, uint8_t pwm_pin)
    : dir_pin1_(dir_pin1), dir_pin2_(dir_pin2), pwm_pin_(pwm_pin) {}

void diffbot::MotorController::begin()
{
    // Set direction and PWM pins as output
    pinMode(dir_pin1_, OUTPUT);
    pinMode(dir_pin2_, OUTPUT);
    pinMode(pwm_pin_, OUTPUT);

    // Initialize motor to stopped state
    digitalWrite(dir_pin1_, LOW);
    digitalWrite(dir_pin2_, LOW);
    analogWrite(pwm_pin_, 0);
}

void diffbot::MotorController::setSpeed(int value)
{
    if (value > 0)
    {
        // Forward direction
        digitalWrite(dir_pin1_, HIGH);
        digitalWrite(dir_pin2_, LOW);
    }
    else if (value < 0)
    {
        // Reverse direction
        digitalWrite(dir_pin1_, LOW);
        digitalWrite(dir_pin2_, HIGH);

        // Convert negative value to positive for PWM
        value = -value;
    }
    else
    {
        // Stop the motor
        digitalWrite(dir_pin1_, LOW);
        digitalWrite(dir_pin2_, LOW);
    }

    // Set motor speed using PWM, ensuring value is between 0 and 255
    analogWrite(pwm_pin_, constrain(value, 0, 255));
}
