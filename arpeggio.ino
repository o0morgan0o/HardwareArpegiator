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

#define ARPEGGIO_LENGTH 5
const int buttonPin = 2;
const int potPin = 2;
const int potNoteLength = 4;
int buttonState = 0;
volatile byte restart = LOW;

int noteON = 144;  //144 = 10010000 in binary, note on command
int noteOFF = 128; //128 = 10000000 in binary, note off command
int velocity = 100;

const int MIDILow = 0;
const int MIDIHigh = 200;

int bpm = 60;
float notesPerBeat = 2;
int noteDuration = 100; // in ms

float delayBetweenNotes = 60000 / bpm / notesPerBeat;

int myMIDInote = 30;
int arpeggio[ARPEGGIO_LENGTH] = {myMIDInote + 0, myMIDInote + 3, myMIDInote + 5, myMIDInote + 8, myMIDInote + 12};
int currentStep = 0;
int currentStepOff = 0;

unsigned long previousMillis = 0;
long interval = delayBetweenNotes;
// unsigned long previousMillisOff = noteDuration;
long previousMillisOff = noteDuration;
float val = 0;

void setup()
{
  // Set MIDI baud rate:
  Serial.begin(31250);
  // Serial1.begin(115200);
  pinMode(buttonPin, INPUT);

  attachInterrupt(digitalPinToInterrupt(buttonPin), checkRestart, RISING);
}

void detectNotePressed()
{
  if (digitalRead(buttonPin) == HIGH)
  {
    // myMIDInote = 0x1E; //note C detectee par exempl
  }
  else
  {
  }
}

void loop()
{
  recalcValues();

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
    MIDImessage(noteON, arpeggio[currentStep], velocity);
  }

  // if (millis() - previousMillisOff >= interval + firstTimeDelay)
  if ((long)millis() - previousMillisOff >= interval)
  {
    previousMillisOff = millis();
    if (currentStepOff >= ARPEGGIO_LENGTH - 1)
    {
      currentStepOff = 0;
    }
    else
    {
      currentStepOff++;
    }
    MIDImessage(noteOFF, arpeggio[currentStepOff], velocity);
  }
}

void MIDImessage(int command, int MIDInote, int MIDIvelocity)
{
  Serial.write(command);      //send note on or note off command
  Serial.write(MIDInote);     //send pitch data
  Serial.write(MIDIvelocity); //send velocity data
}

void checkRestart()
{

  myMIDInote = (int)random(20, 50);
  int newArpeggio[ARPEGGIO_LENGTH] = {myMIDInote + 1, myMIDInote + 3, myMIDInote + 5, myMIDInote + 8, myMIDInote + 12};
  for (int i = 0; i < ARPEGGIO_LENGTH; i++)
  {
    MIDImessage(noteOFF, arpeggio[i], velocity);
    arpeggio[i] = newArpeggio[i];
  }
}
void recalcValues()
{
  //recalc with new bpm
  //peut etre un soucis avec la note duration a cause du premier delay

  int newBpm = map(analogRead(potPin), 0, 1023, 280, 30); //bpm mappe de 30 a 280
  bpm = newBpm;
  delayBetweenNotes = 60000 / bpm / notesPerBeat;
  interval = delayBetweenNotes;

  // noteDuration = map(analogRead(potPin), 0, 1023, 400, 800);
  // noteDuration = 500;
  // previousMillisOff = noteDuration;
  // firstTimeDelay = noteDuration;
}