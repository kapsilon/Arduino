// Include Library for LCD Screen Using
#include <LiquidCrystal.h>

// Digital Out Numbers to LCD Screen
const int RS_PIN = 6;
const int EN_PIN = 7;
const int D4_PIN = 8;
const int D5_PIN = 9;
const int D6_PIN = 10;
const int D7_PIN = 11;
LiquidCrystal lcd(RS_PIN, EN_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN);

void setup() {
	pinMode(RS_PIN, OUTPUT);
	pinMode(EN_PIN, OUTPUT);
	pinMode(D4_PIN, OUTPUT);
	pinMode(D5_PIN, OUTPUT);
	pinMode(D6_PIN, OUTPUT);
	pinMode(D7_PIN, OUTPUT);

	// Set LCD Screen's number of Columns and Rows:
	lcd.begin(16, 2);
}

void loop() {
	// Print to First Line
	lcd.print("Hello!");
	delay(5000);
	// Print to Second Line
	lcd.setCursor(2, 1);
	lcd.print("You're Super!!!");
	delay(5000);

	lcd.clear();
}
