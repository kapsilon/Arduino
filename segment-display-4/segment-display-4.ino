// Digital Out Number to 4-Digit 7-Segment Display (Low Pin Line)
const int DISPLAY_PIN_01 = 3;
const int DISPLAY_PIN_02 = 4;
const int DISPLAY_PIN_03 = 5;
const int DISPLAY_PIN_04 = 6;
const int DISPLAY_PIN_05 = 7;
const int DISPLAY_PIN_06 = 14;
// Digital Out Number to 4-Digit 7-Segment Display (High Pin Line)
const int DISPLAY_PIN_07 = 17;
const int DISPLAY_PIN_08 = 8;
const int DISPLAY_PIN_09 = 9;
const int DISPLAY_PIN_10 = 16;
const int DISPLAY_PIN_11 = 15;
const int DISPLAY_PIN_12 = 10;
// Set Segments&Digits by Pins (Just Table)
const int A = DISPLAY_PIN_08;
const int B = DISPLAY_PIN_12;
const int C = DISPLAY_PIN_04;
const int D = DISPLAY_PIN_02;
const int E = DISPLAY_PIN_01;
const int F = DISPLAY_PIN_09;
const int G = DISPLAY_PIN_05;
const int DP = DISPLAY_PIN_03;
const int D1 = DISPLAY_PIN_06;
const int D2 = DISPLAY_PIN_11;
const int D3 = DISPLAY_PIN_10;
const int D4 = DISPLAY_PIN_07;

// Set Variables for loop
int number = 0;
int counter = 0;
unsigned long timer;

// Include Library for 4-Digit 7-Segment Display Using
#include "SevSeg.h"
SevSeg sevseg;

void setup() {
	// Set Pins to Output Mode
	pinMode(A, OUTPUT);
	pinMode(B, OUTPUT);
	pinMode(C, OUTPUT);
	pinMode(D, OUTPUT);
	pinMode(E, OUTPUT);
	pinMode(F, OUTPUT);
	pinMode(G, OUTPUT);
	pinMode(DP, OUTPUT);
	pinMode(D1, OUTPUT);
	pinMode(D2, OUTPUT);
	pinMode(D3, OUTPUT);
	pinMode(D4, OUTPUT);

	// SevenSegment Library Settings
	byte numDigits = 4;
	byte digitPins[] = {D4, D3, D2, D1};
	byte segmentPins[] = {A, B, C, D, E, F, G, DP};
	bool resistorsOnSegments = true;
	bool updateWithDelaysIn = true;
	byte hardwareConfig = COMMON_CATHODE;
	// SevenSegment Library Settings Turn On
	sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
	sevseg.setBrightness(90);
}

void loop() {
	// Get 1111,2222...9999 Every Second
	// Via millis
	if (millis() - timer > 1000) {
		timer = millis();
		number += 1111;
	}

	// Zeroing by Cycle
	if (number > 9999) {
		number -= 9999;
	}

	// Show Digits
	if (number == 0) {
		// Set 0000 for 0
		sevseg.setNumber(0000, 0);
	} else {
		// Show Number
		sevseg.setNumber(number, 0);
	}
	sevseg.refreshDisplay();
}
