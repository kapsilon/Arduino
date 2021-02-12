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
	delay(2000);
	// Print to First Line
	lcd.setCursor(4, 0);
	lcd.print("HELLO!");
	delay(5000);
	// Print to Second Line
	lcd.setCursor(0, 1);
	lcd.print("You are Super!!!");
	delay(5000);
	// Clear Display
	lcd.clear();

	// Cursor
	// Cursor ON
	lcd.cursor();
	// Moving Cursor
	for (int i = 0; i < 15; i++) {
		lcd.setCursor(i, 0);
		delay(450);
	}
	// Cursor OFF
	lcd.noCursor();
	lcd.clear();

	// Blinking Cursor
	// Blink ON
	lcd.blink();
	// Moving Cursor
	for (int i = 0; i < 15; i++) {
		lcd.setCursor(i, 1);
		delay(450);
	}
	// Blink OFF
	lcd.noBlink();
	lcd.clear();

	// Scroll (40 Maximum)
	lcd.print("Scroll 40 Positions StringLength to Left");
	for (int i = 0; i < 41; i++) {
		// Scroll One Position to Left:
		lcd.scrollDisplayLeft();
		delay(400);
	}
	lcd.clear();

	// AutScroll (25 Maximum)
	lcd.setCursor(16, 1);
	// AutScrolling ON
	lcd.autoscroll();
	String autoscroll = "AutoScroll String toLeft";
	for (int i = 0; i < autoscroll.length(); i++) {
		lcd.print(autoscroll[i]);
		delay(300);
	}
	delay(5000);
	// AutScrolling OFF
	lcd.noAutoscroll();
	lcd.clear();
}
