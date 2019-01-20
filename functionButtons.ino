String currentMajArp = "";
void testButtonPushed()
{

  if (digitalRead(btnMaj) == HIGH && previousStateBtnMaj == LOW)
  {
    previousStateBtnMaj = !previousStateBtnMaj;
  }

  if (digitalRead(btnMin) == LOW)
  {
    temporaryDisplay("New Arp", "minor");
  }
  if (digitalRead(btnAlt) == LOW)
  {
    temporaryDisplay("New Arp", "other");
  }

  if (digitalRead(btnRed1) == LOW)
  {
    temporaryDisplay("boutton rouge1", "");
    changeArpDirection();
  }
  if (digitalRead(btnRed2) == LOW)
  {
    temporaryDisplay("boutton rouge2", "");
  }
  if (digitalRead(btnRed3) == LOW)
  {
    temporaryDisplay("boutton rouge3", "");
  }

  if (digitalRead(btnOctaveMinus) == LOW)
  {
    temporaryDisplay("Octave -", "");
  }
  if (digitalRead(btnOctavePlus) == LOW)
  {
    temporaryDisplay("Octave +", "");
  }
}

void ledArps()
{

  if (digitalRead(btnMaj) == LOW && previousStateBtnMaj == HIGH)
  {
    if (actualMaj <= 3)
    {
      actualMaj++;
    }
    else
    {
      actualMaj = 0;
    }
    switch (actualMaj)
    {
    case 0:
      currentMajArp = "Major";
      digitalWrite(light1, HIGH);
      digitalWrite(light2, LOW);
      digitalWrite(light3, LOW);
      break;
    case 1:
      currentMajArp = "Major7";
      digitalWrite(light1, LOW);
      digitalWrite(light2, HIGH);
      digitalWrite(light3, LOW);
      break;
    case 2:
      currentMajArp = "Major9";
      digitalWrite(light1, LOW);
      digitalWrite(light2, LOW);
      digitalWrite(light3, HIGH);
      break;
    case 3:
      currentMajArp = "Major#4";
      digitalWrite(light1, HIGH);
      digitalWrite(light2, HIGH);
      digitalWrite(light3, LOW);
      break;
    case 4:
      currentMajArp = "Major6";
      digitalWrite(light1, LOW);
      digitalWrite(light2, HIGH);
      digitalWrite(light3, HIGH);
      break;
    default:
      digitalWrite(light1, LOW);
      digitalWrite(light2, LOW);
      digitalWrite(light3, LOW);
    }
    previousStateBtnMaj = !previousStateBtnMaj;
    temporaryDisplay("New Arp", currentMajArp);
  }
}
