#ifndef QUALITY_SENSOR_LED_H
#define QUALITY_SENSOR_LED_H

#include <Arduino.h>

class led
{
public:
    led(uint8_t pin);
    ~led() = default;
public:
    void on();
    void off();
private:
    uint8_t m_pin;
};

#endif // QUALITY_SENSOR_LED_H