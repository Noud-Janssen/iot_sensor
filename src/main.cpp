#include <Arduino.h>

#include "network.h"
#include "sensor.h"

sensor m_sensor(18);
network m_network;

void setup()
{
  Serial.begin(9600);

  // m_network.init();
}

int i = 0;

void loop()
{
  Serial.println(m_sensor.get_temperature());
  delay(3000);
}