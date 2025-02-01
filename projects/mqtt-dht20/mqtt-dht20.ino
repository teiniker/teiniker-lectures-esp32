#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT20.h>

#include "settings.h"

// Linux: mosquitto_sub -t esp32/counter -d

WiFiClient espClient;
PubSubClient client(espClient);
DHT20 DHT;

void setup(void) 
{
    Serial.begin(115200);

    while (DHT.begin() == false)
    ;  //  ESP32 default pins 21 22
    Serial.println(DHT20_LIB_VERSION);    

    setup_wifi();
    client.setServer(mqtt_server, 1883);
    delay(1000);
}

char mqtt_message[80];

void loop(void) 
{
    if (!client.connected()) 
    {
        reconnect();
    }
    client.loop();

    int status = DHT.read();
    float temperature = DHT.getTemperature();
    float humidity = DHT.getHumidity();
    if (status == DHT20_OK) 
    {
        sprintf(mqtt_message, "{\"Temperature\":%4.2f, \"Humidity\": %4.2f}", temperature, humidity);
        Serial.println(mqtt_message);
        client.publish("esp32/module-02", mqtt_message);
    }  
    else 
    {
        print_status(status);
    }
    delay(1000);
}

void setup_wifi(void) 
{
    delay(100);
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

void print_status(int status) 
{
  switch (status) {
    case DHT20_OK:
      Serial.print("OK");
      break;
    case DHT20_ERROR_CHECKSUM:
      Serial.print("Checksum error");
      break;
    case DHT20_ERROR_CONNECT:
      Serial.print("Connect error");
      break;
    case DHT20_MISSING_BYTES:
      Serial.print("Missing bytes");
      break;
    case DHT20_ERROR_BYTES_ALL_ZERO:
      Serial.print("All bytes read zero");
      break;
    case DHT20_ERROR_READ_TIMEOUT:
      Serial.print("Read time out");
      break;
    case DHT20_ERROR_LASTREAD:
      Serial.print("Error read too fast");
      break;
    default:
      Serial.print("Unknown error");
      break;
  }
  Serial.print("\n");
}

