// Digital Out Numbers to RGB LED 1
const int LED1_GND = 5;
const int LED1_RED = 4;
const int LED1_GREEN = 3;
const int LED1_BLUE = 2;

// Digital Out Numbers to RGB LED 2
const int LED2_RED = 12;
const int LED2_GREEN = 11;
const int LED2_BLUE = 10;

// Digital Out Numbers to Infra-Red Receiver
const int IR_Signal = 6;
const int IR_V5 = 7;

// Codes of Buttons IR Remote Controller HX1838
const int Button11 = 0xFFA25D;
const int Button12 = 0xFF629D;
const int Button13 = 0xFFE21D;
const int Button21 = 0xFF22DD;
const int Button22 = 0xFF02FD;
const int Button23 = 0xFFC23D;
const int Button31 = 0xFFE01F;
const int Button32 = 0xFFA857;
const int Button33 = 0xFF906F;
const int Button41 = 0XFF6897;
const int Button42 = 0xFF9867;
const int Button43 = 0xFFB04F;
const int Button51 = 0xFF30CF;
const int Button52 = 0xFF18E7;
const int Button53 = 0xFF7A85;
const int Button61 = 0xFF10EF;
const int Button62 = 0xFF38C7;
const int Button63 = 0xFF5AA5;
const int Button71 = 0xFF42BD;
const int Button72 = 0xFF4AB5;
const int Button73 = 0xFF52AD;

// Include Library for IR Receiver
#include <IRremote.h>
IRrecv ir(IR_Signal);
decode_results iresults;
int button;

void setup() {
	// Set LEDs Pins to Output Mode
	pinMode(LED1_GND, OUTPUT);
	pinMode(LED1_RED, OUTPUT);
	pinMode(LED1_GREEN, OUTPUT);
	pinMode(LED1_BLUE, OUTPUT);
	pinMode(LED2_RED, OUTPUT);
	pinMode(LED2_GREEN, OUTPUT);
	pinMode(LED2_BLUE, OUTPUT);

	// Set IR Receiver Pins to Input Mode
	pinMode(IR_Signal, INPUT);
	pinMode(IR_V5, OUTPUT);

	// Set Starting Color BLACK-rgb(0,0,0)
	setRGB0(1);
	setRGB0(2);

	// Set IR Receiver
	ir.enableIRIn();
	ir.blink13(true);

	// DEBUG on Board
	Serial.begin(9600);
}

void loop() {
	// Power Supply
	digitalWrite(IR_V5, HIGH);
	digitalWrite(LED1_GND, LOW);

	// Get IR Code
	if (ir.decode(&iresults)) {
		// DEBUG on Board, set 9600 at Serial Monitor
		Serial.println(iresults.value, HEX);
		button = iresults.value + 0xFF000000;  // Hack to Hex Integers
		ir.resume();
	}
	switch (button) {
		// First LED
		case Button11:
			setRGB1(1);
			break;
		case Button21:
			setRGB2(1);
			break;
		case Button31:
			setRGB3(1);
			break;
		case Button41:
			setRGB4(1);
			break;
		case Button51:
			setRGB5(1);
			break;
		case Button61:
			setRGB6(1);
			break;
		case Button71:
			setRGB7(1);
			break;
		case Button12:
			setRGB0(1);
			break;

		// Second LED
		case Button13:
			setRGB1(2);
			break;
		case Button23:
			setRGB2(2);
			break;
		case Button33:
			setRGB3(2);
			break;
		case Button43:
			setRGB4(2);
			break;
		case Button53:
			setRGB5(2);
			break;
		case Button63:
			setRGB6(2);
			break;
		case Button73:
			setRGB7(2);
			break;
		case Button72:
			setRGB0(2);
			break;
	}
}

// Conrolling RGB LEDs via analogWrite & PWM
void setRGB(int r, int g, int b, int led) {
	if (led == 1) {
		analogWrite(LED1_RED, r);
		analogWrite(LED1_GREEN, g);
		analogWrite(LED1_BLUE, b);
	}
	if (led == 2) {
		analogWrite(LED2_RED, r);
		analogWrite(LED2_GREEN, g);
		analogWrite(LED2_BLUE, b);
	}
	delay(1000);
}

// Seven Color Rainbow on One LED
void setRGB0(int led) {
	// Set Starting Color BLACK-rgb(0,0,0)
	if (led == 1) {
		setRGB(0, 0, 0, 1);
	}
	if (led == 2) {
		setRGB(0, 0, 0, 2);
	}
}
void setRGB1(int led) {
	// Set Starting Color RED-rgb(255,0,0)
	if (led == 1) {
		setRGB(255, 0, 0, 1);
	}
	if (led == 2) {
		setRGB(255, 0, 0, 2);
	}
}
void setRGB2(int led) {
	// Set Starting Color ORANGE-rgb(255, 125, 0)
	if (led == 1) {
		setRGB(255, 125, 0, 1);
	}
	if (led == 2) {
		setRGB(255, 125, 0, 2);
	}
}
void setRGB3(int led) {
	// Set Starting Color YELLOW-rgb(255, 255, 0)
	if (led == 1) {
		setRGB(255, 255, 0, 1);
	}
	if (led == 2) {
		setRGB(255, 255, 0, 2);
	}
}
void setRGB4(int led) {
	// Set Starting Color GREEN-rgb(0,255,0)
	if (led == 1) {
		setRGB(0, 255, 0, 1);
	}
	if (led == 2) {
		setRGB(0, 255, 0, 2);
	}
}
void setRGB5(int led) {
	// Set Starting Color BLUE-rgb(0,255,255)
	if (led == 1) {
		setRGB(0, 255, 255, 1);
	}
	if (led == 2) {
		setRGB(0, 255, 255, 2);
	}
}
void setRGB6(int led) {
	// Set Starting Color INDIGO-rgb(0,0,255)
	if (led == 1) {
		setRGB(0, 0, 255, 1);
	}
	if (led == 2) {
		setRGB(0, 0, 255, 2);
	}
}
void setRGB7(int led) {
	// Set Starting Color VIOLET-rgb(255,0,255)
	if (led == 1) {
		setRGB(255, 0, 255, 1);
	}
	if (led == 2) {
		setRGB(255, 0, 255, 2);
	}
}
