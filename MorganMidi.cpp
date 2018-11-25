// #include "Arduino.h"
#include "MorganMidi.h"

NotePlaying::NotePlaying(int _midiCC, long _timeOff)
{
  midiCC = _midiCC;
  timeOff = _timeOff;
}

void NotePlaying::dot()
{
}

void NotePlaying::dash()
{
}