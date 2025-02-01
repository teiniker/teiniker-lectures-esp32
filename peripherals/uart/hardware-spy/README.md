# Hardware UART 

Serial communication on pins TX/RX uses TTL logic levels (5V or 3.3V depending on the board). 
Don’t connect these pins directly to an RS232 serial port; they operate at +/- 12V and 
can damage your Arduino board.

```
SUT:                Double:
    RX [3] <--------- [GPIO 17] TX
    TX [1] ---------> [GPIO 16] RX
    GND    ----------  GND
```


## HardwareSerial

* UART1 cannot be used (pins are used for internal Flash Memory)
* UART2 can be used TX(17), RX(16)

## Arduino Library 

* **int available(void)**\
    Get the number of bytes (characters) available for reading from the serial port. 
    This is data that’s already arrived and stored in the serial receive buffer 
    (which holds 64 bytes).
    * Returns the number of bytes available to read.

* **int availableForWrite(void)**\
    Get the number of bytes (characters) available for writing in the serial buffer 
    without blocking the write operation.
    * Returns the number of bytes available to write.

* **int read(void)**\
    Reads incoming serial data.
    * Returns the first byte of incoming serial data available (or -1 if no data is available).

* **size_t readBytes(uint8_t *buffer, size_t length)**\
    Reads characters from the serial port into a buffer. 
    The function terminates if the determined length has been read, or it times out.
    * buffer: The buffer to store the bytes in.
    * length: The number of bytes to read.
    * Returns the number of bytes placed in the buffer. 

* **size_t readBytesUntil(char terminator, char *buffer, size_t length)**\
    Reads characters from the serial buffer into an array. The function terminates (checks being 
    done in this order) if the determined length has been read, if it times out, or if the terminator 
    character is detected (in which case the function returns the characters up to the last character 
    before the supplied terminator). The terminator itself is not returned in the buffer.
    * terminator: The character to search for.
    * buffer: The buffer to store the bytes in. 
    * length: The number of bytes to read. 

    



## References:
* [Arduino Library: Serial](https://www.arduino.cc/reference/en/language/functions/communication/serial/)

* [arduino-esp32/cores/esp32/HardwareSerial.h](https://github.com/espressif/arduino-esp32/blob/master/cores/esp32/HardwareSerial.h)

* [Additional ESP32 Serial Channels in Arduino IDE](https://youtu.be/GwShqW39jlE?si=pAudsxyYzuja3q6V)
* [ ESP32 UART Communication Explained with Example](https://microcontrollerslab.com/esp32-uart-communication-pins-example/)