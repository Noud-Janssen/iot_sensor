#include "led.h"

led::led(uint8_t pin)
    : m_pin(pin)
{
    pinMode(pin, OUTPUT);
}

void led::on()
{
    digitalWrite(m_pin, 1);
}

void led::off()
{
    digitalWrite(m_pin, 0);
}