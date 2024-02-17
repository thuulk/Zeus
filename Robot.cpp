#include <Robot.h>

using namespace frc;
using namespace std;

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

  SmartDashboard::PutNumber("left x : ", left_x);
  SmartDashboard::PutNumber("left y : ", left_y);
  SmartDashboard::PutNumber("right x : ", right_x);
  SmartDashboard::PutNumber("right y : ", right_y);
}

void Robot::AutonomousInit() {

  //Conf Timer y Compresor  
  m_timer.Reset();
  m_timer.Start();

  Compresor.Disable();

  /*Inicializacion del autonomo. Le damos a la variable m_autoselected 
  el valor del autonomo seleccionado en el smart dashboard*/
  m_autoSelected = m_chooser.GetSelected();

  cout << "Auto Selected:" << m_autoSelected << endl;

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

  //La Progra de cada Autónomo

  if (m_autoSelected == kAutoNameCustom1){ //Nombre 1

    //Estructura base de los autónomos
    //En x_s, x representa los segundos de movimiento
    
        
  }else if (m_autoSelected == kAutoNameCustom2){ //Nombre 2
   
    // (velocidad minimo, velocidad del robot, velocidad maximo)

    // Primer cara  
    if(m_timer.Get() < 3_s){
        I_Tank(-0.25,0.5,0.7);
        D_Tank(-0.25,0.5,0.7);
      
      //Tiempo muerto
      }else if(m_timer.Get() < 3.5_s){
        D_Tank(0.0,-0.5,0.5);
        I_Tank(0.0,-0.5,0.5);

      // Primer vuelta
      }else if(m_timer.Get() < 4.5_s){
        D_Tank(-0.45,-0.5,0.5);
        I_Tank(0.45,-0.5,0.5);

      // Tiempo muerto
      }else if(m_timer.Get() < 5_s){
        D_Tank(0.0,-0.5,0.5);
        I_Tank(0.0,-0.5,0.5);

      // Segunda cara
      }else if(m_timer.Get() < 8_s){
        D_Tank(-0.25,-0.5,0.5);
        I_Tank(-0.25,-0.0,0.5);

      //Tiempo muerto
      }else if(m_timer.Get() < 8.5_s){
        D_Tank(0.0,-0.5,0.5);
        I_Tank(0.0,-0.5,0.5);

      // Segunda vuelta
      }else if(m_timer.Get() < 9.5_s){
        D_Tank(-0.45,-0.5,0.5);
        I_Tank(0.45,-0.5,0.5);

      //Tiempo muerto
      }else if(m_timer.Get() < 10_s){
        D_Tank(0.0,-0.5,0.5);
        I_Tank(0.0,-0.5,0.5);
      
      // Tercer cara
      }else if(m_timer.Get() < 13_s){
        D_Tank(-0.25,-0.5,0.5);
        I_Tank(-0.25,-0.0,0.5);
      
      //Tiempo muerto
      }else if(m_timer.Get() < 13.5_s){
        D_Tank(0.0,-0.5, 0.5);
        I_Tank(0.0,-0.5, 0.5);
      
      // Tercer vuelta
      }else if(m_timer.Get() < 14.5_s){
        D_Tank(-0.45,-0.5,0.5);
        I_Tank(0.45,-0.0,0.5);
      
      // Tiempo muerto
      }else if(m_timer.Get() < 15_s){
        D_Tank(0.0,-0.5,0.5);
        I_Tank(0.0,-0.0,0.5); 

      // Cuarta cara
      }else if(m_timer.Get() < 18_s){
        D_Tank(-0.25,-0.5,0.5);
        I_Tank(-0.25,-0.0,0.5); 

      // Tiempo muerto
      }else if(m_timer.Get() < 18.5_s){
      D_Tank(0.0,-0.5,0.5);
      I_Tank(0.0,-0.0,0.5); 

      // Ultima vuelta
      }else if(m_timer.Get() < 19.5_s){
      D_Tank(-0.45,-0.5,0.5);
      I_Tank(0.45,-0.0,0.5); 
      }


  }else if (m_autoSelected == kAutoNameCustom3){ //Nombre 3

    if(m_timer.Get() <1.5_s){
        I_Tank(-0.3,-1.0,0.7);
        D_Tank(-0.3,-1.0,0.7);

      }else if(m_timer.Get() <2_s){
        D_Tank(0.0,-1.0,0.7);
        I_Tank(0.0,-1.0,0.7);
        
      }else if(m_timer.Get() <3.5_s){
        D_Tank(0.4,-1.0,0.7);
        I_Tank(0.4,-1.0,0.7);

      }else if(m_timer.Get() <9_s){
        D_Tank(0.7,-1.0,1.0);
        I_Tank(-0.7,-1.0,1.0);

      }

  }else if (m_autoSelected == kAutoNameCustom4){ //Nombre 4

  
 
  }else{ //Default 

  if(m_timer.Get() < 3_s){
      I_Tank(-0.5,-0.5,0.7);
      D_Tank(-0.5,-0.5,0.7);
    
    }else if(m_timer.Get() <5_s){
      D_Tank(0.0,-0.5,0.5);
      I_Tank(0.0,-0.5,0.5);

    }else if(m_timer.Get() <8_s){
      D_Tank(0.5,-0.5,0.5);
      I_Tank(0.5,-0.5,0.5);

    }else{
      D_Tank(0.0,-0.5,0.5);
      I_Tank(0.0,-0.5,0.5);
    }

    
  }

  ia++;

}

