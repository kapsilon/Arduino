// Use These AT-commands at Serial Monitor with "115200 baud" and "Both NL & CR"

// GET VIA ESP8266 VIA ARDUINO (RX_PIN = 16; TX_PIN = 17;)
// AT+CIPMUX=0 - set multiple connection mode
// AT+CIPSTART="TCP","site.com",80 - start tcp connection with server site.com, port 80
// AT+CIPCLOSE - close connection ID=1
// AT+CIPSTATUS - status of connection

// MULTIPLE CONNECTIONS (1-4)
// AT+CIPMUX=1 - set multiple connection mode
// AT+CIPSTART=1,"TCP","site.com",80 - start tcp connection ID=1 with server site.com, port 80
// AT+CIPCLOSE=1 - close connection ID=1
// AT+CIPSTATUS - status of connections

// GET TO SERVER (ONLY HTTP & DON'T USE "/r/n" NEW LINE SYMBOL AFTER AT+CIPSEND)
// AT+CIPSTART="TCP","xxxx.yyyyyyyy.zz",80
// AT+CIPSEND=86
// GET /arduino/test.txt HTTP/1.1
// Host: xxxx.yyyyyyyy.zz
// User-Agent: ArduinoESP

// One Time Runner
bool START = true;

void setup() {
	// Open Main Serial Port Monitor
	Serial.begin(115200);
	while (!Serial) {
	}
	Serial.println("Serial OK");

	// Open ESP8266 Serial Port Monitor
	Serial2.begin(115200);
	while (!Serial2) {
	}
	Serial.println("WiFi OK\r\n");

	// Waiting
	delay(1000);
}

void loop() {
	// Print Data on Arduino from WiFi-Receiver (ESP8266)
	if (Serial2.available() > 0) {
		int inByte = Serial2.read();
		Serial.write(inByte);
	}

	// Send data to WiFi-Receiver (ESP8266) from Arduino Serial Port
	if (Serial.available() > 0) {
		int inByte = Serial.read();
		Serial2.write(inByte);
	}

	// Get file http://xxxxxxxx.yy/arduino/test.txt from server
	while (START) {
		Serial2.println("AT+CIPSTART=\"TCP\",\"xxxxxxxx.yy\",80");
		delay(500);
		Serial2.println("AT+CIPSEND=55");
		delay(500);
		Serial2.println("GET /arduino/test.txt HTTP/1.1");
		delay(500);
		Serial2.println("Host: xxxxxxxx.yy");
		delay(500);
		Serial2.println("");
		delay(500);
		Serial2.println("");
		delay(5000);
		Serial2.println("AT+CIPCLOSE");
		delay(500);
		START = false;
	}
}
