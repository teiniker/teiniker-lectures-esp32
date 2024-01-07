#include <Wire.h>

SemaphoreHandle_t i2cMutex;

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

void task2(void *parameter) 
{
    while(1) {
        if (xSemaphoreTake(i2cMutex, portMAX_DELAY) == pdTRUE) 
        {
            // Use I2C bus
            Wire.beginTransmission(deviceAddress2);
            // ... send or receive data
            Wire.endTransmission();

            xSemaphoreGive(i2cMutex);  // Release the mutex
        }
        vTaskDelay(20 / portTICK_PERIOD_MS);
    }
}


void setup() 
{
    i2cMutex = xSemaphoreCreateMutex();
    if (i2cMutex == NULL) 
    {
        // Handle error (e.g., print an error message and halt)
    }

    Wire.begin();
    // ... other setup code

    xTaskCreate(task1, "Task1", 2048, NULL, 1, NULL);
    xTaskCreate(task2, "Task2", 2048, NULL, 1, NULL);
}


void loop() 
{
    // Just a delay to prevent the loop from running wild.
    vTaskDelay(1000 / portTICK_PERIOD_MS);
}
