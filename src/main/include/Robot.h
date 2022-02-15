// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <Libraries.hpp>
#include <Configuration.hpp>
#include <Settings.hpp>

//#include <../subsystem/Dashboard.hpp>
#include <../subsystem/Drivetrain.hpp>
#include <../subsystem/Input.hpp>
#include <../subsystem/Autonomous.hpp>
#include <../subsystem/Shooter.hpp>

using namespace std;
/*
The class for the robot
*/
class Robot : public frc::TimedRobot {
private:
  frc::SendableChooser<string> m_chooser;
  const string kAutoNameDefault = "Default";
  const string kAutoNameCustom = "My Auto";
  string m_autoSelected;
  
  int FLSwerve[2] = {FLD,FLS}; //The front-left swerve drive
  int FRSwerve[2] = {FRD,FRS}; //The front-right swerve drive
  int BLSwerve[2] = {BLD,BLS}; //The back-left swerve drive
  int BRSwerve[2] = {BRD,BRS}; //The back-right swerve drive

protected:
  double driveTargetState[2] = {0,0}; //the target state of the robot drivetrain

  Drivetrain drivetrain = Drivetrain(FLSwerve,FRSwerve,BLSwerve,BRSwerve);
  
  //sticks
  Input inputs = Input(DRIVE_STICK,STEER_STICK);
  double * inputVals; //used to not have to call GetInputs() 4 times
  

public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;
};