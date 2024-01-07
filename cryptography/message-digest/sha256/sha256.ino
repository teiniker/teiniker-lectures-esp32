#include "mbedtls/sha256.h"


String to_hex_string(byte* buffer, int length) 
{
    String hexString = "";
    for (int i = 0; i < length; i++) 
    {
        char temp[3];
        sprintf(temp, "%02X", buffer[i]);
    hexString += temp;
  }
  return hexString;
}

void setup() 
{
    Serial.begin(115200);

    // Input data
    uint8_t data[] = "Hello, ESP32!";
    uint8_t hash[32];  // The SHA-256 hash will be stored here

    // Compute the hash
    mbedtls_sha256(data, sizeof(data) - 1, hash, 0);  // The "-1" is to exclude the NULL terminator from the hash

    // Print the hash in HEX
    Serial.print("SHA-256 hash: ");
    Serial.println(to_hex_string(hash, 32));
}

void loop() 
{
  // Nothing to do here for this example
}
