#include <ros.h>
#include "diffbot_base_config.h"
#include "base_controller.h"
#include "controller_motors.h"  // Sử dụng file control_motors.h

ros::NodeHandle nh;

using namespace diffbot;

// Khởi tạo đối tượng điều khiển động cơ bên trái và bên phải với các chân tương ứng
MotorController motor_controller_right = MotorController(MOTOR_RIGHT_DIR1_PIN, MOTOR_RIGHT_DIR2_PIN, MOTOR_RIGHT_PWM_PIN);
MotorController motor_controller_left = MotorController(MOTOR_LEFT_DIR1_PIN, MOTOR_LEFT_DIR2_PIN, MOTOR_LEFT_PWM_PIN);

// Khởi tạo BaseController với hai motor controllers
BaseController<MotorController, void> base_controller(nh, &motor_controller_left, &motor_controller_right);

void setup()
{
    base_controller.setup();
    base_controller.init();

    nh.loginfo("Initialize DiffBot Motor Controllers");

    // Khởi tạo động cơ
    motor_controller_left.begin();
    motor_controller_right.begin();

    nh.loginfo("Setup finished");
}

void loop()
{
    static bool imu_is_initialized;

    // Vòng lặp điều khiển chính cho base_controller.
    ros::Duration command_dt = nh.now() - base_controller.lastUpdateTime().control;
    if (command_dt.toSec() >= ros::Duration(1.0 / base_controller.publishRate().control_, 0).toSec())
    {
        base_controller.read();
        base_controller.write();
        base_controller.lastUpdateTime().control = nh.now();
    }

    // Dừng động cơ nếu không nhận lệnh điều khiển từ RobotHW
    command_dt = nh.now() - base_controller.lastUpdateTime().command_received;
    if (command_dt.toSec() >= ros::Duration(E_STOP_COMMAND_RECEIVED_DURATION, 0).toSec())
    {
        nh.logwarn("Emergency STOP");
        base_controller.eStop();
    }

    // Kiểm tra và xuất dữ liệu từ IMU nếu có
    ros::Duration imu_dt = nh.now() - base_controller.lastUpdateTime().imu;
    if (imu_dt.toSec() >= base_controller.publishRate().period().imu_)
    {
        if (!imu_is_initialized)
        {
            // Kiểm tra kết nối IMU
            // imu_is_initialized = initIMU();  // Uncomment this line when IMU initialization is available
            if (imu_is_initialized)
                nh.loginfo("IMU Initialized");
            else
                nh.logfatal("IMU failed to initialize. Check your IMU connection.");
        }
        else
        {
            // publishIMU();  // Uncomment this line when IMU publishing is available
        }
        base_controller.lastUpdateTime().imu = nh.now();
    }

    // Hiển thị giá trị encoder nếu cần debug
    if(base_controller.debug())
    {
        ros::Duration debug_dt = nh.now() - base_controller.lastUpdateTime().debug;
        if (debug_dt.toSec() >= base_controller.publishRate().period().debug_)
        {
            base_controller.printDebug();
            base_controller.lastUpdateTime().debug = nh.now();
        }
    }

    // Gọi tất cả các callback chờ xử lý
    nh.spinOnce();
}
