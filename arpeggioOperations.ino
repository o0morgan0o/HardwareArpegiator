int arpeggioNotesOffset[ARPEGGIO_LENGTH] = {0, 0, 0, 0, 0}; //arpege de depart majeur
void MIDImessage(int command, int MIDInote, int MIDIvelocity)
{
  Serial.write(command);      //send note on or note off command
  Serial.write(MIDInote);     //send pitch data
  Serial.write(MIDIvelocity); //send velocity data
}

void changeArpeggio(int midiNote)

{
  for (int i = 0; i < ARPEGGIO_LENGTH; i++)
  {
    arpeggio[i] = midiNote + arpeggioNotesOffset[i];
  }
  myMIDInote = midiNote;
}

void recalcValues()
{

  int newBpm = map(analogRead(potBpm), 0, 1023, 60, 180); //bpm mappe de 30 a 280
  if (abs(newBpm - previousBpm) >= 4)
  {
    bpm = newBpm;
    previousBpm = bpm;
  }
  delayBetweenNotes = 60000 / bpm / notesPerBeat;
  float oldNoteDuration = noteDuration;
  noteDuration = map(analogRead(potDuration), 0, 1023, 10, 1000);
  for (int i = 0; i < ARPEGGIO_LENGTH; i++)
  {
    bufferOffTimes[i] = noteDuration;
  }
}

void constructNewArpeggio(int arp[])
{
}

void switchOctave()
{
}

void checkArpeggioPressed()
{

  if (digitalRead(12) == HIGH) //Majeur
  {
    // changeArpeggio(30);
    arpeggioNotesOffset[0] = 0;
    arpeggioNotesOffset[1] = 4;
    arpeggioNotesOffset[2] = 7;
    arpeggioNotesOffset[3] = 4;
    arpeggioNotesOffset[4] = 7;
  }
  else if (digitalRead(11) == HIGH) // mineur
  {
    arpeggioNotesOffset[0] = 0;
    arpeggioNotesOffset[1] = 3;
    arpeggioNotesOffset[2] = 7;
    arpeggioNotesOffset[3] = 3;
    arpeggioNotesOffset[4] = 7;
  }
  else if (digitalRead(10) == HIGH)
  {
    arpeggioNotesOffset[0] = 0;
    arpeggioNotesOffset[1] = 3;
    arpeggioNotesOffset[2] = 6;
    arpeggioNotesOffset[3] = 9;
    arpeggioNotesOffset[4] = 6;
  }
}