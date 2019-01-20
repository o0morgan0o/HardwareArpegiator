// int majArp = {0, 2, 4, 5, 6};

void MIDImessage(int command, int MIDInote, int MIDIvelocity)
{
  Serial.write(command);      //send note on or note off command
  Serial.write(MIDInote);     //send pitch data
  Serial.write(MIDIvelocity); //send velocity data
}

void changeArpeggio(int midiNote)

{
  switch (arpDirection)
  {
  case 0: //cas pour arpege ascendante
    for (int i = 0; i < ARPEGGIO_LENGTH; i++)
    {
      arpeggio[i] = midiNote + arpeggioNotesOffset[i];
    }
    myMIDInote = midiNote;
    break;
  case 1: //cas pour arpege descendant y'a un truc qui marche pas
    for (int i = 0; i < ARPEGGIO_LENGTH; i++)
    {
      arpeggio[ARPEGGIO_LENGTH-1-i] = midiNote + arpeggioNotesOffset[i];
    }
    myMIDInote = midiNote;
  case 2: //cas pour arpege aleatoire
  for(int i=0;i<ARPEGGIO_LENGTH; i++){
    int n = random(0, ARPEGGIO_LENGTH);
    arpeggio[i] = midiNote + arpeggioNotesOffset[n];

  }
  myMIDInote = midiNote;
  break;
  }
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

void createNewArpeggio()
{
  for (int i = 0; i < ARPEGGIO_LENGTH; i++)
  {
    arpeggio[i] = myMIDInote + arpeggioNotesOffset[i];
  }
}

void changeArpDirection()
{

  if (arpDirection <= 1)
  {
    arpDirection++;
  }
  else
  {
    arpDirection = 0;
  }
  temporaryDisplay(String(arpDirection), "");
}


// void changeArpeggioValues(int values[]){
//   for(int i=0; i<ARPEGGIO_LENGTH; i++){
//     arpeggioNotesOffset[i] = values[i];
//   }

// }