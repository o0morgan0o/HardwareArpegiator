/* A implementer dans le desordre
- Bouton panik
- Boutons d'arpeges mineurs, majeurs, dominant avec les switches (3 positions ou bouttons)
- Voir si il vaut pas mieux controler les lumieres des bouttons en independant pour pouvoir les allumer  selon l'arpege 
- MIDI in ?
- Ecran
-Tap Tempo ?
*/
int btnState = 0;
void loop()
{
  //individuellement ca fonctionne voir ce qui bloque dans le programme
  if (digitalRead(46) == HIGH)
  //soudure instable sur 36
  {
    lcd.print("aaa");
  }
  else
  {
    lcd.print("bbb");
  }

  // tapTempo();
  // digitalWrite(43, HIGH);
  recalcValues();
  // checkIfNoteButtonsAreReleased();
  if (arpeggioChangeAsked)
    dumpArpeggio();

  // checkNotePressed(46, middleC + 3);
  // checkNotePressed(44, middleC + 3);
  // checkNotePressed(42, middleC + 3);
  // checkNotePressed(40, middleC + 3);
  // checkNotePressed(38, middleC + 3);
  // checkNotePressed(3, middleC + 2);
  // checkNotePressed(4, middleC + 4);
  // checkNotePressed(5, middleC + 5);
  // checkNotePressed(6, middleC + 7);
  // checkNotePressed(41, middleC + 8);
  // checkNotePressed(24, middleC + 8);
  // checkNotePressed(35, middleC + 9);
  checkArpeggioPressed();
  // checkRecording(30, 22); //changer cette pin deja utilisee

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
  //juste pour test
  // MIDImessage(noteON, 45, velocity);
  // lcd.print("note on44");
  // lcd.begin(16, 2);
  // lcd.print("test2 tes ");
  // updateDisplay();
}

void lightONButton(int noteToLight)
{
  //ca marche faudra essayer de combiner les 2 actions et de faire un switch
  if (noteToLight == middleC)
  {
    digitalWrite(43, HIGH);
  }
}

void lightOFFButton(int noteToOff)
{
  if (noteToOff == middleC)
  {
    digitalWrite(43, LOW);
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
