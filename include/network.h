#ifndef QUALITY_SENSOR_NETWORK_H
#define QUALITY_SENSOR_NETWORK_H

#include <WiFi.h>
#include <PubSubClient.h>
#include <Arduino.h>

class network
{
public:
    network();
    ~network() = default;
public:
    void init();
    void transmit(String payload);    
private:
    static void mqtt_callback(char *msg_a, uint8_t *length, unsigned int i);

    WiFiClient m_wifi_client;
    PubSubClient m_client;
};


#endif //QUALITY_SENSOR_NETWORK_H