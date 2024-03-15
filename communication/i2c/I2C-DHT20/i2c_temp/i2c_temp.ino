#include "DHT20.h"
#include <ArduinoLog.h>

DHT20 DHT;
char mqtt_message[80];

void setup() {
  while (DHT.begin() == false)
    ;  //  ESP32 default pins 21 22

  Serial.begin(115200);
  Serial.print("DHT20 LIBRARY VERSION: ");
  Serial.println(DHT20_LIB_VERSION);

  Log.begin(LOG_LEVEL_VERBOSE, &Serial);
  Log.setShowLevel(false);
  delay(1000);
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

void loop() 
{
  int status = DHT.read();
  float temperature = DHT.getTemperature();
  float humidity = DHT.getHumidity();

  if (status == DHT20_OK) 
  {
    sprintf(mqtt_message, "{\"Temperature\":%4.2f, \"Humidity\": %4.2f}", temperature, humidity);
    Serial.println(mqtt_message);
  } 
  else 
  {
    print_status(status);
  }
  delay(1000);
}