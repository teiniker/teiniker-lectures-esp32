#include "base64.hpp"

void setup() 
{
    Serial.begin(115200);

    unsigned char binary[] = {133, 244, 117, 206, 178, 195};
    unsigned char base64[9]; // 8 bytes for output + 1 for null terminator

    unsigned int base64_length = encode_base64(binary, 6, base64);

    Serial.print(base64_length); // Prints "8"
    Serial.print(": ");
    Serial.println(base64); // Prints "hfR1zrLD"

}

void loop() 
{
  // Nothing to do here for this example
}
