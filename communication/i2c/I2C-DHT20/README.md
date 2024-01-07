# Example: DHT20 via I2C

The DHT20 is a **humidity and temperature sensor**.

The sensor has a **fixed address of 0x38**. It is not known if the address can be changed.

The library must be initiated by calling the begin() function, or begin(dataPin, clockPin) 
for ESP32 and similar platforms.

Thereafter one has to call the read() function to do the actual reading, and call 
getTemperature() and getHumidity() to get the measured values. Calling these latter again 
will return the same values until a new read() is done.


There are two timings that need to be considered (from datasheet):

* time between requests = 1000 ms.
* time between request and data ready = 80 ms.


## References

* [GitHub: DHT20 Library](https://github.com/RobTillaart/DHT20)
