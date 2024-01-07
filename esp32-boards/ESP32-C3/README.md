# ESP32-C3-DevKitC-02

## Arduino Pins

_Configuration_: arduino-esp32/variants/esp32c3/pins_arduino.h

```C 
#define EXTERNAL_NUM_INTERRUPTS 22
#define NUM_DIGITAL_PINS        22
#define NUM_ANALOG_INPUTS       6

static const uint8_t LED_BUILTIN = SOC_GPIO_PIN_COUNT+8;

static const uint8_t TX = 21;
static const uint8_t RX = 20;

static const uint8_t SDA = 8;
static const uint8_t SCL = 9;

static const uint8_t SS    = 7;
static const uint8_t MOSI  = 6;
static const uint8_t MISO  = 5;
static const uint8_t SCK   = 4;

static const uint8_t A0 = 0;
static const uint8_t A1 = 1;
static const uint8_t A2 = 2;
static const uint8_t A3 = 3;
static const uint8_t A4 = 4;
static const uint8_t A5 = 5;
```

## References
* [ESP32-C3-DevKitC-02](https://docs.espressif.com/projects/esp-idf/en/latest/esp32c3/hw-reference/esp32c3/user-guide-devkitc-02.html)

* [ESP32-C3 – Pinout](https://www.studiopieters.nl/esp32-c3-pinout/)

* [ESP32­C3 Series Datasheet](https://www.espressif.com/sites/default/files/documentation/esp32-c3_datasheet_en.pdf)

* [ESP32-C3-DevKitM-1](https://docs.espressif.com/projects/arduino-esp32/en/latest/boards/ESP32-C3-DevKitM-1.html)

* [ESP32-C3-12F using the Arduino IDE - Getting Started - Environment Setup](https://dev.to/rafalozan0/esp32-c3-12f-using-the-arduino-ide-getting-started-environment-setup-38ij)

* [Arduino core for the ESP32, ESP32-S2, ESP32-S3 and ESP32-C3](https://github.com/espressif/arduino-esp32#arduino-core-for-the-esp32-esp32-s2-esp32-s3-and-esp32-c3)
