// Digital Out Number to Micro Servo Drive SG90
const int STEPPER_IN1 = 4;
const int STEPPER_IN2 = 5;
const int STEPPER_IN3 = 6;
const int STEPPER_IN4 = 7;

// Include Library for Temperature Module DHT
#include <Stepper.h>
const int stepsPerRevolution = 250;	 // Different for Different Motors
Stepper stepper(stepsPerRevolution, STEPPER_IN1, STEPPER_IN2, STEPPER_IN3, STEPPER_IN4);

void setup() {
	// Set Display Pins
	pinMode(STEPPER_IN1, OUTPUT);
	pinMode(STEPPER_IN1, OUTPUT);
	pinMode(STEPPER_IN1, OUTPUT);
	pinMode(STEPPER_IN1, OUTPUT);

	// set the speed at 60 rpm:
	stepper.setSpeed(100);
}

void loop() {
	stepper.step(stepsPerRevolution);
	delay(500);
}
