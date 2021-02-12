
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

// Digital Out to Battery Module
const int BATTERY_VCC = 53;
const int BATTERY_GND = 51;
const int BATTERY_CLK = 49;
const int BATTERY_DAT = 47;
const int BATTERY_RST = 45;
// Include Library for Battery Clock DS1302
#include <Wire.h>
#include <iarduino_RTC.h>
// Initialization of DS1302
iarduino_RTC rtc(RTC_DS1302, BATTERY_RST, BATTERY_CLK, BATTERY_DAT);

// Set Current Date and Time
const char* strM = "JanFebMarAprMayJunJulAugSepOctNovDec";
const char* sysT = __TIME__;
const char* sysD = __DATE__;
// Convert Current Date and Time to Variables
const int sysSeconds = (sysT[6] - 48) * 10 + (sysT[7] - 48);
const int sysMinutes = (sysT[3] - 48) * 10 + (sysT[4] - 48);
const int sysHours = (sysT[0] - 48) * 10 + (sysT[1] - 48);
const int sysDay = (sysD[4] - 48) * 10 + (sysD[5] - 48);
const int sysMonth = ((int)memmem(strM, 36, sysD, 3) + 3 - (int)&strM[0]) / 3;
const int sysYear = (sysD[9] - 48) * 10 + (sysD[10] - 48);

// Set Variables for loop
unsigned long timerDate;
unsigned long timerTime;
char* timerDisplay;
int count = 0;

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

	// SevenSegment Library Settings
	byte numDigits = 4;
	byte digitPins[] = {D4, D3, D2, D1};
	byte segmentPins[] = {A, B, C, D, E, F, G, DP};
	bool resistorsOnSegments = true;
	bool updateWithDelaysIn = true;
	byte hardwareConfig = COMMON_CATHODE;
	// SevenSegment Library Settings Turn On
	sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins,
				 resistorsOnSegments);
	sevseg.setBrightness(90);

	// Set Battery Clock Pins to Output Mode
	pinMode(BATTERY_VCC, OUTPUT);
	pinMode(BATTERY_GND, OUTPUT);
	digitalWrite(BATTERY_VCC, HIGH);
	digitalWrite(BATTERY_GND, LOW);
	// Set Clock to Run
	rtc.begin();
	// Set Current Time and Date
	if (rtc.Hours != sysHours || rtc.minutes != sysMinutes) {
		rtc.settime(sysSeconds, sysMinutes, sysHours, sysDay, sysMonth,
					sysYear);
	}

	// DEBUG on Board
	//Serial.begin(9600);
}

void loop() {
	digitalWrite(BATTERY_VCC, HIGH);
	digitalWrite(BATTERY_GND, LOW);

	// Get Current Time Every Second
	if (millis() % 1000 == 0) {
		count += 1;
		// Get Current Date Every 10 Second
		if (count == 10) {
			timerDisplay = rtc.gettime("d.m");
			count = 0;
		} else {
			timerDisplay = rtc.gettime("H.i");
		}
	}

	// Get Time to Display
	sevseg.setChars(timerDisplay);
	sevseg.refreshDisplay();
}
