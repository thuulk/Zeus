#include <Robot.h>

using namespace frc;
using namespace std;

//holiwis, prueba belica
void Robot::RobotInit(){ //inicializacion del robot

  //Selección de Autónomos
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom1, kAutoNameCustom1);
  m_chooser.AddOption(kAutoNameCustom2, kAutoNameCustom2);
  m_chooser.AddOption(kAutoNameCustom3, kAutoNameCustom3);
  m_chooser.AddOption(kAutoNameCustom4, kAutoNameCustom4);
  m_chooser.AddOption(kAutoNameCustom5, kAutoNameCustom5);
  SmartDashboard::PutData("Auto Modes", &m_chooser);
}

void Robot::RobotPeriodic() { //

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
  el valor del autonomo seleccionado en el smart dashboard*/
  m_autoSelected = m_chooser.GetSelected();
  cout << "Autonomous Selected:" << m_autoSelected << endl;

  if (m_autoSelected == kAutoNameCustom1){
    //Toda la progra
  }else if (m_autoSelected == kAutoNameCustom2){
    //Toda la progra 2
  }else if (m_autoSelected == kAutoNameCustom3){
    //Toda la progra 3
  }else{
    //Toda la progra del default
  }

  ia = 0;
}

void Robot::AutonomousPeriodic(){

  /* Esta funcion contiene los bloques de codigo de todos los caminos del autonomo.
  Estructura base de los autónomos
  En x_s, x representa los segundos de movimiento.
  (velocidad del robot, velocidad minima, velocidad maxima). */

  if (m_autoSelected == kAutoNameCustom1){ //Nombre 1

    first_autonomous();

  }else if (m_autoSelected == kAutoNameCustom2){ //Nombre 2
   
    second_autonomous();

  }else if (m_autoSelected == kAutoNameCustom3){ //Nombre 3

    third_autonomous();

  }else if (m_autoSelected == kAutoNameCustom4){ //Nombre 4

    fourth_autonomous();

  }else{ //Default 

    default_autonomous();

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
  se usa para obtener el valor del boton que estas aplastando, y lo almacenamos
  en una variable para usar esos valores despues cuando los necesitemos.*/
  leftbump = xbox.GetLeftBumper();
  rightbump = xbox.GetRightBumper();

  bY = xbox.GetYButton();
  bX = xbox.GetXButton();

  left_x = xbox.GetLeftX();
  left_y = xbox.GetLeftY();

  right_x = xbox.GetRightX();
  right_y = xbox.GetRightY();

  righttrig = xbox.GetRightTriggerAxis();
  lefttrig = xbox.GetLeftTriggerAxis();


  if(bX == true) {
    invertir_direccion = false;    
  }
  
  if (bA == true) {
    invertir_direccion = true;
  }

  if (leftbump == true) {
    SPM1.Set(1);
  }

  if (rightbump == true) {
    SPM1.Set(0);
  }

  // Comparación Variable para Mover Robot Tanque ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

  if (invertir_direccion == true)
  {
    D_Tank(right_y,-limite_velocidad,limite_velocidad);
    I_Tank(left_y,-limite_velocidad,limite_velocidad);
  }
  else
  {
    DS_Tank(right_y,-limite_velocidad,limite_velocidad);
    IS_Tank(left_y,-limite_velocidad,limite_velocidad);
  }
  
  //Funciones de Botones Xbox Driver (resto) ------------------------------------------------------------------------------------------------------------------------------------------------------
  //Conf Control² (todo) 

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


  if(bY2 == true){
    
  }else{

  }

  if(leftbump == true){
    SPM1.Set(0.8);
  }
  
  
  if(rightbump == true){
    SPM2.Set(0.8);
  }
   

  /*if(lefttrig == true)
  {
    SPM2.Set(0.8);
  }else{
    
    if(righttrig == true)
    {
      SPM2.Set(-0.8);
    }
    else
    {
      SPM2.Set(0.0);
    }
  }*/
   
}

// Funciones de Movimiento ------------------------------------------------------------------------------------------------------------------------------------------------------

void Robot::D_Tank(double control, float lim_neg, float lim_pos)
{
    victorspx_derecha_delante.Set(VictorSPXControlMode::PercentOutput, limite_velocidad*control);
    victorspx_derecha_atras.Set(VictorSPXControlMode::PercentOutput, -limite_velocidad*control);
}

void Robot::I_Tank(double control, float lim_neg, float lim_pos)
{
    victorspx_izquierda_delante.Set(VictorSPXControlMode::PercentOutput, -limite_velocidad*control);
    victorspx_izquierda_atras.Set(VictorSPXControlMode::PercentOutput, -limite_velocidad*control);
}

void Robot::DS_Tank(double control, float lim_neg, float lim_pos)
{
    victorspx_derecha_delante.Set(VictorSPXControlMode::PercentOutput, -limite_velocidad*control);
    victorspx_derecha_atras.Set(VictorSPXControlMode::PercentOutput, limite_velocidad*control);
}

void Robot::IS_Tank(double control, float lim_neg, float lim_pos)
{
    victorspx_izquierda_delante.Set(VictorSPXControlMode::PercentOutput, limite_velocidad*control);
    victorspx_izquierda_atras.Set(VictorSPXControlMode::PercentOutput, limite_velocidad*control);
}

void Robot::default_autonomous(){

  if(m_timer.Get() < 3_s){
      SPM2.Set(1);
      SPM3.Set(1);
  }
  if(m_timer.Get() < 4.5_s){
      I_Tank(-1,-0.5,0.7);
      D_Tank(-1,-0.5,0.7);
    } 
}

void Robot::first_autonomous(){

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
