#include <WiFi.h>
#include <WebServer.h>
#include "WiFiSettings.h"

const int LED_BUILTIN = 16;//2; // Not defined in ESP32
int led_status = LOW;

const int HTTP_PORT = 80;
WebServer server(HTTP_PORT);

void handle_root() 
{
    Serial.println("handle_root()");
    server.send(200, "text/plain", "hello"); 
}

void handle_led_on() 
{
    Serial.println("handle_led_on()");
    led_status = HIGH;
    server.send(200, "text/plain", "LED status: ON");
}

void handle_led_off() 
{
    Serial.println("handle_led_off()");
    led_status = LOW;
    server.send(200, "text/plain", "LED status: OFF");
}

void handle_not_found()
{
    Serial.println("handle_not_found()");
    server.send(404, "text/plain", "Not found");
}

void setup()
{
    Serial.begin(115200);
    pinMode(LED_BUILTIN, OUTPUT);   
    digitalWrite(LED_BUILTIN, LOW);

    Serial.print("Connecting to ");
    Serial.println(SSID);
    WiFi.begin(SSID, PASSWORD);
    while (WiFi.status() != WL_CONNECTED) 
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());   
    
    server.on("/", handle_root);
    server.on("/led/on", handle_led_on);    
    server.on("/led/off", handle_led_off);
    server.onNotFound(handle_not_found);
    server.begin();
    Serial.print("HTTP server started on port: ");
    Serial.println(HTTP_PORT);
}


void loop()
{
    server.handleClient();
    digitalWrite(LED_BUILTIN, led_status);
}
