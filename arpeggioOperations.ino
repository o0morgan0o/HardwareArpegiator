int arpeggioNotesOffset[ARPEGGIO_LENGTH] = {0, 0, 0, 0, 0}; //arpege de depart majeur
void MIDImessage(int command, int MIDInote, int MIDIvelocity)
{
  Serial.write(command);      //send note on or note off command
  Serial.write(MIDInote);     //send pitch data
  Serial.write(MIDIvelocity); //send velocity data
}

void changeArpeggio(int midiNote)

{
  // int newArpeggio[ARPEGGIO_LENGTH] = {midiNote + , midiNote + 4, midiNote + 7, midiNote + 12, midiNote + 7};
  for (int i = 0; i < ARPEGGIO_LENGTH; i++)
  {
    // MIDImessage(noteOFF, arpeggio[i], velocity);
    // arpeggio[i] = newArpeggio[i];
    arpeggio[i] = midiNote + arpeggioNotesOffset[i];
  }
  myMIDInote = midiNote;
}

void recalcValues()
{

  bpm = map(analogRead(potBpm), 0, 1023, 280, 30); //bpm mappe de 30 a 280
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