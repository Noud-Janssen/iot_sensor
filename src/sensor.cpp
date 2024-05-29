#include "sensor.h"



sensor::sensor(uint8_t pin)
    : m_pin(pin), m_dht(pin, DHT11)
{
}

void sensor::init()
{
    m_dht.begin();
    m_dht.temperature().getSensor(&m_temp_sensor);
    m_dht.humidity().getSensor(&m_humidity_sensor);
}

void sensor::debug()
{
    m_dht.temperature().printSensorDetails();
    m_dht.humidity().printSensorDetails();
}

float sensor::get_temperature()
{
    sensors_event_t event;
    m_dht.temperature().getEvent(&event);
    if (isnan(event.temperature)) 
    {
        Serial.println(F("Error reading temperature!"));
        return -255;
    }
    return event.temperature;
}

float sensor::get_humidity()
{
    sensors_event_t event;
    m_dht.humidity().getEvent(&event);
    if (isnan(event.temperature)) 
    {
        Serial.println(F("Error reading relative humidity!"));
        return -255;
    }        
    return event.relative_humidity;
}