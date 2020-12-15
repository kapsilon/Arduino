// Digital Out Number to Distance Meter
const int DISTANCE_5V = 41;
const int DISTANCE_TRIG = 39;
const int DISTANCE_ECHO = 37;
const int DISTANCE_GND = 35;

//// Include Library for Distance Meter HC-SR04
#include <HCSR04.h>
// Set Distance Meter On
UltraSonicDistanceSensor distanceSensor(DISTANCE_TRIG, DISTANCE_ECHO);

void setup() {
	// Set Pins to Output Mode
	pinMode(DISTANCE_5V, OUTPUT);
	pinMode(DISTANCE_GND, OUTPUT);
	pinMode(DISTANCE_TRIG, OUTPUT);
	pinMode(DISTANCE_ECHO, INPUT);

	// DEBUG on Board
	Serial.begin(9600);
}

void loop() {
	// Set Power Supply for Distance Meter
	digitalWrite(DISTANCE_5V, HIGH);
	digitalWrite(DISTANCE_GND, LOW);

	// Measuring Distance in cantimeters
	double distance = distanceSensor.measureDistanceCm();

	// Distance out to Serial
	Serial.print(distance);
	Serial.println(" cm");

	delay(1000);
}
