#include "network.h"

#include <WiFi.h>
#include <PubSubClient.h>

network::network()
    : m_client(m_wifi_client)
    {

    }

void network::init() 
{
    const char *ssid = "ICTPraktijk";
    const char *password = "ICTPr@ktijk!";

    Serial.println("Connecting...");

    WiFi.begin(ssid,password);

    while (WiFi.status() != WL_CONNECTED);

    Serial.print("Connected to: ");
    Serial.println(ssid);

    const char *domain = "10.255.15.21";
    const char *topic = "finn-noud/113/temperatuur";
    const int mqtt_port = 1883;

    m_client.setServer(domain, mqtt_port);
    m_client.setCallback(mqtt_callback);


    while (!m_client.connected()) {
        if (WiFi.status() != WL_CONNECTED) {
            Serial.println("WiFi connection lost");
        }
        String client_id = "esp32-client-";
        client_id += String(WiFi.macAddress());

        Serial.printf("The client %s is trying to connect to the public MQTT broker\n", client_id.c_str());


        if (m_client.connect(client_id.c_str())) {
            Serial.println("Public EMQX MQTT broker connected");
        } else {
            Serial.print("failed with state ");
            Serial.println(m_client.state());
            delay(200);
        }
    }    

    transmit("Connected!");
}

void network::mqtt_callback(char *topic, byte *payload, unsigned int length) {

}


void network::transmit(String payload)
{
    m_client.publish("finn-noud/113/temperatuur",payload.c_str());
}