# Accessing the I2C Bus from two Tasks

Using a mutex (short for "mutual exclusion") is a common way 
to ensure that only one task at a time can access a shared resource, 
like the I2C bus.

* Declare the Mutex: Declare a global variable for the mutex handle.
```C++
SemaphoreHandle_t i2cMutex;
```

* Initialize the Mutex in setup(): Before using the mutex, we need to create it.
```C++
void setup() 
{
    i2cMutex = xSemaphoreCreateMutex();
    if (i2cMutex == NULL) 
    {
        // Handle error (e.g., print an error message and halt)
    }
    //...
}
```

* Use the Mutex in Tasks: Whenever a task wants to use the I2C bus, it first 
    tries to "take" the mutex. If it's successful, the task proceeds to use 
    the I2C bus. Once done, the task "gives" back the mutex.
```C++
void task1(void *parameter) 
{
    while(1) 
    {
        if (xSemaphoreTake(i2cMutex, portMAX_DELAY) == pdTRUE) 
        {
            // Use I2C bus
            Wire.beginTransmission(deviceAddress1);
            // ... send or receive data
            Wire.endTransmission();

            xSemaphoreGive(i2cMutex);  // Release the mutex
        }
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}
```
    * xSemaphoreTake() tries to take the mutex. The function will block 
        until the mutex is available or the specified timeout expires. 
        Here, portMAX_DELAY is used, which means the task will wait 
        indefinitely until the mutex is available.

    * If the mutex is successfully taken, the task accesses the I2C bus.

    * After finishing with the I2C bus, the task releases the mutex using
        xSemaphoreGive(), allowing other tasks to use the I2C bus.

## References

* [YouTube: (Digi-Key Electronics) Introduction to RTOS Part 6: Mutex](https://youtu.be/I55auRpbiTs?si=57p6FpE6H6TNtaoJ)

