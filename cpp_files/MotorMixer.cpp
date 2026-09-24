#include "BasicLibraries.h"
#include "MotorMixer.h"

MOTOR_MIXER::MOTOR_MIXER(float c_x, float c_y) : control_x(c_x), control_y(c_y), deg_motor1(0.0f), deg_motor2(0.0f), deg_motor3(0.0f) {};

void MOTOR_MIXER::Motor_Output_C() {
	deg_motor1 = control_y; //тк мотор на 0 градусов относительно Y
	deg_motor2 = (-(std::sqrt(3.0f) / 2.0f) * control_x) - ((1.0f / 2.0f) * control_y);//тк мотор на 120 градусов относительно Y
	deg_motor3 = ((std::sqrt(3.0f) / 2.0f) * control_x) - ((1.0f / 2.0f) * control_y);//тк мотор на 240 градусов относительно Y
}

float MOTOR_MIXER::Get_Val_Mot_1() const { return deg_motor1; }
float MOTOR_MIXER::Get_Val_Mot_2() const { return deg_motor2; }
float MOTOR_MIXER::Get_Val_Mot_3() const { return deg_motor3; }