
void checkRecording(int buttonToCheck, int pinToLight)
{
  if (digitalRead(buttonToCheck) == HIGH)
  {
    digitalWrite(pinToLight, HIGH);
  }
  else
  {
    digitalWrite(pinToLight, LOW);
  }
}

void launchRecording()
{
  bufferCurrentStep = 0;
  for (int k = 0; k < ARPEGGIO_LENGTH; k++)
  {
    bufferArpeggio[k] = arpeggio[k];
  }
}

void endRecording()
{
  arpeggioChangeAsked = true;
}

void storeBufferArpeggio(int noteToBuffer)
{
  bufferArpeggio[bufferCurrentStep] = noteToBuffer;
  bufferCurrentStep++;
  if (bufferCurrentStep >= ARPEGGIO_LENGTH)
  {
    bufferCurrentStep = 0;
  }
}

void dumpArpeggio()
{
  lcd.print("ddd");
  for (int i = 0; i < ARPEGGIO_LENGTH; i++)
  {
    arpeggio[i] = bufferArpeggio[i];
  }
  arpeggioChangeAsked = false;
}
