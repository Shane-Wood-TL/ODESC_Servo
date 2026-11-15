#ifndef __odesc_servo__
#define __odesc_servo__

#include "../ODESC_Driver/odesc_driver.h"


class odesc_servo {
    public:
        odesc motor;

        odesc_servo(odesc motor, float minimum_sensor_position, float maximum_sensor_position, float minimum_angle, float maximum_angle)
            : motor(motor), minimum_sensor_position(minimum_sensor_position), maximum_sensor_position(maximum_sensor_position) {
                minimum_measured_radians = minimum_angle * (3.14f / 180.0f);
                maximum_measured_radians = maximum_angle * (3.14f / 180.0f);
                motor.clear_errors();
            }
        

        void set_position_raw(float radians);
        void set_position_degrees(float degrees);
    private:
        // These are in radians
        float minimum_sensor_position;
        float maximum_sensor_position;
        float minimum_measured_radians;
        float maximum_measured_radians;
};

#endif
