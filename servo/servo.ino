// Digital Out Number to Micro Servo Drive SG90
const int SERVO_PIN = 37;

// Include Library for Temperature Module DHT
#include <Servo.h>
Servo servo;

void setup() {
	// Set Display Pins
	pinMode(SERVO_PIN, INPUT);

	// Set ServoDrive to 0-Position
	servo.attach(SERVO_PIN);
	servo.write(0);
}

void loop() {
	// Cycling
	servo.write(45);
	delay(1000);
	servo.write(90);
	delay(1000);
	servo.write(135);
	delay(1000);
	servo.write(90);
	delay(1000);
	servo.write(135);
	delay(1000);
	servo.write(90);
	delay(1000);
	servo.write(135);
	delay(1000);
	servo.write(180);
	delay(1000);
	servo.write(0);
	delay(1000);
}
