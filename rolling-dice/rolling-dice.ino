// Digital Out Number to Seven Segment Display (Low Pin Line)
const int DISPLAY_PIN_01 = 22;
const int DISPLAY_PIN_02 = 24;
const int DISPLAY_PIN_04 = 26;
const int DISPLAY_PIN_05 = 28;
// Digital Out Number to Seven Segment Display (High Pin Line)
const int DISPLAY_PIN_06 = 4;
const int DISPLAY_PIN_07 = 5;
const int DISPLAY_PIN_09 = 6;
const int DISPLAY_PIN_10 = 7;
// Set Segments by Pins (Just Table)
const int A = DISPLAY_PIN_09;
const int B = DISPLAY_PIN_10;
const int C = DISPLAY_PIN_04;
const int D = DISPLAY_PIN_02;
const int E = DISPLAY_PIN_01;
const int F = DISPLAY_PIN_07;
const int G = DISPLAY_PIN_06;
const int DP = DISPLAY_PIN_05;

// Digital Out Number to Button
const int BUTTON_5V = 12;
const int BUTTON_PIN = 13;

// Include Library for 4-Digit 7-Segment Display Using
#include "SevSeg.h"
SevSeg sevseg;

// Set Variables for loop
int number = 0;
int point = 0;
int buttonState = 0;
unsigned long timer;

void setup() {
	// Set Display Pins to Output Mode
	pinMode(A, OUTPUT);
	pinMode(B, OUTPUT);
	pinMode(C, OUTPUT);
	pinMode(D, OUTPUT);
	pinMode(E, OUTPUT);
	pinMode(F, OUTPUT);
	pinMode(G, OUTPUT);
	pinMode(DP, OUTPUT);

	// Set Display Pins
	pinMode(BUTTON_5V, OUTPUT);
	pinMode(BUTTON_PIN, INPUT);

	// SevenSegment Library Settings
	byte numDigits = 1;
	byte digitPins[] = {};	// For 1 Digit
	byte segmentPins[] = {A, B, C, D, E, F, G, DP};
	bool resistorsOnSegments = true;
	bool updateWithDelaysIn = true;
	byte hardwareConfig = COMMON_CATHODE;
	// SevenSegment Library Settings Turn On
	sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
}

void loop() {
	// Button Settings
	digitalWrite(BUTTON_5V, HIGH);
	buttonState = digitalRead(BUTTON_PIN);

	// Button On: Light Random Number and Blink of Dot
	if (buttonState == HIGH) {
		if (millis() - timer >= 1000) {
			timer = millis();
			point = !point;
		}
		sevseg.setNumber(number, point);
		sevseg.refreshDisplay();
		// Button Off: Rolling Dice and Get Random Number
	} else {
		rolling();
		number = random(0, 9);
	}
}

//Cycle Light in Circles
void rolling() {
	int pause = 250;
	digitalWrite(A, HIGH);
	delay(pause);
	refreshDisplay();
	digitalWrite(B, HIGH);
	delay(pause);
	refreshDisplay();
	digitalWrite(C, HIGH);
	delay(pause);
	refreshDisplay();
	digitalWrite(D, HIGH);
	delay(pause);
	refreshDisplay();
	digitalWrite(E, HIGH);
	delay(pause);
	refreshDisplay();
	digitalWrite(F, HIGH);
	delay(pause);
	refreshDisplay();
}

// Turn Off All Segments
void refreshDisplay() {
	digitalWrite(A, LOW);
	digitalWrite(B, LOW);
	digitalWrite(C, LOW);
	digitalWrite(D, LOW);
	digitalWrite(E, LOW);
	digitalWrite(F, LOW);
	digitalWrite(G, LOW);
	digitalWrite(DP, LOW);
}