#ifndef MorganMidi_h
#define MorganMidi_h

// #include "Arduino.h"

class NotePlaying
{

public:
  NotePlaying(int _midiCC, long _timeOff);
  void dot();
  void dash();

private:
  int midiCC;
  long timeOff;
};

#endif