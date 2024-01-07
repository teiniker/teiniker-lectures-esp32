#define LED_BUILTIN 2 // Not defined in ESP32

void setup() 
{
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() 
{
    digitalWrite(LED_BUILTIN, HIGH);   
    delay(200);                         
    digitalWrite(LED_BUILTIN, LOW);     
    delay(200);                         
}
