
int previousStateBtnMaj = HIGH;
int previousStateBtnMin = HIGH;
int previousStateBtnAlt = HIGH;
int previousStateBtnRed1 = HIGH;
int previousStateBtnRed2 = HIGH;
int previousStateBtnRed3 = HIGH;
int previousStateBtnOctaveMinus = HIGH;
int previousStateBtnOctavePlus = HIGH;

void updateStateButtonPushed()
{

  if (digitalRead(btnMaj) == HIGH && previousStateBtnMaj == LOW)
  {
    previousStateBtnMaj = !previousStateBtnMaj;
  }

  if (digitalRead(btnMin) == HIGH && previousStateBtnMin == LOW)
  {
    previousStateBtnMin = !previousStateBtnMin;
  }
  if (digitalRead(btnAlt) == HIGH && previousStateBtnAlt == LOW)
  {
    previousStateBtnAlt = !previousStateBtnAlt;
  }

  if (digitalRead(btnRed1) == HIGH && previousStateBtnRed1 == LOW)
  {
    previousStateBtnRed1 = !previousStateBtnRed1;
  }

  if (digitalRead(btnRed2) == HIGH && previousStateBtnRed2 == LOW)
  {
    previousStateBtnRed2 = !previousStateBtnRed2;
  }

  if (digitalRead(btnRed3) == HIGH && previousStateBtnRed3 == LOW)
  {
    previousStateBtnRed3 = !previousStateBtnRed3;
  }

  if (digitalRead(btnOctaveMinus) == HIGH && previousStateBtnOctaveMinus == LOW)
  {
    previousStateBtnOctaveMinus = !previousStateBtnOctaveMinus;
  }
  if (digitalRead(btnOctavePlus) == HIGH && previousStateBtnOctavePlus == LOW)
  {
    previousStateBtnOctavePlus = !previousStateBtnOctavePlus;
  }

  if (digitalRead(btnRec) == LOW)
  {
    temporaryDisplay("Recording...", "");
    // digitalWrite(22, HIGH);
  }
}

void functionButtons()
{

  if (digitalRead(btnRed1) == LOW && previousStateBtnRed1 == HIGH)
  {
    previousStateBtnRed1 = !previousStateBtnRed1;
    // temporaryDisplay("boutton rouge1", "");
    changeArpDirection();
  }


  if(digitalRead(btnOctaveMinus) == LOW && previousStateBtnOctaveMinus==HIGH){
    previousStateBtnOctaveMinus=!previousStateBtnOctaveMinus;
    if(middleC >-10){
    middleC-=12;
    temporaryDisplay("octave - ", String(middleC));
    }
  }
  if(digitalRead(btnOctavePlus) == LOW && previousStateBtnOctavePlus==HIGH){
    previousStateBtnOctavePlus=!previousStateBtnOctavePlus;
    if(middleC <100){
    middleC+=12;
    temporaryDisplay("octave + ", String(middleC));
    }

  }
}
