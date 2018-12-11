
void loop()
{
  recalcValues();
  checkIfNoteButtonsAreReleased();
  if (arpeggioChangeAsked)
    dumpArpeggio();

  // updateDisplay();

  checkNotePressed(2, middleC);
  checkNotePressed(3, middleC + 2);
  checkNotePressed(4, middleC + 4);
  checkNotePressed(5, middleC + 5);
  checkNotePressed(6, middleC + 7);
  checkRecording(30, 22);

  if (!isRecording && digitalRead(recPin) == HIGH)
  {
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
      MIDImessage(noteOFF, noteToCheck, velocity);
      bufferTimes[k] = 99999999;
    }
  }
}
