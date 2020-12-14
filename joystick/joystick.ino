// Digital Out Numbers to Joystick
const int JOYSTICK_GND = A0;
const int JOYSTICK_5V = A1;
const int JOYSTICK_VRX = A2;
const int JOYSTICK_VRY = A3;
const int JOYSTICK_SW = A4;

// Digital Out Numbers to LEDs
const int LED_UP = 3;
const int LED_DOWN = 52;
const int LED_RIGHT = 8;
const int LED_LEFT = 53;

void setup() {
	// Set Joystick Pins to Output Mode
	pinMode(JOYSTICK_GND, OUTPUT);
	pinMode(JOYSTICK_5V, OUTPUT);
	pinMode(JOYSTICK_VRX, INPUT);
	pinMode(JOYSTICK_VRY, INPUT);
	pinMode(JOYSTICK_SW, INPUT);

	// Set LED Pins to Output Mode
	pinMode(LED_UP, OUTPUT);
	pinMode(LED_DOWN, OUTPUT);
	pinMode(LED_RIGHT, OUTPUT);
	pinMode(LED_LEFT, OUTPUT);

	// DEBUG on Board
	Serial.begin(9600);
}

void loop() {
	// Set Power Supply
	digitalWrite(JOYSTICK_GND, LOW);
	digitalWrite(JOYSTICK_5V, HIGH);

	Serial.print("X = ");
	Serial.println(analogRead(JOYSTICK_VRX));
	Serial.print("Y = ");
	Serial.println(analogRead(JOYSTICK_VRY));

	// Light All LEDs with Joystick Button
	if (digitalRead(JOYSTICK_SW) == HIGH) {
		digitalWrite(LED_RIGHT, HIGH);
		digitalWrite(LED_LEFT, HIGH);
		digitalWrite(LED_UP, HIGH);
		digitalWrite(LED_DOWN, HIGH);
		Serial.println("CLICK");

	} else {
		digitalWrite(LED_RIGHT, LOW);
		digitalWrite(LED_LEFT, LOW);
		digitalWrite(LED_UP, LOW);
		digitalWrite(LED_DOWN, LOW);
	}

	// Light LED with Joystick Moving
	if (analogRead(JOYSTICK_VRX) > 800) {
		digitalWrite(LED_RIGHT, HIGH);

	} else {
		digitalWrite(LED_RIGHT, LOW);
	}
	if (analogRead(JOYSTICK_VRX) < 200) {
		digitalWrite(LED_LEFT, HIGH);

	} else {
		digitalWrite(LED_LEFT, LOW);
	}
	if (analogRead(JOYSTICK_VRY) < 200) {
		digitalWrite(LED_UP, HIGH);

	} else {
		digitalWrite(LED_UP, LOW);
	}
	if (analogRead(JOYSTICK_VRY) > 800) {
		digitalWrite(LED_DOWN, HIGH);

	} else {
		digitalWrite(LED_DOWN, LOW);
	}

}
