#include "sensor.h"



sensor::sensor(uint8_t pin)
    : m_pin(pin), m_dht(pin, DHT11)
{
    m_dht.temperature().getSensor(&m_temp_sensor);
    m_dht.humidity().getSensor(&m_humidity_sensor);
}

int sensor::get_temperature()
{
    sensors_event_t event;
    m_dht.temperature().getEvent(&event);
    if (isnan(event.temperature)) 
    {
        return -1;
    }
    else 
    {
        return event.temperature;
    }

}