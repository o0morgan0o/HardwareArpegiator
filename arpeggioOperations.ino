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

  if (digitalRead(arpTypeButton1) == HIGH) //Majeur
  {
    temporaryDisplay("test", "ffdsk");
    currentArp = "major";
    arpeggioNotesOffset[0] = 0;
    arpeggioNotesOffset[1] = 4;
    arpeggioNotesOffset[2] = 7;
    arpeggioNotesOffset[3] = 12;
    arpeggioNotesOffset[4] = 7;
    // createNewArpeggio();
  }
  else if (digitalRead(arpTypeButton2) == HIGH) // mineur
  {
    currentArp = "minor";
    arpeggioNotesOffset[0] = 0;
    arpeggioNotesOffset[1] = 3;
    arpeggioNotesOffset[2] = 7;
    arpeggioNotesOffset[3] = 12;
    arpeggioNotesOffset[4] = 7;
    // createNewArpeggio();
  }
  else if (digitalRead(arpTypeButton3) == HIGH)
  {
    currentArp = "dim";
    arpeggioNotesOffset[0] = 0;
    arpeggioNotesOffset[1] = 3;
    arpeggioNotesOffset[2] = 6;
    arpeggioNotesOffset[3] = 9;
    arpeggioNotesOffset[4] = 12;

    // createNewArpeggio();
  }
  else
  {
  }
}

void createNewArpeggio()
{
  for (int i = 0; i < ARPEGGIO_LENGTH; i++)
  {
    arpeggio[i] = myMIDInote + arpeggioNotesOffset[i];
  }
}

void changeArpDirection()
{
}