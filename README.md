
# Arduino based Hardware MIDI Arpegiattor. (BETA Version)

## The project

<img src="https://i.imgur.com/sdqKrx9.jpg" width="auto" height="auto" />


This is a first prototype of a Arduino based Hardware Arpegiattor. I want in the future to rebuild it with better optimizations and improvements, but because of lack of time I don't konw when I'll be able to do so. So, I post it here as it is, so anybody who is searching for a little similar project can have some ideas... Fell free to improve or use code or ideas of this repo.

## What is it for ?

An arpegiattor is something which when connected via MIDI cable to a synthetizer (hardware or virtual instrumnent) can trigger chords or notes so that it creates a kind of musical background or atmosphere for different sound explorations.

Few of my user stories were the following:
  - Trigger easily different kind of arpeggios (minor, major, etc... ) including some "jazzy" chords with extensions and alterations.
  - Implement a kind of "recording mode" which permit to personnalize the arpeggios and feel free to experiment crazy note successions.
  - Have control on BPM or note length, and have controls on octaves or arpeggio direction.

## Material Needed

The list can be adapted but here are the main components:

  1 - Arduino MEGA 2560 (many inputs/outputs are required in the actual configurations) (x1)
  
  2- Arcade LED buttons [like these ones](https://boutique.semageek.com/en/1047-mini-arcade-led-button-24mm-red-transparent.html). These will be used as piano keyboard. (x12)
  
  3 - simple Arcade buttons [like these ones](https://boutique.semageek.com/fr/258-bouton-arcade-jaune.html?search_query=arcade&results=29) (x3)

  4 - simple push buttons.(x6)

  5 - biposition push button [like this one](https://boutique.semageek.com/fr/1056-bouton-poussoir-lumineux-16mm-vert.html?search_query=bouton&results=197) (x1)

  6 - LEDs (x9);

  7 - potentiometers 3 pins (x2)

  8 - Liquid Crystal Display (x1)

  9 - MIDI 5 pins plug (x1)

  10 - Breadboard or soldering plates.

  11 - Bunch of cables, wires and 220 ohms resistors.

  12 - Some patience and coffee.


## The Schematic

Here is a synthetic representation of main connections of the project.
Because the schema is already is very compressed I don't show some connections about the lighting because it would lead to too much confusion. Many improvements can be made, because I am not familiar in C language, all the code and more globally the use of Arduino connections will be made clearly better in the future versions. Please just take this schema as an help.


<img src="https://i.imgur.com/leC2vnD.png" width="auto" height="auto"/>



If you want to construct some kind of box for this project here you can find for starting point the 3d printing STL file top plate for incorporation of the elements. (3d fusion360 file is include in "plate 3d object" folder).

<span style="display:flex; justify-content:center; ">
<img src="https://i.imgur.com/j6yXCQZ.png" widht="300px" height="300px"/>
</span>

The plate needs to be remade to have better incorporation of the elements. So be aware that some corrections are to be done according to your components you will use.




## Demos

[Quick example of utilisation with a VST (the arpeggiator controls the uDiva VST)](https://youtu.be/ljZOk-fAyPg)

## Basic Usage

But pushing of the arp buttons (in green), an arpeggio is set in memory and will be launch at the next push of one note. The green buttons represents 3 family of arpeggios : Major, Minor, and Others.
But pressing arpeggio type button (in black), the arpeggio will be a variation of the family (example minor7 or minor9 for the Minor family, etc...)

**Recording mode:**
By pressing the "rec" button, the notes can be pressed, and at the release of the "rec" button, the arpeggio will be created according to all the notes which have been pushed during the recording.

Octave can be switched by the 2 corresponding buttons (blue) and the length of the arpeggio can be increased or decreased by pression the red buttons at the top.




## Ideas of improvements for the future versions

- Sync MIDI via a new connection MIDI-in and better communication with incoming signals.
- On / Off buttons for switching off the arpeggio even when connected.
- Battery usage (for the moment the alimentation is made via usb cable)
- Include a "Tap Tempo" button.
- Inculde "Swing" controls for more groovy grooves.
- Permit to insert blank notes in an arpeggio, especially in record mode.
- Record of parameters like note Length or even BPM during the rec mode.
- Better code !!

## TroubleShootings

All the ino files should compile for the Arduino MEGA2560.
Tested on windows 10 environnement with Visual Studio code and Arduino Extension.
If compilation errors, try to merge all arduino files into one big .ino file.