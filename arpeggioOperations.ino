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
    temporaryDisplay(String(arpDirection), "up");
    //  checkArpeggioPressed();
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
    //faudra faire plutot 2 pour faire aller retour
    if (arpeggioLength % 2 == 0)
    {
      for (int i = 0; i < (arpeggioLength / 2 + 1); i++)
      {
        // CHANGE ICI VOIR AVEC MON DESSIN AU TABLEAU
        int bufferValue = arpeggio[i];
        arpeggio[i] = midiNote + arpeggioNotesOffset[i];
        arpeggio[arpeggioLength - 1 - i] = bufferValue;
      }
      // arpeggio[arpeggioLength / 2] = midiNote + arpeggioNotesOffset[arpeggioLength / 2];
      // arpeggio[arpeggioLength / 2] = midiNote + arpeggioNotesOffset[arpeggioLength / 2];
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

    // {
    //   for (int i = 0; i < arpeggioLength / 2; i++)
    //   {
    //     arpeggio[i] = midiNote + arpeggioNotesOffset[i];
    //   }
    //   int counter = arpeggioLength / 2 - 1;
    //   for (int i = 0; i < arpeggioLength / 2; i++)
    //   {
    //     arpeggio[i + arpeggioLength / 2] = arpeggio[counter];
    //     counter--;
    //   }
    // }
    // for (int i = 0; i < arpeggioLength; i++)
    // {
    //   int n = random(0, arpeggioLength);
    //   arpeggio[i] = midiNote + arpeggioNotesOffset[n];
    // }
    break;
  }
}

void changeArpeggioType(int arpType)
{
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

void constructNewArpeggio(int arp[])
{
}

void switchOctave()
{
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

  // temporaryDisplay(String(arpDirection), "");
}

// void changeArpeggioValues(int values[]){
//   for(int i=0; i<arpeggioLength; i++){
//     arpeggioNotesOffset[i] = values[i];
//   }

// }