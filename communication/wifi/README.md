# WIFI 

The ESP32 can be used in two different WiFi modes.
* **Station (STA) Mode**: In STA, or Station, mode the ESP32 acts as a WiFi station or client. In this mode the ESP32 needs to know the SSID and Password to access the WiFi network.
The ESP32 is provided with an network IP address using the routers internal DHCP server. It can then be accessed using that address.  It is also possible to assign a fixed IP address to the ESP32, which is useful if you are using it as a web server where a changing IP address would cause difficulties for other clients.

* **Soft Access Point (AP) Mode**: In Soft Access Point, or AP, mode, the ESP32 provides a WiFi connection for external devices. These devices can be computers, phones, tablets, IoT devices or even other ESP32’s configured in STA mode.
The ESP32 can support a maximum of five external devices in AP mode. It has a default IP address of 192.168.4.1 and it will provide DHCP services to the externally connected devices.  The default IP address can be changed if it conflicts with existing devices.
This allows the ESP32 to create its own IP network, independent of any existing WiFi networks. You can secure the network with a password and choose the SSID (network name).

## WiFi Scanner
The first example sketch we will look at is the WiFi Scanner. As its name would imply, this program scans for local WiFi networks. It then prints the results on the serial monitor. The results include the network SSID (name), the signal strength in dBm and an indicator if the network is secured.

```C++
#include "WiFi.h"
 
void setup()
{
    Serial.begin(115200);
 
    // Set WiFi to station mode and disconnect from an AP if it was previously connected
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);
 
    Serial.println("Setup done");
}
 
void loop()
{
    Serial.println("scan start");
 
    // WiFi.scanNetworks will return the number of networks found
    int n = WiFi.scanNetworks();
    Serial.println("scan done");
    if (n == 0) 
    {
        Serial.println("no networks found");
    } 
    else 
    {
        Serial.print(n);
        Serial.println(" networks found");
        for (int i = 0; i < n; ++i) {
            // Print SSID and RSSI for each network found
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.print(WiFi.SSID(i));
            Serial.print(" (");
            Serial.print(WiFi.RSSI(i));
            Serial.print(")");
            Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
            delay(10);
        }
    }
    Serial.println("");
 
    // Wait a bit before scanning again
    delay(5000);
}
```



## References

* [Getting started with ESP32](https://dronebotworkshop.com/esp32-intro/)

* [ESP32 Useful Wi-Fi Library Functions](https://randomnerdtutorials.com/esp32-useful-wi-fi-functions-arduino/)