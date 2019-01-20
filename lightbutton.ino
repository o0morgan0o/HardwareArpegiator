
void lightONButton(int noteToLight)
{
  switch ((noteToLight + 40) % 12) //a ameliorer pour recalcer sur do
  {
  case 0:
    digitalWrite(lightCnote, HIGH);
    break;
  case 1:
    digitalWrite(lightDbnote, HIGH);
    break;
  case 2:
    digitalWrite(lightDnote, HIGH);
    break;
  case 3:
    digitalWrite(lightEbnote, HIGH);
    break;
  case 4:
    digitalWrite(lightEnote, HIGH);
    break;
  case 5:
    digitalWrite(lightFnote, HIGH);
    break;
  case 6:
    digitalWrite(lightGbnote, HIGH);
    break;
  case 7:
    digitalWrite(lightGnote, HIGH);
    break;
  case 8:
    digitalWrite(lightAbnote, HIGH);
    break;
  case 9:
    digitalWrite(lightAnote, HIGH);
    break;
  case 10:
    digitalWrite(lightBbnote, HIGH);
    break;
  case 11:
    digitalWrite(lightBnote, HIGH);
    break;
  }
}

void lightOFFButton(int noteToOff)
{
  switch ((noteToOff + 40) % 12)
  {
  case 0:
    digitalWrite(lightCnote, LOW);
    break;
  case 1:
    digitalWrite(lightDbnote, LOW);
    break;
  case 2:
    digitalWrite(lightDnote, LOW);
    break;
  case 3:
    digitalWrite(lightEbnote, LOW);
    break;
  case 4:
    digitalWrite(lightEnote, LOW);
    break;
  case 5:
    digitalWrite(lightFnote, LOW);
    break;
  case 6:
    digitalWrite(lightGbnote, LOW);
    break;
  case 7:
    digitalWrite(lightGnote, LOW);
    break;
  case 8:
    digitalWrite(lightAbnote, LOW);
    break;
  case 9:
    digitalWrite(lightAnote, LOW);
    break;
  case 10:
    digitalWrite(lightBbnote, LOW);
    break;
  case 11:
    digitalWrite(lightBnote, LOW);
    break;
  }
}
