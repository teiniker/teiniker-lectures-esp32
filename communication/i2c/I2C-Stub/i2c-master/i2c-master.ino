#include <Wire.h>

// I2C Master

#include <Wire.h>

void setup() 
{
  Wire.begin(); // join i2c bus (address optional for master)
}


uint8_t invert(uint8_t data)
{
  return data ^ 0xff;
}

void loop() 
{
  uint8_t data = 0x01;
  
  for(int i = 0; i < 8; i++)
  {
    Wire.beginTransmission(0x20);     // PCF8574 IO (addresses from 0x20 to 0x27)
    Wire.write(invert(data << i));    // send one bytes
    Wire.endTransmission();           // stop transmitting
    delay(50);
  }

  data = 0x80;
  for(int i = 0; i < 8; i++)
  {
    Wire.beginTransmission(0x20);     // PCF8574 IO (addresses from 0x20 to 0x27)
    Wire.write(invert(data >> i));    // send one bytes
    Wire.endTransmission();           // stop transmitting
    delay(50);
  }
  
}