
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
  // counterRecording=0;
  bufferCurrentStep = 0;
  // for (int k = 0; k < arpeggioLength; k++)
  // {
  // bufferArpeggio[k] = arpeggio[k];
  // bufferArpeggio[k] = 0;
  // }
}

void endRecording()
{
  arpeggioChangeAsked = true;
}

void dumpArpeggio()
{
  String myStr = "";
  if (counterRecording >= 2)
  {

    arpeggioLength = counterRecording;
    for (int i = 0; i < arpeggioLength; i++)
    {
      arpeggio[i] = bufferArpeggio[i];
      myStr += " " + String(bufferArpeggio[i]);
    }
  }
  arpeggioChangeAsked = false;
  temporaryDisplay(myStr, "test2");
}
