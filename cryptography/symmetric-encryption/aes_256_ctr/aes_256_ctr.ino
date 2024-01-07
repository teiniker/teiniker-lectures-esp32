#include "mbedtls/aes.h"


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

    mbedtls_aes_context aes;

    unsigned char key[32] = {
        // Example 256-bit key
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
        0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
        0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
        0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f
    };

    uint8_t nonce_counter_initial[16] = { // 16-byte nonce and counter
         0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f };
    uint8_t nonce_counter[16];
    memcpy(nonce_counter, nonce_counter_initial, 16);
    size_t nc_off = 0; // Offset in the current block for CTR mode
    uint8_t stream_block[16];

    uint8_t input[16] = "Hello, ESP32!"; // 16-byte plaintext
    uint8_t output[16]; // 16-byte buffer to store ciphertext
    uint8_t plain[16];

    // Input data
    Serial.print("Input data: ");
    Serial.println(to_hex_string(input, 16));

    // Encrypt input data using AES-256/CTR
    mbedtls_aes_init(&aes);
    mbedtls_aes_setkey_enc(&aes, key, 32 * 8); // Using 256-bit key
    mbedtls_aes_crypt_ctr(&aes, sizeof(input), &nc_off, nonce_counter, stream_block, input, output);
    Serial.print("Encrypted data: ");
    Serial.println(to_hex_string(output, 16));

    // Decrypt cypher text using AES-256/CTR
    // Reset nonce and counter
    memcpy(nonce_counter, nonce_counter_initial, 16);
    nc_off = 0;
    mbedtls_aes_crypt_ctr(&aes, sizeof(output), &nc_off, nonce_counter, stream_block, output, plain);
    Serial.print("Plain text data: ");
    Serial.println(to_hex_string(plain, 16));

    // Free AES context
    mbedtls_aes_free(&aes);
}

void loop() 
{
  // Nothing to do here for this example
}