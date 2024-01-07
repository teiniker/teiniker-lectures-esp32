#include <mbedtls/entropy.h>
#include <mbedtls/ctr_drbg.h>

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

    // Initialize mbedtls modules
    mbedtls_entropy_context entropy;
    mbedtls_ctr_drbg_context ctr_drbg;
    
    mbedtls_entropy_init(&entropy);
    mbedtls_ctr_drbg_init(&ctr_drbg);

    // Seed the random number generator
    int ret = mbedtls_ctr_drbg_seed(&ctr_drbg, mbedtls_entropy_func, &entropy, NULL, 0);
    if (ret != 0) 
    {
        Serial.printf("mbedtls_ctr_drbg_seed failed: -0x%04x\n", -ret);
        return;
    }

    // Generate random bytes
    const size_t len = 32; // for example, 32 bytes
    unsigned char random_bytes[len];

    ret = mbedtls_ctr_drbg_random(&ctr_drbg, random_bytes, len);
    if (ret != 0) 
    {
        Serial.printf("mbedtls_ctr_drbg_random failed: -0x%04x\n", -ret);
        return;
    }

    // Print the random bytes
    Serial.print("Generated random bytes: ");
    Serial.println(to_hex_string(random_bytes, len));

    // Free mbedtls contexts
    mbedtls_ctr_drbg_free(&ctr_drbg);
    mbedtls_entropy_free(&entropy);
}

void loop() 
{
  // Nothing to do here
}
