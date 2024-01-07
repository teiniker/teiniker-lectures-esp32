#include <mbedtls/md.h>

String to_hex_string(uint8_t* buffer, int length) 
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

    uint8_t message[] = "Hello, ESP32!";
    uint8_t key[32] = { // Example 256-bit key
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
        0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
        0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
        0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f
    };
    uint8_t hmac_output[32]; // SHA-256 output will be 32 bytes

    Serial.println(to_hex_string(message, sizeof(message)-1));    

    // Initialize the mbedtls stuff
    mbedtls_md_context_t ctx;
    const mbedtls_md_info_t *info = mbedtls_md_info_from_type(MBEDTLS_MD_SHA256);
    // Initialize the context
    mbedtls_md_init(&ctx);
    // Setup the HMAC context with the hash info and the secret key
    if (mbedtls_md_setup(&ctx, info, 1)) 
    {
        Serial.println("Error: mbedtls_md_setup failed");
        return;
    }

    // Compute the HMAC
    mbedtls_md_hmac_starts(&ctx, key, 32);
    mbedtls_md_hmac_update(&ctx, message, sizeof(message)-1);
    mbedtls_md_hmac_finish(&ctx, hmac_output);
    // Free the context
    mbedtls_md_free(&ctx);

    Serial.print("HMAC value: ");
    Serial.println(to_hex_string(hmac_output, 32));
}

void loop() 
{
  // Nothing to do here for this example
}
