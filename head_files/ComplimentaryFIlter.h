#include "BasicLibraries.h"


struct imu_output {
    float ax, ay, az;
    float gx, gy, gz;
};

class COMPLIMENTARY_FILTER {
private:
    float pitch;
    float roll;
    float filter_coef;

public:
    COMPLIMENTARY_FILTER(float filter_coef_input = 0.98f);

    void Filter_Updater(const imu_output& imu, float delta_time);

    float get_pitch() const;
    float get_roll() const;
};