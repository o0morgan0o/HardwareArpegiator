

void checkNotePressed(int buttonToCheck, int noteToPlay)
{
  //test
  // changeArpeggio(noteToPlay);
  // lcd.clear();
  // lcd.print("nte");

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
      }
      else
      {
        changeArpeggio(noteToPlay);
        lcd.clear();
        lcd.print("nte");
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
      digitalRead(2) == LOW &&
      digitalRead(3) == LOW &&
      digitalRead(4) == LOW &&
      digitalRead(5) == LOW &&
      digitalRead(6) == LOW)
  {
    noteButtonIsReleased = true;
    digitalWrite(23, HIGH);
  }
  else
  {
    digitalWrite(23, LOW);
  }
}