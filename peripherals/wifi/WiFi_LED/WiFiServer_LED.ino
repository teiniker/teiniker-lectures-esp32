#include <WiFi.h>
#include "WiFiSettings.h"

const int LED_BUILTIN = 2; // Not defined in ESP32
int led_status = LOW;

WiFiServer server(80);

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
    server.begin();
}

void loop()
{
    WiFiClient client = server.available();   // Listen for incoming clients
    if(client) 
    {                            
        Serial.println("New Client.");   
        String currentLine = "";               // make a String to hold incoming data from the client
        while(client.connected()) 
        {            
            if(client.available())             // if there are bytes to read from the client
            {            
                char c = client.read();        // read a byte from the client
                Serial.write(c);               
                if (c == '\n')                 // indicates end of a line 
                {                    
                    // if the current line is blank, you got two newline characters in a row.
                    // that's the end of the client HTTP request, so send a response:
                    if (currentLine.length() == 0) 
                    {
                        // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
                        // and a content-type so the client knows what's coming, then a blank line:
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-type:text/plain");
                        client.println();
                        client.print("LED status: ");
                        client.println(led_status);
                        break;
                    } 
                    else 
                    {    // if you got a newline, then clear currentLine:
                        currentLine = "";
                    }
                } 
                else if (c != '\r') 
                {                          // if you got anything else but a carriage return character,
                    currentLine += c;      // add it to the end of the currentLine
                }

                // Check to see if the client request was "GET /H" or "GET /L":
                if (currentLine.endsWith("GET /H")) 
                {
                    //digitalWrite(LED_BUILTIN, HIGH);               // GET /H turns the LED on
                    led_status = HIGH;
                }
                if (currentLine.endsWith("GET /L")) 
                {
                    //digitalWrite(LED_BUILTIN, LOW);                // GET /L turns the LED off
                    led_status = LOW;
                }
            }
        }

        digitalWrite(LED_BUILTIN, led_status);
        client.stop(); // close the connection:
        Serial.println("Client disconnected.");
    }
}
