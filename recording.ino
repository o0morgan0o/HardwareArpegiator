
void checkRecording(int buttonToCheck, int pinToLight)
{
  if (!digitalRead(buttonToCheck) == HIGH)
  {
    digitalWrite(pinToLight, HIGH);
    // isRecording = true;
  }
  else
  {
    digitalWrite(pinToLight, LOW);
  }
}

void launchRecording()
{
  bufferCurrentStep = 0;
  for (int k = 0; k < arpeggioLength; k++)
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
  if (bufferCurrentStep >= arpeggioLength)
  {
    bufferCurrentStep = 0;
  }
}

void dumpArpeggio()
{
  for (int i = 0; i < arpeggioLength; i++)
  {
    arpeggio[i] = bufferArpeggio[i];
  }
  arpeggioChangeAsked = false;
}
