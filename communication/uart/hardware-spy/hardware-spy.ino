#define RXD2 16
#define TXD2 17

// HardwareSerial Serial2(2);

void setup() 
{
    // Note the format for setting a serial port is as follows: Serial2.begin(baud-rate, protocol, RX pin, TX pin);
    Serial.begin(115200);
 
    Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);
    Serial.println("Serial Txd is on pin: " + String(TX));
    Serial.println("Serial Rxd is on pin: " + String(RX));
}

char buffer[64];
void loop() 
{
  /* 
    while (Serial2.available()) 
    {
      Serial.print(char(Serial2.read()));
    }
  */
  if(Serial2.available() > 0)
  {
    size_t len = Serial2.readBytesUntil('\n', buffer, 64);
    buffer[len] = 0x00; // Terminate string
    Serial.print(len);
    Serial.print(": ");
    Serial.println(buffer);
  }
}