
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
    temporaryDisplay(String(arpDirection), "up");
    recalcNotesOffset(arpeggioLength);
    for (int i = 0; i < arpeggioLength; i++)
    {
      arpeggio[i] = midiNote + arpeggioNotesOffset[i];
    }
    myMIDInote = midiNote;
    break;
  case 1: //cas pour arpege descendant y'a un truc qui marche pas
    temporaryDisplay(String(arpDirection), "down");
    for (int i = 0; i < arpeggioLength; i++)
    {
      arpeggio[arpeggioLength - 1 - i] = midiNote + arpeggioNotesOffset[i];
    }
    myMIDInote = midiNote;
    break;
  case 2: //cas pour arpege aleatoire
    temporaryDisplay(String(arpDirection), "up and down");
    if (arpeggioLength % 2 == 0)
    {
      for (int i = 0; i < (arpeggioLength / 2 + 1); i++)
      {
        int bufferValue = arpeggio[i];
        arpeggio[i] = midiNote + arpeggioNotesOffset[i];
        arpeggio[arpeggioLength - 1 - i] = bufferValue;
      }
      myMIDInote = midiNote;
    }
    else
    {
      for (int i = 0; i < (arpeggioLength / 2); i++)
      {
        arpeggio[i] = midiNote + arpeggioNotesOffset[i];
        arpeggio[arpeggioLength - 1 - i] = arpeggio[i];
      }
      myMIDInote = midiNote;
    }

    break;
  }
}

void recalcValues()
{

  int newBpm = map(analogRead(potBpm), 0, 1023, 30, 320); //bpm mappe de 30 a 280
  if (abs(newBpm - previousBpm) >= 4)
  {
    bpm = newBpm;
    previousBpm = bpm;
  }
  delayBetweenNotes = 60000 / bpm / notesPerBeat;
  float oldNoteDuration = noteDuration;
  noteDuration = map(analogRead(potDuration), 0, 1023, 10, 1000);
  for (int i = 0; i < arpeggioLength; i++)
  {
    bufferOffTimes[i] = noteDuration;
  }
}

void createNewArpeggio()
{
  for (int i = 0; i < arpeggioLength; i++)
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
  changeArpeggio(myMIDInote);
}