#include <SoftwareSerial.h>

#define TX_PIN 12
#define RX_PIN 13

char buffer[64];

// Set up a new SoftwareSerial object
EspSoftwareSerial::UART softSerial;

void setup()
{
    Serial.begin(115200);
    softSerial.begin(115200, SWSERIAL_8N1, RX_PIN, TX_PIN, false);

    Serial.println("Software UART Spy started");
}

void loop()
{
    while (softSerial.available()) 
    {
        Serial.print(char(softSerial.read()));
    }
}
