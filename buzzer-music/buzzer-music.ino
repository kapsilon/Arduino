// Digital Out Number to Buzzer
const int SPEAKER_PIN = 11;

//// Include Library for Music Notes
#include "pitches.h"

void setup() {
	// Set Pin to Output Mode
	pinMode(SPEAKER_PIN, OUTPUT);
}

void loop() {
	// Melody: Notes and Their Durations
	int notes[] = {NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5,
				   NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6};
	int notesDuration[] = {4, 8, 8, 4,
						   4, 4, 4, 4};	 // 4 = quarter note, 8 = eighth note
	// Playing This Melody
	playMelody(notes, notesDuration, 8);

	// IMPERIAL MARCH
	int notes1[] = {NOTE_A4, NOTE_A4, NOTE_A4, NOTE_F4, NOTE_C5};
	int notesDuration1[] = {2, 2, 2, 2, 8};
	playMelody(notes, notesDuration, 5);
	int notes2[] = {NOTE_A4, NOTE_F4, NOTE_C5, NOTE_A4};
	int notesDuratio2[] = {2, 2, 8, 1};
	playMelody(notes, notesDuration, 4);
	int notes3[] = {NOTE_E5, NOTE_E5, NOTE_E5, NOTE_F5, NOTE_C5};
	int notesDuration3[] = {2, 2, 2, 2, 8};
	playMelody(notes, notesDuration, 5);
	int notes4[] = {NOTE_GS4, NOTE_F4, NOTE_C5, NOTE_A4};
	int notesDuration4[] = {2, 2, 8, 1};
	playMelody(notes, notesDuration, 4);
	int notes5[] = {NOTE_A5, NOTE_A4, NOTE_A4, NOTE_A5, NOTE_GS5, NOTE_G5};
	int notesDuration5[] = {2, 2, 8, 2, 4, 4};
	playMelody(notes, notesDuration, 6);
	int notes6[] = {NOTE_FS5, NOTE_F5, NOTE_FS5, NOTE_AS4, NOTE_DS5, NOTE_D5, NOTE_CS5};
	int notesDuration6[] = {8, 8, 4, 4, 2, 4, 4};
	playMelody(notes, notesDuration, 7);
	int notes7[] = {NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_F4, NOTE_GS4, NOTE_F4,  NOTE_A4};
	int notesDuration7[] = {8, 8, 4, 8, 2, 2, 8};
	playMelody(notes, notesDuration, 7);
	int notes8[] = {NOTE_C5, NOTE_A4, NOTE_C5, NOTE_E5};
	int notesDuration8[] = {2, 2, 8, 1};
	playMelody(notes, notesDuration, 4);
	int notes9[] = {NOTE_A5, NOTE_A4, NOTE_A4, NOTE_A5, NOTE_GS5, NOTE_G5};
	int notesDuration9[] = {2, 2, 8, 2, 4, 4};
	playMelody(notes, notesDuration, 6);
	int notes10[] = {NOTE_FS5, NOTE_F5, NOTE_FS5, NOTE_AS4, NOTE_DS5, NOTE_D5, NOTE_CS5};
	int notesDuration10[] = {8, 8, 4, 4, 2, 4, 4};
	playMelody(notes, notesDuration, 7);
	int notes11[] = {NOTE_C5,	 NOTE_AS4, NOTE_C5, NOTE_F4, NOTE_GS4, NOTE_F4,  NOTE_C5};
	int notesDuration11[] = {8, 8, 4, 8, 2, 2, 8};
	playMelody(notes, notesDuration, 7);
	int notes12[] = {NOTE_A4, NOTE_F4, NOTE_C4, NOTE_A4};
	int notesDuration12[] = {2, 2, 8, 1};
	playMelody(notes, notesDuration, 4);

	delay(5000);
}

// Play Melody with Arrays of Notes and Their Durations
void playMelody(int notes[], int notesDuration[], int size) {
	for (int note = 0; note < size; note++) {
		// Calculate One Note Duration
		int noteDuration = 1000 / notesDuration[note];
		// Play One Note
		tone(SPEAKER_PIN, notes[note], noteDuration);
		// Minimal Pause Between Notes
		delay(noteDuration * 1.3);
	}
	noTone(SPEAKER_PIN);
}

