#include <WiFi.h>
#include <PubSubClient.h>

#include "settings.h"

// Linux: mosquitto_pub -t esp32/output -m  "on" -d

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

void callback(char* topic, byte* message, unsigned int length) 
{
    Serial.print("Message arrived on topic: ");
    Serial.print(topic);
    Serial.print(". Message: ");
    String messageTemp;
  
    for (int i = 0; i < length; i++) 
    {
        Serial.print((char)message[i]);
        messageTemp += (char)message[i];
    }
    Serial.println();

    // If a message is received on the topic esp32/output, we check 
    // if the message is either "on" or "off". 
    if (String(topic) == "esp32/output") 
    {
        Serial.print("Changing output to ");
        if(messageTemp == "on")
        {
            Serial.println("on");
        }
        else if(messageTemp == "off")
        {
            Serial.println("off");
        }
    }
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
            // Subscribe
            client.subscribe("esp32/output");
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
    client.setCallback(callback);
}

void loop(void) 
{
    if (!client.connected()) 
    {
        reconnect();
    }
    client.loop();

    // Do something

    delay(2000);
}
