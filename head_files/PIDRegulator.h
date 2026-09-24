#pragma once

class PID_REGULATOR {
COMPLIMENTARY_FILTER filter();
PID_REGULATOR(float p, float i, float d, float limit);
private:
	float kp, ki, kd;
	float limit_p, limit_m;
	float integral, differential;
	float setpoint = 0;
	float output_pid_val;
	float prev_error;
public:
	float PID_Counter(float measured_point, float delta_time);

	float get_pid_val() const;

	void reset_pid();
};