// Digital Out Numbers to RGB LED
const int LED_GND = 7;
const int LED_RED = 6;
const int LED_GREEN = 5;
const int LED_BLUE = 4;

// Digital Out Numbers to Motion Sensor HC-SR501
const int MOTION_GND = 10;
const int MOTION_PIN = 11;
const int MOTION_5V = 12;
int motion = 0;

void setup() {
	// Set LED Pins to Output Mode
	pinMode(LED_GND, OUTPUT);
	pinMode(LED_RED, OUTPUT);
	pinMode(LED_GREEN, OUTPUT);
	pinMode(LED_BLUE, OUTPUT);
	// Set Starting Color BLACK-rgb(0,0,0)
	setRGB(0, 0, 0);

	// Set Motion Sensor Pins to Input-Output Mode
	pinMode(MOTION_GND, OUTPUT);
	pinMode(MOTION_PIN, INPUT);
	pinMode(MOTION_5V, OUTPUT);
}

void loop() {
	// Power Supply of Motion Sensor
	digitalWrite(MOTION_5V, HIGH);
	digitalWrite(MOTION_GND, LOW);

	// Get Motion
	int motion = digitalRead(MOTION_PIN);

	// LED On When There is Motion
	if (motion) {
		setRGB(255, 0, 0);

	} else {
		setRGB(0, 0, 0);
	}
}

// Conrolling RGB Led via analogWrite & PWM
void setRGB(int r, int g, int b) {
	analogWrite(LED_RED, r);
	analogWrite(LED_GREEN, g);
	analogWrite(LED_BLUE, b);
	delay(1000);
}
