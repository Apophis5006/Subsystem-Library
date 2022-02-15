// Includes all the needed libraries

// Built-In:
#include <iostream>
#include <string>
#include <map>
//#include <tuple>

#include <fmt/core.h>

// CTRE_Phoenix:
#include <ctre/Phoenix.h> // CTRE_Phoenix Version: 5.19.4: https://www.ctr-electronics.com/downloads/api/cpp/html/index.html

// WPILib Version 2021.3.1: https://first.wpi.edu/wpilib/allwpilib/docs/release/cpp/index.html
// WPILib Classes:
#include <frc/TimedRobot.h> // https://first.wpi.edu/wpilib/allwpilib/docs/release/cpp/classfrc_1_1TimedRobot.html
#include <frc/DriverStation.h> // https://first.wpi.edu/wpilib/allwpilib/docs/release/cpp/classfrc_1_1DriverStation.html
#include <frc/smartdashboard/SmartDashboard.h> // https://first.wpi.edu/wpilib/allwpilib/docs/release/cpp/classfrc_1_1SmartDashboard.html
#include <frc/smartdashboard/SendableChooser.h> // https://first.wpi.edu/wpilib/allwpilib/docs/release/cpp/classfrc_1_1SendableChooser.html
#include <frc/RobotController.h>
#include <frc/Joystick.h> // https://first.wpi.edu/wpilib/allwpilib/docs/release/cpp/classfrc_1_1Joystick.html
#include <frc/AnalogInput.h> // https://first.wpi.edu/wpilib/allwpilib/docs/release/cpp/classfrc_1_1AnalogInput.html
//#include <frc/PWMVictorSPX.h> // https://first.wpi.edu/wpilib/allwpilib/docs/release/cpp/classfrc_1_1PWMVictorSPX.html

// Analog Devices Library (ADIS16448 Inertial Measurement Unit):
//#include <adi/ADIS16448_IMU.h> // https://wiki.analog.com/first/adis16448_imu_frc/cpp