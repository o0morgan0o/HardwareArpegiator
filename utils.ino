

void checkNotePressed(int buttonToCheck, int noteToPlay)
{
  // changeArpeggio(noteToPlay);

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
        storeBufferArpeggio(noteToPlay);
        // debugStr = "111";
      }
      else
      {
        // checkArpeggioPressed();
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
      //a remplacer avec les valeurs des vrais boutons
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
    // digitalWrite(23, HIGH);
  }
  else
  {
    debugStr = "button not released";
    // digitalWrite(23, LOW);
  }
}
