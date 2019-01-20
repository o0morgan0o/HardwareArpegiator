
void testLog()
{
  digitalWrite(22, HIGH); //rec led

  digitalWrite(A5, HIGH);
  digitalWrite(A6, HIGH);
  digitalWrite(A7, HIGH);
  digitalWrite(A8, HIGH);
  digitalWrite(A9, HIGH);
  digitalWrite(A10, HIGH);
  digitalWrite(A11, HIGH);
  digitalWrite(A12, HIGH);
  digitalWrite(A13, HIGH);
  digitalWrite(A14, HIGH);
  digitalWrite(A15, HIGH);

  //test des bouttons function + rec
  testButton(4);
  testButton(25);
  testButton(27);
  testButton(2);
  testButton(3);
  testButton(5);
  testButton(6);
  testButton(23);
  testButton(53);

  //test boutons note
  testButton(pinCnote);
  testButton(pinDbnote);
  testButton(pinDnote);
  testButton(pinEbnote);
  testButton(pinEnote);
  testButton(pinFnote);
  testButton(pinGbnote);
  testButton(pinGnote);
  testButton(pinAbnote);
  testButton(pinAnote);
  testButton(pinBbnote);
  testButton(pinBnote);
  testButton(arpTypeButton1); //attention le fonctionnement est inverse pour eux
  testButton(arpTypeButton2);
  testButton(arpTypeButton3);

  //test leds bouttons
  digitalWrite(lightCnote, HIGH);
  digitalWrite(lightDbnote, HIGH);
  digitalWrite(lightDnote, HIGH);
  digitalWrite(lightEbnote, HIGH);
  digitalWrite(lightEnote, HIGH);
  digitalWrite(lightFnote, HIGH);
  digitalWrite(lightGbnote, HIGH);
  digitalWrite(lightGnote, HIGH);
  digitalWrite(lightAbnote, HIGH);
  digitalWrite(lightAnote, HIGH);
  digitalWrite(lightBbnote, HIGH);
  digitalWrite(lightBnote, HIGH);

  if (aButtonIsPressed == 0)
  {
    debugStr = "none ....";
  }
  aButtonIsPressed = 0;
}

void testButton(int ledNum)
{
  if (digitalRead(ledNum) == LOW)
  {
    aButtonIsPressed = 1;
    debugStr = String(ledNum) + "....";
  }
}
