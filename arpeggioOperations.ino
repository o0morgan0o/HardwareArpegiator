
void MIDImessage(int command, int MIDInote, int MIDIvelocity)
{
  Serial.write(command);      //send note on or note off command
  Serial.write(MIDInote);     //send pitch data
  Serial.write(MIDIvelocity); //send velocity data
}

void changeArpgeggio(int midiNote)
{
  int newArpeggio[ARPEGGIO_LENGTH] = {midiNote + 1, midiNote + 3, midiNote + 5, midiNote + 8, midiNote + 12};
  for (int i = 0; i < ARPEGGIO_LENGTH; i++)
  {
    // MIDImessage(noteOFF, arpeggio[i], velocity);
    arpeggio[i] = newArpeggio[i];
  }
  myMIDInote = midiNote;
}
void recalcValues()
{
  //recalc with new bpm
  //peut etre un soucis avec la note duration a cause du premier delay

  bpm = map(analogRead(potPin), 0, 1023, 280, 30); //bpm mappe de 30 a 280
  // bpm = newBpm;
  delayBetweenNotes = 60000 / bpm / notesPerBeat;
  interval = delayBetweenNotes;
  float oldNoteDuration = noteDuration;
  noteDuration = map(analogRead(potDuration), 0, 1023, 10, 1000);
  for (int i = 0; i < ARPEGGIO_LENGTH; i++)
  {
    bufferOffTimes[i] = noteDuration;
  }

  // previousMillisOff = noteDuration;
  // firstTimeDelay = noteDuration;
}

void constructNewArpeggio(int arp[])
{
}

// constructNewArpeggio(major);

void switchOctave()
{
}