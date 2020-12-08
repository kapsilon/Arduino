// Digital Out Numbers to RGB Led
const int RED_PIN = 13;
const int GREEN_PIN = 12;
const int BLUE_PIN = 11;

void setup() {
	// Set Pins to Output Mode
	pinMode(RED_PIN, OUTPUT);
	pinMode(GREEN_PIN, OUTPUT);
	pinMode(BLUE_PIN, OUTPUT);
	// Set Starting Color to BLACK
	setRGB(0, 0, 0);
}

// Seven Color Rainbow on One Led
void loop() {
// Set Color to RED
	setRGB(255, 0, 0);
	setRGB(0, 0, 0);
	// Set Color to ORANG
	setRGB(255, 125, 0);
	setRGB(0, 0, 0);
	// Set Color to YELLOW
	setRGB(255, 255, 0);
	setRGB(0, 0, 0);
	// Set Color to GREEN
	setRGB(0, 255, 0);
	setRGB(0, 0, 0);
	// Set Color to BLUE
	setRGB(0, 255, 255);
	setRGB(0, 0, 0);
	// Set Color to INDIGO
	setRGB(0, 0, 255);
	setRGB(0, 0, 0);
	// Set Color to VIOLET
	setRGB(255, 0, 255);
	setRGB(0, 0, 0);
}

// Conrolling RGB Led via analogWrite & PWM
void setRGB(int r, int g, int b) {
	analogWrite(RED_PIN, r);
	analogWrite(GREEN_PIN, g);
	analogWrite(BLUE_PIN, b);
	delay(1000);  // ms
}
