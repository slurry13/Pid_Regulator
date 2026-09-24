#pragma once

class MOTOR_MIXER {
MOTOR_MIXER(float c_x, float c_y);
private:
	float deg_motor1, deg_motor2, deg_motor3;
	float control_x, control_y;
public:
	void Motor_Output_C();

	float Get_Val_Mot_1() const;
	float Get_Val_Mot_2() const;
	float Get_Val_Mot_3() const;
};