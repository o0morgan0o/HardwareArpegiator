//reste plus qu'a faire un mode d'enregistrement pour enregistrer des progressions d'accord

void checkNotePressed(int buttonToCheck, int noteToPlay)
{
  if (noteButtonIsReleased)
  { //ca risque de poser probleme quand implementation boutton type arpege simultane

    buttonState = digitalRead(buttonToCheck);
    buttonState = !buttonState;
    // buttonState = LOW;
    if (buttonState == HIGH && previousState == LOW)

    {
      noteButtonIsReleased = false;
      previousState = HIGH;
      if (isRecording)
      {
        bufferArpeggio[counterRecording] = noteToPlay;
        counterRecording++;
        arpeggioLength = counterRecording;
        temporaryDisplay(String(noteToPlay), "Recording ...");
      }
      else
      {
        changeArpeggio(noteToPlay);
      }
    }
    else if (buttonState == LOW)
    {
      previousState = LOW;
    }
  }
}

void checkIfNoteButtonsAreReleased()
{
  if (
      digitalRead(pinCnote) == HIGH &&
      digitalRead(pinDbnote) == HIGH &&
      digitalRead(pinDnote) == HIGH &&
      digitalRead(pinEbnote) == HIGH &&
      digitalRead(pinEnote) == HIGH &&
      digitalRead(pinFnote) == HIGH &&
      digitalRead(pinGbnote) == HIGH &&
      digitalRead(pinGnote) == HIGH &&
      digitalRead(pinAbnote) == HIGH &&
      digitalRead(pinAnote) == HIGH &&
      digitalRead(pinBbnote) == HIGH &&
      digitalRead(pinBnote) == HIGH)
  {
    debugStr = "button released";
    noteButtonIsReleased = true;
  }
  else
  {
    debugStr = "button not released";
  }
}

void storeBufferArpeggio(int noteToBuffer)
{
  bufferArpeggio[bufferCurrentStep] = noteToBuffer;
  bufferCurrentStep++;
  if (bufferCurrentStep >= arpeggioLength)
  {
    bufferCurrentStep = 0;
  }
}

void storeBufferArpeggioRec(int noteToBuffer)
{
}