void Robot::TeleopInit() {
  
  //Confs Default Teleop
  it = 0;

  invertir_direccion = true;

  Compresor.Disable();
  Vacio.Set(false);
}

void Robot::TeleopPeriodic(){
  it++;

  //SmartDashboard

  SmartDashboard::UpdateValues();
  
  //Mapeo de los controles del driver 1
  
  leftbump = xbox.GetLeftBumper();
  rightbump = xbox.GetRightBumper();

  bA = xbox.GetAButton();
  bB = xbox.GetBButton();
  bY = xbox.GetYButton();
  bX = xbox.GetXButton();

  left_x = xbox.GetLeftX();
  left_y = xbox.GetLeftY();

  leftnt = -xbox.GetLeftY();
  rightnt = -xbox.GetRightY();

  right_x = xbox.GetRightX();
  right_y = xbox.GetRightY();

  righttrig = xbox.GetRightTriggerAxis();
  lefttrig = xbox.GetLeftTriggerAxis();


  if(bA == true){
    Compresor.EnableDigital();
  }else{

  }

  if(bB == true){
    Compresor.Disable();
  }else{

  }

  if(bX == true)
  {
    invertir_direccion = false;    
  }
  else if (bY == true)
  {
    invertir_direccion = true;
  }

  // Declarar Variable para cambio de sentido para trabajo del movimiento Robot  

  // Variable para sentido (invertir)
  

  // Comparación Variable para Mover Robot Tanque

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
  
  //Funciones de Botones Xbox Driver (resto)

  

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

  if(bA2 == true){
    Piston.Set(true);
  }else{

  }

  if(bB2 == true){
    Piston.Set(false);
  }else{

  }

  if(bX2 == true){
    Vacio.Set(true);
  }else{

  }

  if(bY2 == true){
    Vacio.Set(false);
  }else{

  }

  if(leftbump == true)
  {
    SPM1.Set(0.5);
  }
  else
  {
    if(rightbump == true)
    {
      SPM1.Set(-0.5);
    }
    else
    {
      SPM1.Set(0.0);
    }
  }

  if(lefttrig == true)
  {
    SPM2.Set(0.8);
  }
  else
  {
    if(righttrig == true)
    {
      SPM2.Set(-0.8);
    }
    else
    {
      SPM2.Set(0.0);
    }
  }
   
}

// Funciones de Movimiento

void Robot::D_Tank(double control,float lim_neg,float lim_pos)
{
    DA.Set(VictorSPXControlMode::PercentOutput, -limite_velocidad*control);
    DB.Set(VictorSPXControlMode::PercentOutput, limite_velocidad*control);
}

void Robot::I_Tank(double control,float lim_neg,float lim_pos)
{
    IA.Set(VictorSPXControlMode::PercentOutput, -limite_velocidad*control);
    IB.Set(VictorSPXControlMode::PercentOutput, -limite_velocidad*control);
}

void Robot::DS_Tank(double control,float lim_neg,float lim_pos)
{
    DA.Set(VictorSPXControlMode::PercentOutput, limite_velocidad*control);
    DB.Set(VictorSPXControlMode::PercentOutput, -limite_velocidad*control);
}

void Robot::IS_Tank(double control,float lim_neg,float lim_pos)
{
    IA.Set(VictorSPXControlMode::PercentOutput, limite_velocidad*control);
    IB.Set(VictorSPXControlMode::PercentOutput, limite_velocidad*control);
}

//Resto del Código

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FTC_TESTS
int main() { return StartRobot<Robot>(); }
#endif
