#include <Robot.h>

using namespace frc;
using namespace std;

//inicializacion del robot
void Robot::RobotInit(){ 

  // Cargar selección de autónomos al Smart Dashboard
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom1, kAutoNameCustom1);
  m_chooser.AddOption(kAutoNameCustom2, kAutoNameCustom2);
  m_chooser.AddOption(kAutoNameCustom3, kAutoNameCustom3);
  m_chooser.AddOption(kAutoNameCustom4, kAutoNameCustom4);
  m_chooser.AddOption(kAutoNameCustom5, kAutoNameCustom5);
  SmartDashboard::PutData("Auto Modes", &m_chooser);
}

void Robot::RobotPeriodic() { 

  //Valores que se ven en el SmartDashboard
  SmartDashboard::PutNumber("ia: ", ia);
  SmartDashboard::PutNumber("it: ", it);

  SmartDashboard::PutBoolean("LB : ", leftbump);
  SmartDashboard::PutBoolean("RB : ", rightbump);

  SmartDashboard::PutBoolean("bA : ", bA);
  SmartDashboard::PutBoolean("bB : ", bB);
  SmartDashboard::PutBoolean("bY : ", bY);
  SmartDashboard::PutBoolean("bX : ", bX);

  SmartDashboard::PutNumber("left x : ", left_y);
  SmartDashboard::PutNumber("left y : ", left_y);
  SmartDashboard::PutNumber("right x : ", right_x);
  SmartDashboard::PutNumber("right y : ", right_y);
}

void Robot::AutonomousInit() {

  // Reiniciando cronometro 
  m_timer.Reset();
  m_timer.Start();

  /*Inicializacion del autonomo. Le damos a la variable m_autoselected 
  el valor del autonomo seleccionado en el Smart Dashboard*/
  m_autoSelected = m_chooser.GetSelected();
  cout << "Autonomous Selected:" << m_autoSelected << endl;
  
  ia = 0;
}

void Robot::AutonomousPeriodic(){

  /* Esta funcion contiene los bloques de codigo de todos los caminos del autonomo.
  Estructura base de los autónomos
  En x_s, x representa los segundos de movimiento.
  (velocidad del robot, velocidad minima, velocidad maxima). */
  
  //Nombre 1
  if (m_autoSelected == kAutoNameCustom1){ //Nombre 1
    straight_forward();
  }

  //Nombre 2
  else if (m_autoSelected == kAutoNameCustom2){ //Nombre 2
    second_autonomous();
  }

  //Nombre 3
  else if (m_autoSelected == kAutoNameCustom3){ //Nombre 3
    third_autonomous();
    
  }

  //Nombre 4
  else if (m_autoSelected == kAutoNameCustom4){ 
    fourth_autonomous();
  }

  //Default 
  else{ 
    default_center();
  }
  ia++;
}

void Robot::TeleopInit() {
  
  //Confs Default Teleop
  it = 0;

  invertir_direccion = true;

}

void Robot::TeleopPeriodic(){
  
  /* Esta función es un loop for; para que el robot avanze, retroceda, gire o se detenga, necesita
  constantemente actualizar los valores tanto de los motores, como los booleanos (true or false),
  si es mecesario. */

  /* Esta linea aumenta el valor de "it" por una unidad cada vez que el loop se ejecuta,
  no se que funcion cumple en el codigo, por lo mismo, recomiendo no eliminarlo.*/
  it++;

  // Esta funcion actualiza los valores del SmartDashboard
  SmartDashboard::UpdateValues();
  
  // Mapeo de los controles del driver 1 ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  /* El metodo "xbox.Get + boton + ();"
  se usa para obtener el valor del boton que estas presionando, y lo almacenamos
  en una variable para usar esos valores despues cuando los necesitemos.*/
  leftbump = xbox.GetLeftBumper();
  rightbump = xbox.GetRightBumper();

  bY = xbox.GetYButton();
  bX = xbox.GetXButton();
  bA = xbox.GetAButton();
  bB = xbox.GetBButton();

  left_x = xbox.GetLeftX();
  left_y = xbox.GetLeftY();

  right_x = xbox.GetRightX();
  right_y = xbox.GetRightY();

  righttrig = xbox.GetRightTriggerAxis();
  lefttrig = xbox.GetLeftTriggerAxis();

  // Regresar la direccion de los motores a la normal
  if(bX == true){
    invertir_direccion = false;    
  }

  // Invertir la direccion de los motores
  if (bA == true){
    invertir_direccion = true;
  }

  // Activar motor del intake
  if (leftbump == true){
    SPM3.Set(1);
  }
  
  if (bB == true){
    SPM3.Set(-1);
  }

  // Desactivar motor del intake
  if(rightbump == true){
    SPM3.Set(0.0);
  }

  // Darle potencia a los motores del outtake
  SPM4.Set(-righttrig);  
  SPM2.Set(lefttrig);

  //Mapeo del control 2  ------------------------------------------------------------------------------------------------------------------------------------------------------
  leftbump2 = xbox2.GetLeftBumper();
  rightbump2 = xbox2.GetRightBumper();

  bA2 = xbox2.GetAButton();
  bB2 = xbox2.GetBButton();
  bY2 = xbox2.GetYButton();
  bX2 = xbox2.GetXButton();

  left_x2 = xbox2.GetLeftX();
  left_y2 = xbox2.GetLeftY();

  right_x2 = xbox2.GetRightX();
  right_y2 = xbox2.GetRightY();

  clamp(left_y2,-0.5,0.5);
  clamp(right_y2,-0.5,0.5);
  
  // Bloque de código que invierte la dirección de los motores ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  if (invertir_direccion == true){
    D_Tank(right_y);
    I_Tank(left_y);
  }
  else{
    D_Tank(right_y);
    I_Tank(left_y);
  }
}

// Funciones de Movimiento ------------------------------------------------------------------------------------------------------------------------------------------------------
void Robot::D_Tank(double control)
{
    VSPX4.Set(VictorSPXControlMode::PercentOutput, limite_velocidad*control);
    VSPX3.Set(VictorSPXControlMode::PercentOutput, limite_velocidad*control);
}

void Robot::I_Tank(double control)
{
    VSPX1.Set(VictorSPXControlMode::PercentOutput, -limite_velocidad*control);
    VSPX2.Set(VictorSPXControlMode::PercentOutput, -limite_velocidad*control);
}


void Robot::default_center(){

  if(m_timer.Get() < 5_s){
      SPM1.Set(1);
      SPM2.Set(1);
  }

  if(m_timer.Get() < 7_s){
      I_Tank(1);
      D_Tank(1);
  } 
}

void Robot::straight_forward(){

  if(m_timer.Get() < 2_s){
    I_Tank(1);
    D_Tank(1);

  }
}

void Robot::second_autonomous(){

}

void Robot::third_autonomous(){

}

void Robot::fourth_autonomous(){

}

void Robot::fifth_autonomous(){

}

void Robot::sixth_autonomous(){

}


//Resto del Código ------------------------------------------------------------------------------------------------------------------------------------------------------

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FTC_TESTS
int main() { return StartRobot<Robot>(); }
#endif
