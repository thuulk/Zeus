#pragma once

#include <frc/motorcontrol/PWMSparkMax.h>
#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>
#include <string>
#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/XboxController.h>
#include <frc/GenericHID.h>
#include <frc/motorcontrol/Spark.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/DriverStation.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/Joystick.h>
#include <frc/Compressor.h>
#include <frc/Solenoid.h>
#include <frc/Counter.h>
#include <frc/Timer.h>
#include <frc/motorcontrol/MotorController.h>
#include <frc/kinematics/DifferentialDriveWheelSpeeds.h>
#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/kinematics/ChassisSpeeds.h>
#include <frc/kinematics/SwerveDriveKinematics.h>
#include <cameraserver/CameraServer.h>
#include <cscore_oo.h>
#include <cscore.h>
#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>
#include <ctre/Phoenix.h>
#include <ctre/phoenix/motorcontrol/can/BaseMotorController.h>
#include <ctre/phoenix/motorcontrol/GroupMotorControllers.h>
#include <ctre/phoenix/CustomParamConfiguration.h>
#include <rev/CANSparkMax.h>
#include <rev/CANSparkMaxLowLevel.h>

using namespace std;
using namespace frc;

class Robot : public frc::TimedRobot {
 public:

  //Funciones

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
  void D_Tank(double control,float lim_neg,float lim_pos);
  void I_Tank(double control,float lim_neg,float lim_pos);
  void DS_Tank(double control,float lim_neg,float lim_pos);
  void IS_Tank(double control,float lim_neg,float lim_pos);

private:

  //Autónomos y SmartDashboard
  
  SendableChooser<string> m_chooser;
  const string kAutoNameDefault = "0(exp)";
  const string kAutoNameCustom1 = "1";
  const string kAutoNameCustom2 = "Cuadrado";
  const string kAutoNameCustom3 = "3";
  const string kAutoNameCustom4 = "4";
  const string kAutoNameCustom5 = "5";

  string m_autoSelected;

  int it = 0;
  int ia = 0; 

  //variables control

  XboxController xbox{0};

  bool leftbump = false;
  bool rightbump = false;
  bool bA = false;
  bool bB = false;
  bool bX = false;
  bool bY = false;

  double left_x = 0.0;
  double left_y = 0.0;
  double right_x = 0.0;
  double right_y = 0.0;
  double leftnt = 0.0;
  double rightnt = 0.0;

  double righttrig = 0.0;
  double lefttrig = 0.0;

  //Variables de los motores 

  bool invertir_direccion = true;
  int limite_velocidad = 0.5;
  
  //Sparks & Victors 

  VictorSPX DA{3}; 
  VictorSPX DB{4}; 
  VictorSPX IB{5}; 
  VictorSPX IA{6}; 

  rev::CANSparkMaxLowLevel::MotorType Brushed;
  
  rev::CANSparkMax SPM1{7,Brushed};
  rev::CANSparkMax SPM2{8,Brushed}; 

  Spark SP{0};
  
  //Solenoides y Compresor

  Solenoid Vacio{PneumaticsModuleType::CTREPCM,7};
  Solenoid Piston{PneumaticsModuleType::CTREPCM,6};

  Compressor Compresor{0, PneumaticsModuleType::CTREPCM};

  //Timer

  Timer m_timer;

  //Control 2

  XboxController xbox2{1};

  bool leftbump2 = false;
  bool rightbump2 = false;
  bool bA2 = false;
  bool bB2 = false;
  bool bX2 = false;
  bool bY2 = false;

  double left_x2 = 0.0;
  double left_y2 = 0.0;
  double right_x2 = 0.0;
  double right_y2 = 0.0;
  
    /*
    NOTA
    El valor de las variables no siempre
    tiene que ser el mismo, se cambiarán
    de acuerdo a las necesidades del robot
    y de como esté conectado
  */
};

