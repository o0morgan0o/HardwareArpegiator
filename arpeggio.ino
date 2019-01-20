#define ARPEGGIO_LENGTH 5
#define ARPEGGIO_MAX_LENGTH 12
#define BUFFER_LENGTH 20
#include "MorganMidi.h"
#include <LiquidCrystal.h>

//variables for screen **************
String debugStr = "";
String tempDisplayLine1 = "test";
String tempDisplayLine2 = "";
double tempDisplayTime = 0;
boolean tempDisplayActivate = false;
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//variables pour enregistrement
boolean isRecording = false;
boolean noteButtonIsReleased = true; //permet d'eviter les doubles entrees

int bufferPlace = 0;
int arpDirection = 0; //0 =ascendant, 1=descendant, 2=random

// POTENTIOMETRES -----------------
const int potBpm = 0; //Potard BPM
const int potDuration = 1;
const int longerNotes = 2;
//PIN *****************************
// const int noteInputs[12] = {24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46}; //valeur des pins des touches du clavier
const int recPin = 30;
// const int ledButtonsReleased = 23;

// const int noteC = 2, noteD = 3, noteE = 4, noteF = 5, noteG = 6;
String currentArp = "...";
int middleC = 44; // valeur de reference de Do
int actualMaj = 0;
int actualMin = 0;
int actualAlt = 0;
// const int shorterNotes = 23;
//**********************************
int pinCnote = 36;
int pinDbnote = 46;
int pinDnote = 34;
int pinEbnote = 44;
int pinEnote = 30;
int pinFnote = 32;
int pinGbnote = 42;
int pinGnote = 28;
int pinAbnote = 40;
int pinAnote = 26;
int pinBbnote = 38;
int pinBnote = 24;

int lightCnote = 41;
int lightDbnote = 51;
int lightDnote = 39;
int lightEbnote = 49;
int lightEnote = 37;
int lightFnote = 35;
int lightGbnote = 47;
int lightGnote = 33;
int lightAbnote = 45;
int lightAnote = 31;
int lightBbnote = 43;
int lightBnote = 29;

int btnOctaveMinus = 2;
int btnOctavePlus = 3;
int btnRed1 = 5;
int btnRed2 = 6;
int btnRed3 = 4;
int btnMaj = 25;
int btnMin = 23;
int btnAlt = 27;
int btnRec = 53;

int previousStateBtnMaj = HIGH;

int light1 = A7;
int light2 = A6;
int light3 = A5;
int light4 = A12;
int light5 = A10;
int light6 = A11;
int light7 = A15;
int light8 = A13;
int light9 = A14;

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
int arpeggioNotesOffset[ARPEGGIO_LENGTH] = {0, 3, 5, 7, 9}; //arpege de depart majeur
int arpeggio[ARPEGGIO_LENGTH] = {myMIDInote + arpeggioNotesOffset[0], myMIDInote + arpeggioNotesOffset[1], myMIDInote + arpeggioNotesOffset[2], myMIDInote + arpeggioNotesOffset[3], myMIDInote + arpeggioNotesOffset[4]};
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

  // pinMode(22, OUTPUT);
  // pinMode(23, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A6, OUTPUT);
  pinMode(A7, OUTPUT);
  pinMode(A8, OUTPUT);
  pinMode(A9, OUTPUT);
  pinMode(A10, OUTPUT);
  pinMode(A11, OUTPUT);
  pinMode(A12, OUTPUT);
  pinMode(A13, OUTPUT);
  pinMode(A14, OUTPUT);
  pinMode(A15, OUTPUT);

  //********************** Buttons light *********************//
  pinMode(22, OUTPUT); //test pour illumination button
  pinMode(29, OUTPUT); //test pour illumination button
  pinMode(31, OUTPUT); //test pour illumination button
  pinMode(33, OUTPUT); //test pour illumination button
  pinMode(35, OUTPUT); //test pour illumination button
  pinMode(37, OUTPUT); //test pour illumination button
  pinMode(39, OUTPUT); //test pour illumination button
  pinMode(41, OUTPUT); //test pour illumination button
  pinMode(43, OUTPUT); //test pour illumination button
  pinMode(45, OUTPUT); //test pour illumination button
  pinMode(47, OUTPUT); //test pour illumination button
  pinMode(49, OUTPUT); //test pour illumination button
  pinMode(51, OUTPUT); //test pour illumination button
  //*********************************************************

  // pinMode(53, OUTPUT); //test pour illumination button
  // pinMode(ledButtonsReleased, OUTPUT);
  // pinMode(recPin, INPUT); //pas sure que ca marche
  // pinMode(51, INPUT);

  //----------------- Buttons arpege --------------//
  pinMode(arpTypeButton1, INPUT);
  pinMode(arpTypeButton2, INPUT);
  pinMode(arpTypeButton3, INPUT);
  //-----------------  --------------//

  //------------------Buttons notes -----------------//
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

  //Bouton Rec **************
  pinMode(btnRec, INPUT_PULLUP);
  digitalWrite(btnRec, HIGH);
  //Bouttons function *************
  pinMode(btnOctaveMinus, INPUT_PULLUP);
  pinMode(btnOctavePlus, INPUT_PULLUP);
  pinMode(btnRed1, INPUT_PULLUP);
  pinMode(btnRed2, INPUT_PULLUP);
  pinMode(btnRed3, INPUT_PULLUP);
  pinMode(btnMaj, INPUT_PULLUP);
  pinMode(btnMin, INPUT_PULLUP);
  pinMode(btnAlt, INPUT_PULLUP);
  digitalWrite(btnOctaveMinus, HIGH);
  digitalWrite(btnOctavePlus, HIGH);
  digitalWrite(btnRed1, HIGH);
  digitalWrite(btnRed2, HIGH);
  digitalWrite(btnRed3, HIGH);
  digitalWrite(btnMaj, HIGH);
  digitalWrite(btnMin, HIGH);
  digitalWrite(btnAlt, HIGH);

  //pas sur
  pinMode(4, INPUT_PULLUP);
  digitalWrite(4, HIGH);

  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("beginning");
}
