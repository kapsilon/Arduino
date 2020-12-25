// Digital Out Numbers to RGB LED
const int LED_GND = 8;
const int LED_V5 = 9;

// Digital Out Numbers to Sound Sensor
const int SOUND_ANALOG = A11;
const int SOUND_GND = 21;
const int SOUND_5V = 20;
const int SOUND_DIGITAL = 19;

void setup() {
	// Set LED Pins to Output Mode
	pinMode(LED_GND, OUTPUT);
	pinMode(LED_V5, OUTPUT);

	// Set Sound Sensor Pins to Input-Output Mode
	pinMode(SOUND_GND, OUTPUT);
	pinMode(SOUND_5V, OUTPUT);
	pinMode(SOUND_DIGITAL, INPUT);

	// DEBUG on Board
	Serial.begin(9600);
}

void loop() {
	// Power Supply of Sound Sensor
	digitalWrite(SOUND_5V, HIGH);
	digitalWrite(SOUND_GND, LOW);
	// Power Supply of LED
	digitalWrite(LED_GND, LOW);

	// Get Sound
	bool soundStatus = digitalRead(SOUND_DIGITAL);
	int soundVolume = analogRead(SOUND_ANALOG);

	// DEBUG on Board
	Serial.println(soundStatus);
	Serial.println(soundVolume);

	// LED On When There is Sound
	if (soundStatus) {
		digitalWrite(LED_V5, HIGH);
	} else {
		digitalWrite(LED_V5, LOW);
	}
}
