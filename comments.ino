
/*
  MIDI note player

  This sketch shows how to use the serial transmit pin (pin 1) to send MIDI note data.
  If this circuit is connected to a MIDI synth, it will play the notes
  F#-0 (0x1E) to F#-5 (0x5A) in sequence.

  The circuit:
  - digital in 1 connected to MIDI jack pin 5
  - MIDI jack pin 2 connected to ground
  - MIDI jack pin 4 connected to +5V through 220 ohm resistor
  - Attach a MIDI cable to the jack, then to a MIDI synth, and play music.

  created 13 Jun 2006
  modified 13 Aug 2012
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Midi
  voir ca pour brancher un interrupteur, pour en brancher plus, il faudra utiliser un signal analog avec differentes valeures 
  de resistance. 
  https://www.arduino.cc/en/tutorial/button
*/

//Je pense qu'il faut vraiment mieux  a chaque note ajouter une planification de note off dans une array
//si je branche plusieurs potentiometres, ils se perturbent etre eux.

/*

Pins bouttons :

Digital 23 25 27
Digital 4 5 6
Digital 2 3


Pins leds:

Analo 5 6 7
Analo 10 11 12
Analo 13 14 15


Bouton rec 
Digital 53
Digital 22
/*