/*
 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 7
 * LCD Enable pin to digital pin 8
 * LCD D4 pin to digital pin 9
 * LCD D5 pin to digital pin 10
 * LCD D6 pin to digital pin 11
 * LCD D7 pin to digital pin 12
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
*/

void updateDisplay()
{

  String notePressed = "unknown";
  lcd.setCursor(0, 0);
  char myStr[] = "BPM : ";
  String str = String("BPM : " + String(bpm) + "    ");
  lcd.print(str);
  lcd.setCursor(0, 1);
  recalcValues();

  switch (myMIDInote % 12)
  {
  case 0:
    notePressed = "C";
    break;
  case 1:
    notePressed = "C#/Db";
    break;
  case 2:
    notePressed = "D";
    break;
  case 3:
    notePressed = "D#/Eb";
    break;
  case 4:
    notePressed = "E";
    break;
  case 5:
    notePressed = "F";
    break;
  case 6:
    notePressed = "F#/Gb";
    break;
  case 7:
    notePressed = "G";
    break;
  case 8:
    notePressed = "G#/Ab";
    break;
  case 9:
    notePressed = "A";
    break;
  case 10:
    notePressed = "A#/Bb";
    break;
  case 11:
    notePressed = "B";
    break;
  }

  String str2 = String(notePressed) + " {";
  for (int i = 0; i < ARPEGGIO_LENGTH; i++)
  {
    str2 = str2 + String(arpeggio[i] - myMIDInote);
    str2 = str2 + ",";
  }
  str2 = str2 + "}";
  // lcd.clear();
  lcd.print(str2);
  str2 = "update";
  lcd.print(str2);
}