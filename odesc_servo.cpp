#include "odesc_servo.h"

void odesc_servo::set_position_raw(float radians) {
    if (radians < minimum_sensor_position || radians > maximum_sensor_position) {
        ESP_LOGE("ODESC_SERVO", "Position out of bounds: %f", radians);
        return;
    }

    ESP_LOGI("ODESC_SERVO", "Setting position: %f", radians);
    //motor.set_input_position(radians, 10, 10);
}

void odesc_servo::set_position_degrees(float degrees) {
    float converted_radians = degrees * (3.14f / 180.0f);
    
    float radians = map(converted_radians, minimum_measured_radians, maximum_measured_radians, minimum_sensor_position, maximum_sensor_position);
    set_position_raw(radians);
}