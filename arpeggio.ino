#define ARPEGGIO_LENGTH 5
#define ARPEGGIO_MAX_LENGTH 12
#define BUFFER_LENGTH 20
#include "MorganMidi.h"
#include <LiquidCrystal.h>
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

boolean isRecording = false;
boolean noteButtonIsReleased = true; //permet d'eviter les doubles entrees
int bufferPlace = 0;

// POTENTIOMETRES -----------------
const int potBpm = 0; //Potard BPM
const int potDuration = 1;
const int longerNotes = 2;
//PIN *****************************
const int noteInputs[12] = {24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46}; //valeur des pins des touches du clavier
const int recPin = 30;
const int ledButtonsReleased = 23;

// const int noteC = 2, noteD = 3, noteE = 4, noteF = 5, noteG = 6;
int middleC = 44; // valeur de reference de Do
// const int shorterNotes = 23;
//**********************************

int noteON = 144;  //144 = 10010000 in binary, note on command
int noteOFF = 128; //128 = 10000000 in binary, note off command
int velocity = 100;

const int MIDILow = 0;
const int MIDIHigh = 200;

int bpm = 60;
int previousBpm = 60;
float notesPerBeat = 2;
long noteDuration = 100; // in ms

float delayBetweenNotes = 60000 / bpm / notesPerBeat;
boolean arpeggioChangeAsked = false;

boolean tapTempoButtonPushed = false;
int tapTempoCounter = 0;
boolean enoughValuesTapTempo = false;

long tapTempoBuffer[2];
int myMIDInote = middleC;
// int arpeggio[ARPEGGIO_LENGTH] = {myMIDInote, myMIDInote, myMIDInote + 0, myMIDInote + 5, myMIDInote + 5};
int arpeggio[ARPEGGIO_LENGTH] = {myMIDInote + 0, myMIDInote + 3, myMIDInote + 7, myMIDInote + 3, myMIDInote + 0};
// int arpeggio[ARPEGGIO_LENGTH] = {myMIDInote + 0, myMIDInote + 3, myMIDInote + 5, myMIDInote + 8, myMIDInote + 12};
int bufferArpeggio[ARPEGGIO_LENGTH];

int bufferStep = 0;
int bufferCC[BUFFER_LENGTH];
long bufferTimes[BUFFER_LENGTH];
long bufferOffTimes[BUFFER_LENGTH];

int currentStep = 0;
int bufferCurrentStep = 0;
// int currentStepOff = 0;

unsigned long previousMillis = 0;
long interval = delayBetweenNotes;
long previousMillisOff = noteDuration;

int buttonState = LOW;
int previousState = LOW;
int major[3] = {0, 4, 7};
int minor[3] = {0, 3, 7};
int dim[3] = {0, 3, 6};
int aug[3] = {0, 4, 8};

int arpTypeButton1 = 48;
int arpTypeButton2 = 50;
int arpTypeButton3 = 52;

void setup()
{
  Serial.begin(31250);
  // for (int i = 0; i < 10; i++)
  // {
  // pinMode(noteInputs[i], INPUT); //pas sure que ca marche
  // }
  pinMode(22, OUTPUT);
  pinMode(43, OUTPUT); //test pour illumination button
  pinMode(ledButtonsReleased, OUTPUT);
  pinMode(recPin, INPUT); //pas sure que ca marche
  pinMode(51, INPUT);

  //----------------- Buttons arpege --------------//
  pinMode(arpTypeButton1, INPUT);
  pinMode(arpTypeButton2, INPUT);
  pinMode(arpTypeButton3, INPUT);
  //-----------------  --------------//

  //------------------Buttons notes -----------------//
  for (int i = 0; i < 12; i++)
  {
    // pinMode(noteInputs[i], INPUT_PULLUP);
    // digitalWrite(noteInputs[i], HIGH);
  }
  pinMode(24, INPUT_PULLUP);
  pinMode(26, INPUT_PULLUP);
  pinMode(28, INPUT_PULLUP);
  pinMode(30, INPUT_PULLUP);
  pinMode(32, INPUT_PULLUP);
  pinMode(34, INPUT_PULLUP);
  pinMode(36, INPUT_PULLUP);
  pinMode(38, INPUT_PULLUP);
  pinMode(40, INPUT_PULLUP);
  pinMode(42, INPUT_PULLUP);
  pinMode(44, INPUT_PULLUP);
  pinMode(46, INPUT_PULLUP);
  digitalWrite(24, HIGH);
  digitalWrite(26, HIGH);
  digitalWrite(28, HIGH);
  digitalWrite(30, HIGH);
  digitalWrite(32, HIGH);
  digitalWrite(34, HIGH);
  digitalWrite(36, HIGH);
  digitalWrite(40, HIGH);
  digitalWrite(42, HIGH);
  digitalWrite(44, HIGH);
  digitalWrite(46, HIGH);
  // pinMode(29, INPUT_PULLUP);
  // digitalWrite(29, HIGH);
  // pinMode(35, INPUT_PULLUP);
  // digitalWrite(35, HIGH);

  //------------------ -----------------//
  //test
  // pinMode(29, INPUT_PULLUP); //permet de pas avoir de resistance
  // digitalWrite(29, HIGH);

  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("beginning");
}
