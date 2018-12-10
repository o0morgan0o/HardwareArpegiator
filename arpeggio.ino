/*
  MIDI note player

  This sketch shows how to use the serial transmit pin (pin 1) to send MIDI note data.
  If this circuit is connected to a MIDI synth, it will play the notes
  F#-0 (0x1E) to F#-5 (0x5A) in sequence.

  The circuit:
  - digital in 1 connected to MIDI jack pin 5
  - MIDI jack pin 2 connected to ground
  - MIDI jack pin 4 connected to +5V through 220 ohm resistor
  - Attach a MIDI cable to the jack, then to a MIDI synth, and play music.

  created 13 Jun 2006
  modified 13 Aug 2012
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Midi
  voir ca pour brancher un interrupteur, pour en brancher plus, il faudra utiliser un signal analog avec differentes valeures 
  de resistance. 
  https://www.arduino.cc/en/tutorial/button
*/

//Je pense qu'il faut vraiment mieux  a chaque note ajouter une planification de note off dans une array
//si je branche plusieurs potentiometres, ils se perturbent etre eux.

#define ARPEGGIO_LENGTH 5
#define ARPEGGIO_MAX_LENGTH 12
#include "MorganMidi.h"
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte bufferCC[20];
long bufferTimes[20];
long bufferOffTimes[20];

// POTENTIOMETRES -----------------
const int potPin = 0; //Potard BPM
const int potDuration = 1;
const int longerNotes = 2;
// const int shorterNotes = 23;

int noteON = 144;  //144 = 10010000 in binary, note on command
int noteOFF = 128; //128 = 10000000 in binary, note off command
int velocity = 100;

const int MIDILow = 0;
const int MIDIHigh = 200;

int bpm = 60;
float notesPerBeat = 2;
long noteDuration = 100; // in ms

float delayBetweenNotes = 60000 / bpm / notesPerBeat;

int myMIDInote = 29;
int arpeggio[ARPEGGIO_LENGTH] = {myMIDInote + 0, myMIDInote + 3, myMIDInote + 5, myMIDInote + 8, myMIDInote + 12};
int currentStep = 0;
int currentStepOff = 0;

unsigned long previousMillis = 0;
long interval = delayBetweenNotes;
long previousMillisOff = noteDuration;

int buttonState = LOW;
int previousState = LOW;
int major[3] = {0, 4, 7};
int minor[3] = {0, 3, 7};
int dim[3] = {0, 3, 6};
int aug[3] = {0, 4, 8};

void setup()
{
  Serial.begin(31250);
  // pinMode(buttonPin, INPUT);
  pinMode(longerNotes, INPUT);
  // pinMode(shorterNotes, INPUT);
  lcd.begin(16, 2);
  lcd.clear();
  // attachInterrupt(digitalPinToInterrupt(buttonPin), checkRestart, RISING);
  // attachInterrupt(digitalPinToInterrupt(longerNotes), longNotes, CHANGE);
  // attachInterrupt(digitalPinToInterrupt(shorterNotes), shortNotes, CHANGE);
}

void loop()
{

  updateDisplay();

  // noteDuration = map(analogRead(potNoteLength), 0, 1032, 1200, 20);
  // if (digitalRead(longerNotes) == LOW)
  // {
  //   bpm = 200;
  //   delayBetweenNotes = 60000 / bpm / notesPerBeat;
  //   interval = delayBetweenNotes;
  // }

  buttonState = digitalRead(longerNotes);
  // buttonState = LOW;
  if (buttonState == HIGH && previousState == LOW)
  {

    previousState = HIGH;
    changeArpgeggio((int)random(30, 50));
  }
  else if (buttonState == LOW)
  {
    previousState = LOW;
  }

  if (millis() - previousMillis >= interval)
  {
    previousMillis = millis();
    if (currentStep >= ARPEGGIO_LENGTH - 1)
    {
      currentStep = 0;
    }
    else
    {
      currentStep++;
    }

    bufferCC[currentStep] = arpeggio[currentStep];
    bufferTimes[currentStep] = millis();
    bufferOffTimes[currentStep] = noteDuration;
    MIDImessage(noteON, bufferCC[currentStep], velocity);
  }

  for (int k = 0; k < ARPEGGIO_LENGTH; k++)
  {

    if (millis() > bufferTimes[k] + bufferOffTimes[k])
    {
      MIDImessage(noteOFF, bufferCC[k], velocity);
      bufferTimes[k] = 0;
    }
  }
}
