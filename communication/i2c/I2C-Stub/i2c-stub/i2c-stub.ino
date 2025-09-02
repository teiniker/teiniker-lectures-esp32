#include <Wire.h>
 
// I2C Servant 

// Define Slave I2C Address
#define SLAVE_ADDR 0x20
 
void receiveEvent(int i) 
{
 
  // Read while data received
  while (0 < Wire.available()) 
  {
    byte x = Wire.read();
    Serial.println(x,BIN);
  }
}


void setup() 
{
 
  // Initialize I2C communications as Slave
  Wire.begin(SLAVE_ADDR);
  
  // Function to run when data received from master
  Wire.onReceive(receiveEvent);
  
  // Setup Serial Monitor 
  Serial.begin(115200);
  Serial.println("I2C Slave started");
}
 
 

void loop() 
{
 
  // Time delay in loop
  delay(50);
}