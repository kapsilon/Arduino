// Analog Out TermoResister
const int TERM_PIN = 11;
const int TERM_5V = 12;
const int TERM_GND = 13;
// TermoResister Variables
float temperature;
float humidity;
// Library for Temperature Module DHT
#include <DHT.h>
DHT dht(TERM_PIN, DHT11);

// Digital Out to Battery Module
const int BATTERY_VCC = 53;
const int BATTERY_GND = 51;
const int BATTERY_CLK = 49;
const int BATTERY_DAT = 47;
const int BATTERY_RST = 45;
// Include Library for Battery Clock DS1302
#include <Wire.h>
#include <iarduino_RTC.h>
// Initialization of DS1302
iarduino_RTC rtc(RTC_DS1302, BATTERY_RST, BATTERY_CLK, BATTERY_DAT);
// Set Current Date and Time
const char* strM = "JanFebMarAprMayJunJulAugSepOctNovDec";
const char* sysT = __TIME__;
const char* sysD = __DATE__;
// Convert Current Date and Time to Variables
const int sysSeconds = (sysT[6] - 48) * 10 + (sysT[7] - 48);
const int sysMinutes = (sysT[3] - 48) * 10 + (sysT[4] - 48);
const int sysHours = (sysT[0] - 48) * 10 + (sysT[1] - 48);
const int sysDay = (sysD[4] - 48) * 10 + (sysD[5] - 48);
const int sysMonth = ((int)memmem(strM, 36, sysD, 3) + 3 - (int)&strM[0]) / 3;
const int sysYear = (sysD[9] - 48) * 10 + (sysD[10] - 48);
// Set Variables for Time
char* timeDisplay;

// Digital Out Numbers to LCD Screen
const int I2C_GND = 18;
const int I2C_V5 = 19;
const int I2C_SDA = 20;
const int I2C_SCL = 21;
// Libraries for LCD
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
// Set LCD Screen's number of I2C Channel, Columns and Rows
LiquidCrystal_I2C lcd(0x27, 16, 2);
// Counter for Millis
int count = 0;

void setup() {
	// Set TermoResister Pins to Output/Input
	pinMode(TERM_GND, OUTPUT);
	pinMode(TERM_PIN, INPUT);
	pinMode(TERM_5V, OUTPUT);
	// Set TermoResister Power Supply
	digitalWrite(TERM_GND, LOW);
	digitalWrite(TERM_5V, HIGH);
	// Start Module DHT
	dht.begin();

	// Set Battery Clock Pins to Output Mode
	pinMode(BATTERY_VCC, OUTPUT);
	pinMode(BATTERY_GND, OUTPUT);
	// Set Battery Clock Power Supply
	digitalWrite(BATTERY_VCC, HIGH);
	digitalWrite(BATTERY_GND, LOW);
	// Set Clock to Run
	rtc.begin();
	// Set Current Time and Date
	if (rtc.Hours != sysHours || rtc.minutes != sysMinutes) {
		rtc.settime(sysSeconds, sysMinutes, sysHours, sysDay, sysMonth,	sysYear);
	}

	// Set LCD Pins to Output Mode
	pinMode(I2C_V5, OUTPUT);
	pinMode(I2C_GND, OUTPUT);
	// Set LCD Power Supply
	digitalWrite(I2C_V5, HIGH);
	digitalWrite(I2C_GND, LOW);
	// Start LCD Screen
	lcd.init();
	lcd.backlight();
}

void loop() {
	// Get TermoResister Readings
	temperature = dht.readTemperature();
	humidity = dht.readHumidity();

	// Print Readings on LCD Screen
	if (millis() % 1000 == 0) {
		if (count < 7) {
			// Print Temperature For 4 Seconds
			lcd.setCursor(0, 0);
			lcd.print("Temperature");
			lcd.setCursor(0, 1);
			lcd.print(String(temperature) + "C");
			lcd.setCursor(8, 1);
			lcd.print(rtc.gettime("H:i:s"));
		} else if (count < 10) {
			// Print Humidity Every 5 Seconds
			lcd.setCursor(0, 0);
			lcd.print("Humidity   ");
			lcd.setCursor(0, 1);
			lcd.print(String(humidity) + "% ");
			lcd.setCursor(8, 1);
			lcd.print(rtc.gettime("d-m-y"));
		} else {
			count = 0;
		}
		count += 1;
		// lcd.print(screenFirstLine);
		// lcd.print(screenFirstLine);
	}
}
