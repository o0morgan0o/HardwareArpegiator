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
void loop()
{
  if (millis() >= tempDisplayTime + 2000)
  {
    tempDisplayActivate = false;
  }
  updateStateButtonPushed();
  functionButtons();
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


  if (!isRecording && digitalRead(btnRec) == LOW){
    digitalWrite(lightRec, HIGH);
    isRecording = true;
    launchRecording();
  }
  else if(isRecording && digitalRead(btnRec) == HIGH){
    digitalWrite(lightRec, LOW);
    isRecording=false;
    endRecording();

  }

  if (millis() - previousMillis >= delayBetweenNotes)
  {
    previousMillis = millis();
    if (currentStep >= arpeggioLength - 1)
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



// void tapTempo()
// {
//   if (digitalRead(8) == HIGH)
//   {
//     if (!tapTempoButtonPushed)
//     {
//       //ne marche pas pour l'instant
//       tapTempoButtonPushed = true;
//       tapTempoBuffer[0] = tapTempoBuffer[1];
//       tapTempoBuffer[1] = millis();
//       // tapTempoCounter++;
//       if (enoughValuesTapTempo)
//       {
//         bpm = (abs(tapTempoBuffer[1] - tapTempoBuffer[0])) * 60.0 / 1000.0;
//       }
//       enoughValuesTapTempo = true;
//     }
//   }
//   if (digitalRead(8) == LOW)
//     tapTempoButtonPushed = false;
// }
