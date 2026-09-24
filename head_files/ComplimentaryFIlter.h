#pragma once

class COMPLIMENTARY_FILTER {
public:
	struct imu_output {
		float ax, ay, az; //получение ускроения от гироскопа-акселерометра
		float gx, gy, gz; //получение данных о поворотах от гироскова-акселерометра
	};
COMPLIMENTARY_FILTER(float filter_coef_input);
private:
	float pitch;
	float roll;
	float filter_coef;
public:
	void Filter_Updater(imu_output& imu, float delta_time);
	float get_pitch() const;
	float get_roll() const;
};