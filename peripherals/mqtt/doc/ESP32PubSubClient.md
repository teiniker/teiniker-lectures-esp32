# Setup MQTT Client (ESP32 / Arduino) 

We use the MQTT client library **PubSubClient**, Developed by Nick O'Leary.

PubSubClient is a lightweight MQTT client library designed for Arduino-based projects. 
It provides a client for simple publish/subscribe messaging with a server supporting MQTT. 
This library simplifies MQTT communication and enables efficient data exchange in 
Arduino-based IoT applications.

## Create an MQTT Connection

### TCP Connection

We need to import the **WiFi and PubSubClient libraries**. 
The WiFi library allows ESP32 to establish connections with Wi-Fi networks, 
while the PubSubClient library enables ESP32 to connect to an MQTT broker for 
publishing messages and subscribing to topics.

```C++
#include <WiFi.h>
#include <PubSubClient.h>
```

We configure the following parameters in a separate header file: Wi-Fi network 
name and password, MQTT broker address and port:
```C++
const char* ssid = "REPLACE_WITH_YOUR_SSID";
const char* password = "REPLACE_WITH_YOUR_PASSWORD";
const char* mqtt_server = "YOUR_MQTT_BROKER_IP_ADDRESS";
```
Note that only the header file tempate ist checked into Git, not the real values!






## References
* [MQTT on ESP32: A Beginner's Guide](https://www.emqx.com/en/blog/esp32-connects-to-the-free-public-mqtt-broker)

* [Arduino Client for MQTT](https://github.com/knolleary/pubsubclient)

* [ESP32 MQTT – Publish and Subscribe with Arduino IDE](https://randomnerdtutorials.com/esp32-mqtt-publish-subscribe-arduino-ide/)

