#include "BasicLibraries.h"
#include "ComplimentaryFilter.h"
#include "PIDRegulator.h"

PID_REGULATOR::PID_REGULATOR(float p = 0.9f, float i = 0.9f, float d = 0.9f, float limit = 255.0f)
	: kp(p), ki(i), kd(d), limit_p(limit), limit_m(-limit) {};

float PID_REGULATOR::PID_Counter(float measured_point, float delta_time){
	float current_error, prev_error;
	float p_val, i_val, d_val;
	float current_error = setpoint - measured_point;

	p_val = current_error * kp; //расчет пропорциональной составляющей

	integral += current_error * delta_time;
	integral = std::clamp(integral, limit_m, limit_p); //интеграл с защитой от перенасыщения
	i_val = ki * integral; //расчет интегральной составляющей

	differential = (current_error - prev_error) / delta_time;
	d_val = kd * differential; //расчет дифференциальной составляющей

	prev_error = current_error;

	output_pid_val = p_val + i_val + d_val;
	output_pid_val = std::clamp(output_pid_val, limit_m, limit_p);
}

float PID_REGULATOR::get_pid_val() const { return output_pid_val; }

void PID_REGULATOR::reset_pid() {
	integral = 0.0f;
	prev_error = 0.0f;
}
