// Digital Out Numbers to RGB Led
const int RED_PIN = 13;
const int GREEN_PIN = 12;
const int BLUE_PIN = 11;

// Color Variable in RGB
int red;
int green;
int blue;

void setup() {
	// Set Pins to Output Mode
	pinMode(RED_PIN, OUTPUT);
	pinMode(GREEN_PIN, OUTPUT);
	pinMode(BLUE_PIN, OUTPUT);
	// Set Starting Color BLACK-rgb(0,0,0)
	setRGB(0, 0, 0);
	delay(1000);
	// DEBUG on Board
	Serial.begin(9600);
}

// Seven Color Rainbow on One Led
void loop() {
	// Set RED-rgb(255,0,0)
	red = 255;
	green = 0;
	blue = 0;
	setRGB(red, green, blue);

	// Go from RED-rgb(255,0,0) to ORANGE-rgb(255,125,0)
	for (green = 0; green <= 125; green++) {
		setRGB(red, green, blue);
	}

	// DEBUG on Board, set 9600 at Serial Monitor
	Serial.println(red);
	Serial.println(green);
	Serial.println(blue);
	Serial.println("ORANGE");

	// Go from ORANGE - rgb(255, 125, 0) to YELLOW-rgb(255, 255, 0)
	for (green = 126; green < 255; green++) {
		setRGB(red, green, blue);
	}

	// Go from YELLOW-rgb(255,255,0) to GREEN-rgb(0,255,0)
	for (red = 255; red > 0; red--) {
		setRGB(red, green, blue);
	}

	// Go from GREEN-rgb(0,255,0) to BLUE-rgb(0,255,255)
	for (blue = 0; blue < 255; blue++) {
		setRGB(red, green, blue);
	}

	// Go from BLUE-rgb(0,255,255) to INDIGO-rgb(0,0,255)
	for (green = 255; green > 0; green--) {
		setRGB(red, green, blue);
	}

	// Go from INDIGO-rgb(0,0,255) to VIOLET-rgb(255,0,255)
	for (red = 0; red < 255; red++) {
		setRGB(red, green, blue);
	}

	// Go from INDIGO-rgb(255,0,255) to RED-rgb(255,0,0)
	for (blue = 255; blue >= 0; blue--) {
		setRGB(red, green, blue);
	}
}

// Conrolling RGB Led via analogWrite & PWM
void setRGB(int r, int g, int b) {
	analogWrite(RED_PIN, r);
	analogWrite(GREEN_PIN, g);
	analogWrite(BLUE_PIN, b);
	delay(20);	// ms
}
