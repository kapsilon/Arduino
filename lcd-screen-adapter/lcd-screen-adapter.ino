// Include Libraries
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// Digital Out Numbers to LCD Screen
const int I2C_GND = 18;
const int I2C_V5 = 19;
const int I2C_SDA = 20;
const int I2C_SCL = 21;

// Set LCD Screen's number of I2C Channel, Columns and Rows
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
	// Set LCD Pins to Output Mode
	pinMode(I2C_V5, OUTPUT);
	pinMode(I2C_GND, OUTPUT);

	// Set LCD Power Supply
	digitalWrite(I2C_V5, HIGH);
	digitalWrite(I2C_GND, LOW);

	// Set LCD Screen
	lcd.init();
	lcd.backlight();
}

//
void loop() {
	// LCD Power Supply
	digitalWrite(I2C_V5, HIGH);
	digitalWrite(I2C_GND, LOW);

	lcd.setCursor(3, 0);
	lcd.print("Hello!");
	delay(5000);

	lcd.setCursor(0, 1);
	lcd.print("You're Super!!!");
	delay(5000);

	lcd.clear();
}
