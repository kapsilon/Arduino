// Digital Out Number to Seven Segment Display (Low Pin Line)
const int DISPLAY_PIN_01 = 8;
const int DISPLAY_PIN_02 = 9;
const int DISPLAY_PIN_04 = 10;
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

void setup() {
	// Set Pins to Output Mode
	pinMode(A, OUTPUT);
	pinMode(B, OUTPUT);
	pinMode(C, OUTPUT);
	pinMode(D, OUTPUT);
	pinMode(E, OUTPUT);
	pinMode(F, OUTPUT);
	pinMode(G, OUTPUT);
}

void loop() {
	// Set Segments to Light
	digitalWrite(A, HIGH);
	delay(500);
	digitalWrite(B, HIGH);
	delay(500);
	digitalWrite(C, HIGH);
	delay(500);
	digitalWrite(D, HIGH);
	delay(500);
	digitalWrite(E, HIGH);
	delay(500);
	digitalWrite(F, HIGH);
	delay(500);
	digitalWrite(G, HIGH);
	delay(500);
	refreshDisplay();

	// Set Numbers to Light
	for (int i = 0; i <= 9; i++) {
		displayDigit(i);
		delay(1000);
		refreshDisplay();
	}

	// Refresh Display
	refreshDisplay();
}

// Turn On Segments by Numbers 0-9
void displayDigit(int digit) {
	// Turn Off All Segments
	refresDisplay();

	// Turn On Segments by Number
	/* 		A
		   ---
		F |   | B
		  | G |
		   ---
		E |   | C
		  | D |
		   ---    */
	if (digit == 1) {
		digitalWrite(B, HIGH);
		digitalWrite(C, HIGH);
	}
	if (digit == 2) {
		digitalWrite(A, HIGH);
		digitalWrite(B, HIGH);
		digitalWrite(G, HIGH);
		digitalWrite(E, HIGH);
		digitalWrite(D, HIGH);
	}
	if (digit == 3) {
		digitalWrite(A, HIGH);
		digitalWrite(B, HIGH);
		digitalWrite(C, HIGH);
		digitalWrite(D, HIGH);
		digitalWrite(G, HIGH);
	}
	if (digit == 4) {
		digitalWrite(F, HIGH);
		digitalWrite(G, HIGH);
		digitalWrite(B, HIGH);
		digitalWrite(C, HIGH);
	}
	if (digit == 5) {
		digitalWrite(A, HIGH);
		digitalWrite(F, HIGH);
		digitalWrite(G, HIGH);
		digitalWrite(C, HIGH);
		digitalWrite(D, HIGH);
	}
	if (digit == 6) {
		digitalWrite(A, HIGH);
		digitalWrite(F, HIGH);
		digitalWrite(E, HIGH);
		digitalWrite(D, HIGH);
		digitalWrite(C, HIGH);
		digitalWrite(G, HIGH);
	}
	if (digit == 7) {
		digitalWrite(A, HIGH);
		digitalWrite(B, HIGH);
		digitalWrite(C, HIGH);
	}
	if (digit == 8) {
		digitalWrite(A, HIGH);
		digitalWrite(B, HIGH);
		digitalWrite(G, HIGH);
		digitalWrite(F, HIGH);
		digitalWrite(D, HIGH);
		digitalWrite(C, HIGH);
		digitalWrite(E, HIGH);
	}
	if (digit == 9) {
		digitalWrite(D, HIGH);
		digitalWrite(C, HIGH);
		digitalWrite(B, HIGH);
		digitalWrite(A, HIGH);
		digitalWrite(F, HIGH);
		digitalWrite(G, HIGH);
	}
	if (digit == 0) {
		digitalWrite(F, HIGH);
		digitalWrite(E, HIGH);
		digitalWrite(D, HIGH);
		digitalWrite(C, HIGH);
		digitalWrite(B, HIGH);
		digitalWrite(A, HIGH);
	}
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
}