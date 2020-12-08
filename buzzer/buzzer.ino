// Digital Out Number to Buzzer
const int SPEAKER_PIN = 11;

void setup() {
	// Set Pin to Output Mode
	pinMode(SPEAKER_PIN, OUTPUT);
}

void loop() {
	// Make sound at 1000 Hz for 500 ms
	tone(SPEAKER_PIN, 1000, 500);
	delay(1000);

	// Repeat with different Hz
	tone(SPEAKER_PIN, 2000, 500);
	delay(1000);
	tone(SPEAKER_PIN, 3000, 500);
	delay(1000);
	tone(SPEAKER_PIN, 4000, 500);
	delay(1000);
	tone(SPEAKER_PIN, 5000, 500);
	delay(1000);
}
