#include <WiFi.h>
#include <PubSubClient.h>

#include "settings.h"

// Linux: mosquitto_sub -t esp32/counter -d

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi(void) 
{
    delay(10);
    // We start by connecting to a WiFi network
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) 
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}


void reconnect() 
{
    // Loop until we're reconnected
    while (!client.connected()) 
    {
        Serial.print("Attempting MQTT connection...");
        // Attempt to connect
        if (client.connect("ESP32Client")) 
        {
            Serial.println("connected");
        } 
        else 
        {
            Serial.print("failed, rc=");
            Serial.print(client.state());
            Serial.println(" try again in 5 seconds");
            // Wait 5 seconds before retrying
            delay(5000);
        }
    }
}

void setup(void) 
{
    Serial.begin(115200);

    setup_wifi();
    client.setServer(mqtt_server, 1883);
}

int counter = 0;
void loop(void) 
{
    if (!client.connected()) 
    {
        reconnect();
    }
    client.loop();

    char counterString[8];
    sprintf(counterString, "%04d", counter++);
    Serial.print("Counter: ");
    Serial.println(counterString);
    
    client.publish("esp32/counter", counterString);

    delay(2000);
}
