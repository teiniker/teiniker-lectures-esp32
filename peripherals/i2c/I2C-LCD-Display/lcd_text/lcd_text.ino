#include <LiquidCrystal_I2C.h>

// set the LCD number of columns and rows
const int LCD_COLUMNS = 16;
const int LCD_ROWS = 2;
const int LCD_I2C_ADDRESS = 0x27;

LiquidCrystal_I2C lcd(LCD_I2C_ADDRESS, LCD_COLUMNS, LCD_ROWS);  

void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.print("Hello, world!");
}

void loop()
{
}
