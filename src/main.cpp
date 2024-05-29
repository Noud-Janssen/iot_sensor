#include <Arduino.h>
#include <ArduinoJson.h>

#include "network.h"
#include "sensor.h"
#include "config.h"
#include "timer.h"
#include "led.h"

sensor m_sensor(PIN_SENSOR);
network m_network;
led network_led(2);

JsonDocument packet;

utils::timer m_timer(READ_DELAY);

void setup()
{
  Serial.begin(9600);

  m_sensor.init();
  m_sensor.debug();

  m_network.init();

  m_timer.start();
}

int i = 0;

void loop()
{
  if (m_timer.is_triggered()) {
    network_led.on();
    float temp = m_sensor.get_temperature();
    float humidity = floor(m_sensor.get_humidity() + 0.5);


    if (temp != -255 || humidity != -255) {
      Serial.print(temp);
      Serial.println("C");
      Serial.print(humidity);
      Serial.println("%");

      packet["temperature"] = m_sensor.get_temperature();
      packet["humidity"] = m_sensor.get_humidity();

      String json_string;
      serializeJson(packet,json_string);
      Serial.println(json_string);
      m_network.transmit(json_string);

    }
    network_led.off();
  }
}
