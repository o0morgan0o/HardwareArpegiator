    int arpSize;

void recalcNotesOffset(int arpLength){
    int counter =0;
    int factor=1;
    for(int i=arpLength;i <arpeggioLength; i++){
      arpeggioNotesOffset[i] = arpeggioNotesOffset[counter]+factor*12;
      if(counter <=arpLength-2){
        counter++;
      }else{
        counter=0;
        factor++;
      }
    }
}

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
      arpSize=3;
      break;
    case 1: //Maj7
      arpeggioNotesOffset[0] = 0;
      arpeggioNotesOffset[1] = 4;
      arpeggioNotesOffset[2] = 7;
      arpeggioNotesOffset[3] = 11;
      arpSize=4;
      break;
    case 2: //Maj9
      arpeggioNotesOffset[0] = 0;
      arpeggioNotesOffset[1] = 4;
      arpeggioNotesOffset[2] = 7;
      arpeggioNotesOffset[3] = 11;
      arpeggioNotesOffset[4] = 14;
      arpSize=5;
      break;
    case 3: //Maj#11
      arpeggioNotesOffset[0] = 0;
      arpeggioNotesOffset[1] = 4;
      arpeggioNotesOffset[2] = 7;
      arpeggioNotesOffset[3] = 11;
      arpeggioNotesOffset[4] = 18;
      arpSize=5;
      break;
    case 4: //Maj6
      arpeggioNotesOffset[0] = 0;
      arpeggioNotesOffset[1] = 4;
      arpeggioNotesOffset[2] = 7;
      arpeggioNotesOffset[3] = 9;
      arpSize=4;
      break;
    }
  }

  if (digitalRead(arpTypeButton2) == HIGH) //Majeur
  {
    // int arpSize;
    switch (actualMin)
    {
    case 0: //Min
      arpeggioNotesOffset[0] = 0;
      arpeggioNotesOffset[1] = 3;
      arpeggioNotesOffset[2] = 7;
      arpSize=3;
      break;
    case 1: //Min7
      arpeggioNotesOffset[0] = 0;
      arpeggioNotesOffset[1] = 3;
      arpeggioNotesOffset[2] = 7;
      arpeggioNotesOffset[3] = 10;
      arpSize=4;
      break;
    case 2: //Min9
      arpeggioNotesOffset[0] = 0;
      arpeggioNotesOffset[1] = 3;
      arpeggioNotesOffset[2] = 7;
      arpeggioNotesOffset[3] = 10;
      arpeggioNotesOffset[4] = 14;
      arpSize=5;
      break;
    case 3: //min11
      arpeggioNotesOffset[0] = 0;
      arpeggioNotesOffset[1] = 3;
      arpeggioNotesOffset[2] = 7;
      arpeggioNotesOffset[3] = 10;
      arpeggioNotesOffset[4] = 17;
      arpSize = 5;
      break;
    case 4: //Min b9
      arpeggioNotesOffset[0] = 0;
      arpeggioNotesOffset[1] = 3;
      arpeggioNotesOffset[2] = 7;
      arpeggioNotesOffset[3] = 10;
      arpeggioNotesOffset[4] = 13;
      arpSize =5;
      break;
    }
    }

  if (digitalRead(arpTypeButton3) == HIGH) //Alt
  {
    // int arpSize;
    switch (actualAlt)
    {
    case 0: //m7b5
      arpeggioNotesOffset[0] = 0;
      arpeggioNotesOffset[1] = 3;
      arpeggioNotesOffset[2] = 6;
      arpeggioNotesOffset[3] = 10;
      arpSize=4;
      break;
    case 1: //dim
      arpeggioNotesOffset[0] = 0;
      arpeggioNotesOffset[1] = 3;
      arpeggioNotesOffset[2] = 6;
      arpeggioNotesOffset[3] = 9;
      arpSize=4;
      break;
    case 2: //aug
      arpeggioNotesOffset[0] = 0;
      arpeggioNotesOffset[1] = 4;
      arpeggioNotesOffset[2] = 8;
      arpSize=3;
      break;
    case 3: //7#9
      arpeggioNotesOffset[0] = 0;
      arpeggioNotesOffset[1] = 4;
      arpeggioNotesOffset[2] = 8;
      arpeggioNotesOffset[3] = 10;
      arpeggioNotesOffset[4] = 13;
      arpSize=5;
      break;
    case 4: //7
      arpeggioNotesOffset[0] = 0;
      arpeggioNotesOffset[1] = 4;
      arpeggioNotesOffset[2] = 6;
      arpeggioNotesOffset[3] = 10;
      arpSize =4;
      break;
    }
  }
}
