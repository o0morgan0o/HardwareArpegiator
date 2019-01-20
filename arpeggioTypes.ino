
void checkArpeggioPressed()
{

  if (digitalRead(arpTypeButton1) == HIGH) //Majeur
  {
    switch (actualMaj)
    {
    case 0: //Maj
      arpeggioNotesOffset[0] = 0;
      arpeggioNotesOffset[1] = 4;
      arpeggioNotesOffset[2] = 7;
      arpeggioNotesOffset[3] = 12;
      arpeggioNotesOffset[4] = 16;
      break;
    case 1: //Maj7
      arpeggioNotesOffset[0] = 0;
      arpeggioNotesOffset[1] = 4;
      arpeggioNotesOffset[2] = 7;
      arpeggioNotesOffset[3] = 11;
      arpeggioNotesOffset[4] = 16;
      break;
    case 2: //Maj9
      arpeggioNotesOffset[0] = 0;
      arpeggioNotesOffset[1] = 4;
      arpeggioNotesOffset[2] = 7;
      arpeggioNotesOffset[3] = 11;
      arpeggioNotesOffset[4] = 14;
      break;
    case 3: //Maj#11
      arpeggioNotesOffset[0] = 0;
      arpeggioNotesOffset[1] = 4;
      arpeggioNotesOffset[2] = 7;
      arpeggioNotesOffset[3] = 11;
      arpeggioNotesOffset[4] = 18;
      break;
    case 4: //Maj6
      arpeggioNotesOffset[0] = 0;
      arpeggioNotesOffset[1] = 4;
      arpeggioNotesOffset[2] = 7;
      arpeggioNotesOffset[3] = 9;
      arpeggioNotesOffset[4] = 11;
      break;
    }
  }

  if (digitalRead(arpTypeButton2) == HIGH) //Majeur
  {
    switch (actualMin)
    {
    case 0: //Maj
      arpeggioNotesOffset[0] = 0;
      arpeggioNotesOffset[1] = 3;
      arpeggioNotesOffset[2] = 7;
      arpeggioNotesOffset[3] = 12;
      arpeggioNotesOffset[4] = 15;
      break;
    case 1: //Maj7
      arpeggioNotesOffset[0] = 0;
      arpeggioNotesOffset[1] = 3;
      arpeggioNotesOffset[2] = 7;
      arpeggioNotesOffset[3] = 10;
      arpeggioNotesOffset[4] = 15;
      break;
    case 2: //Maj9
      arpeggioNotesOffset[0] = 0;
      arpeggioNotesOffset[1] = 3;
      arpeggioNotesOffset[2] = 7;
      arpeggioNotesOffset[3] = 10;
      arpeggioNotesOffset[4] = 14;
      break;
    case 3: //Maj#11
      arpeggioNotesOffset[0] = 0;
      arpeggioNotesOffset[1] = 3;
      arpeggioNotesOffset[2] = 7;
      arpeggioNotesOffset[3] = 10;
      arpeggioNotesOffset[4] = 17;
      break;
    case 4: //Maj6
      arpeggioNotesOffset[0] = 0;
      arpeggioNotesOffset[1] = 3;
      arpeggioNotesOffset[2] = 7;
      arpeggioNotesOffset[3] = 10;
      arpeggioNotesOffset[4] = 13;
      break;
    }
    }

  if (digitalRead(arpTypeButton3) == HIGH) //Alt
  {
    switch (actualAlt)
    {
    case 0: //Maj
      arpeggioNotesOffset[0] = 0;
      arpeggioNotesOffset[1] = 3;
      arpeggioNotesOffset[2] = 6;
      arpeggioNotesOffset[3] = 12;
      arpeggioNotesOffset[4] = 15;
      break;
    case 1: //Maj7
      arpeggioNotesOffset[0] = 0;
      arpeggioNotesOffset[1] = 3;
      arpeggioNotesOffset[2] = 6;
      arpeggioNotesOffset[3] = 9;
      arpeggioNotesOffset[4] = 12;
      break;
    case 2: //Maj9
      arpeggioNotesOffset[0] = 0;
      arpeggioNotesOffset[1] = 4;
      arpeggioNotesOffset[2] = 8;
      arpeggioNotesOffset[3] = 12;
      arpeggioNotesOffset[4] = 16;
      break;
    case 3: //Maj#11
      arpeggioNotesOffset[0] = 0;
      arpeggioNotesOffset[1] = 4;
      arpeggioNotesOffset[2] = 7;
      arpeggioNotesOffset[3] = 10;
      arpeggioNotesOffset[4] = 15;
      break;
    case 4: //Maj6
      arpeggioNotesOffset[0] = 0;
      arpeggioNotesOffset[1] = 4;
      arpeggioNotesOffset[2] = 7;
      arpeggioNotesOffset[3] = 10;
      arpeggioNotesOffset[4] = 18;
      break;
    }
  }
}
