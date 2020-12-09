// Water Sensor Level Variable
int waterLevel;
// Digital Out Numbers to RGB Led
const int RED_PIN = 13;
const int GREEN_PIN = 12;
const int BLUE_PIN = 11;

void setup() {
	// Set Analog In to Water Sensor
	pinMode(A0, INPUT);
	// Set Led Pins to Output Mode
	pinMode(RED_PIN, OUTPUT);
	pinMode(GREEN_PIN, OUTPUT);
	pinMode(BLUE_PIN, OUTPUT);
	// Set Starting Color to BLACK
	setRGB(0, 0, 0);
	// DEBUG on Board
	Serial.begin(9600);
}

void loop() {
	// Get Water Sensor Data
	waterLevel = analogRead(A0);

	// DEBUG on Board, set 9600 at Serial Monitor
	Serial.println(waterLevel);

	// Set RGB Led: BLUE for little water (<500), INDIGO for big water (>500)
	if (waterLevel == 0) {
		setRGB(0, 0, 0);
	}
	if (0 < waterLevel && waterLevel < 500) {
		setRGB(0, 255, 255);
	}
	if (waterLevel >= 500) {
		setRGB(0, 0, 255);
	}

	delay(1000);
}

// Conrolling RGB Led via analogWrite & PWM
void setRGB(int r, int g, int b) {
	analogWrite(RED_PIN, r);
	analogWrite(GREEN_PIN, g);
	analogWrite(BLUE_PIN, b);
	delay(900);
}
