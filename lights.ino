
void ledArps()
{

//************************************************
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

//*********************************************************
  if (digitalRead(btnMin) == LOW && previousStateBtnMin == HIGH)
  {
    if (actualMin <= 3)
    {
      actualMin++;
    }
    else
    {
      actualMin = 0;
    }
    switch (actualMin)
    {
    case 0:
      currentMinArp = "Minor";
      digitalWrite(light4, HIGH);
      digitalWrite(light5, LOW);
      digitalWrite(light6, LOW);
      break;
    case 1:
      currentMinArp = "Minor7";
      digitalWrite(light4, LOW);
      digitalWrite(light5, HIGH);
      digitalWrite(light6, LOW);
      break;
    case 2:
      currentMinArp = "Minor9";
      digitalWrite(light4, LOW);
      digitalWrite(light5, LOW);
      digitalWrite(light6, HIGH);
      break;
    case 3:
      currentMinArp = "Minor11";
      digitalWrite(light4, HIGH);
      digitalWrite(light5, HIGH);
      digitalWrite(light6, LOW);
      break;
    case 4:
      currentMinArp = "Minorb9";
      digitalWrite(light4, LOW);
      digitalWrite(light5, HIGH);
      digitalWrite(light6, HIGH);
      break;
    default:
      digitalWrite(light4, LOW);
      digitalWrite(light5, LOW);
      digitalWrite(light6, LOW);
    }
    previousStateBtnMin = !previousStateBtnMin;
    temporaryDisplay("New Arp", currentMinArp);
  }

//********************************************************
  if (digitalRead(btnAlt) == LOW && previousStateBtnAlt == HIGH)
  {
    if (actualAlt <= 3)
    {
      actualAlt++;
    }
    else
    {
      actualAlt = 0;
    }
    switch (actualAlt)
    {
    case 0:
      currentAltArp = "min7b5";
      digitalWrite(light7, HIGH);
      digitalWrite(light8, LOW);
      digitalWrite(light9, LOW);
      break;
    case 1:
      currentAltArp = "dim";
      digitalWrite(light7, LOW);
      digitalWrite(light8, HIGH);
      digitalWrite(light9, LOW);
      break;
    case 2:
      currentAltArp = "aug";
      digitalWrite(light7, LOW);
      digitalWrite(light8, LOW);
      digitalWrite(light9, HIGH);
      break;
    case 3:
      currentAltArp = "7#9";
      digitalWrite(light7, HIGH);
      digitalWrite(light8, HIGH);
      digitalWrite(light9, LOW);
      break;
    case 4:
      currentAltArp = "7b5";
      digitalWrite(light7, LOW);
      digitalWrite(light8, HIGH);
      digitalWrite(light9, HIGH);
      break;
    default:
      digitalWrite(light7, LOW);
      digitalWrite(light8, LOW);
      digitalWrite(light9, LOW);
    }
    previousStateBtnAlt = !previousStateBtnAlt;
    temporaryDisplay("New Arp", currentAltArp);
  }
}