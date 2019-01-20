/* A implementer dans le desordre
- Bouton panik
- Boutons d'arpeges mineurs, majeurs, dominant avec les switches (3 positions ou bouttons)
- Voir si il vaut pas mieux controler les lumieres des bouttons en independant pour pouvoir les allumer  selon l'arpege 
- MIDI in ?
- Ecran
-Tap Tempo ?
*/
int btnState = 0;
int aButtonIsPressed = 0;

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

void loop()
{
  if (millis() >= tempDisplayTime + 2000)
  {
    tempDisplayActivate = false;
  }
  testButtonPushed();
  ledArps();
  // testLog();

  if (arpeggioChangeAsked)
    dumpArpeggio();

  // tapTempo();
  recalcValues();
  checkIfNoteButtonsAreReleased();

  checkNotePressed(pinCnote, middleC + 0);
  checkNotePressed(pinDbnote, middleC + 1);
  checkNotePressed(pinDnote, middleC + 2);
  checkNotePressed(pinEbnote, middleC + 3);
  checkNotePressed(pinEnote, middleC + 4);
  checkNotePressed(pinFnote, middleC + 5);
  checkNotePressed(pinGbnote, middleC + 6);
  checkNotePressed(pinGnote, middleC + 7);
  checkNotePressed(pinAbnote, middleC + 8);
  checkNotePressed(pinAnote, middleC + 9);
  checkNotePressed(pinBbnote, middleC + 10);
  checkNotePressed(pinBnote, middleC + 11);
  checkArpeggioPressed();
  // checkRecording(53, 55); //changer cette pin 55 sera la pin a allumer

  /*
  if (!isRecording && digitalRead(recPin) == HIGH)
  {
    //faudra changer la pin 22
    digitalWrite(22, HIGH);
    isRecording = true;
    launchRecording();
  }
  else if (isRecording && digitalRead(recPin) == LOW)
  {
    digitalWrite(22, LOW);
    isRecording = false;
    endRecording();
  }

*/
  if (millis() - previousMillis >= delayBetweenNotes)
  {
    previousMillis = millis();
    if (currentStep >= ARPEGGIO_LENGTH - 1)
    {
      currentStep = 0;
    }
    else
    {
      currentStep++;
    }
    bufferCC[bufferStep] = arpeggio[currentStep];
    bufferTimes[bufferStep] = millis();
    bufferOffTimes[bufferStep] = noteDuration;
    lightONButton(bufferCC[bufferStep]);
    MIDImessage(noteON, bufferCC[bufferStep], velocity);
    bufferStep++;
    if (bufferStep > BUFFER_LENGTH - 2)
      bufferStep = 0;
  }

  for (int k = 0; k < BUFFER_LENGTH; k++)
  {
    int noteToCheck = bufferCC[k];
    if ((millis()) > (bufferTimes[k] + bufferOffTimes[k]))
    {
      lightOFFButton(noteToCheck);
      MIDImessage(noteOFF, noteToCheck, velocity);
      bufferTimes[k] = 99999999;
    }
  }
  updateDisplay();
}

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

void tapTempo()
{
  if (digitalRead(8) == HIGH)
  {
    if (!tapTempoButtonPushed)
    {
      //ne marche pas pour l'instant
      tapTempoButtonPushed = true;
      tapTempoBuffer[0] = tapTempoBuffer[1];
      tapTempoBuffer[1] = millis();
      // tapTempoCounter++;
      if (enoughValuesTapTempo)
      {
        bpm = (abs(tapTempoBuffer[1] - tapTempoBuffer[0])) * 60.0 / 1000.0;
      }
      enoughValuesTapTempo = true;
    }
  }
  if (digitalRead(8) == LOW)
    tapTempoButtonPushed = false;
}
