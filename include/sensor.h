#ifndef QUALITY_SENSOR_SENSOR_H
#define QUALITY_SENSOR_SENSOR_H

#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

struct temp_t {
    int32_t max_value;
    int32_t min_value;
};

class sensor
{
public:
    sensor(uint8_t pin);
    ~sensor() = default;

public:
    int get_temperature();
private:
    uint8_t m_pin;
    DHT_Unified m_dht;
    sensor_t m_temp_sensor;
    sensor_t m_humidity_sensor;

    temp_t m_temp;
};


#endif // QUALITY_SENSOR_SENSOR_H