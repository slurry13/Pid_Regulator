
#include "BasicLibraries.h"
#include "ComplimentaryFilter.h"

COMPLIMENTARY_FILTER::COMPLIMENTARY_FILTER(float filter_coef_input = 0.98f) : pitch(0.0f), roll(0.0f), filter_coef(filter_coef_input) {};

void COMPLIMENTARY_FILTER::Filter_Updater(COMPLIMENTARY_FILTER::imu_output& imu, float delta_time) {
	float acc_pitch; //наклон по X по данным акселерометра
	float acc_roll; //наклон по Y по данным акселерометра

	acc_pitch = std::atan(imu.ax / std::sqrt(std::pow(imu.ay, 2) + std::pow(imu.az, 2))); //расчет угла наклона по оси X
	acc_roll = std::atan(imu.ay / std::sqrt(std::pow(imu.ax, 2) + std::pow(imu.az, 2))); //расчет угла наклона по оси Y

	pitch = filter_coef * (pitch + imu.gx * delta_time) + (1 - filter_coef) * acc_pitch;
	roll = filter_coef * (roll + imu.gy * delta_time) + (1 - filter_coef) * acc_roll;
}

float COMPLIMENTARY_FILTER::get_pitch() const { return pitch; } //возможность забрать переменную pitch извне класса
float COMPLIMENTARY_FILTER::get_roll() const { return roll; } //возможность забрать переменную roll извне класса
