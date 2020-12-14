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

// Include Library for 4-Digit 7-Segment Display Using
#include "SevSeg.h"
SevSeg sevseg;

// Analog Out TermoResister
const int TERMO_GND = A0;
const int TERMO_PIN = A1;
const int TERMO_5V = A3;

int temp;
float tempC;


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
	pinMode(D1, OUTPUT);
	pinMode(D2, OUTPUT);
	pinMode(D3, OUTPUT);
	pinMode(D4, OUTPUT);

	// Set TermoResister Pins to Output/Input
	pinMode(TERMO_GND, OUTPUT);
	pinMode(TERMO_PIN, INPUT);
	pinMode(TERMO_5V, OUTPUT);
	analogReference(INTERNAL1V1);

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

	// DEBUG on Board
	Serial.begin(9600);
}

void loop() {
	digitalWrite(TERMO_GND, LOW);
	digitalWrite(TERMO_5V, HIGH);

	temp = analogRead(TERMO_PIN);
	tempC = temp / 9.31;
	Serial.println(tempC);

	sevseg.setNumber(tempC, 1);
	sevseg.refreshDisplay();
}
