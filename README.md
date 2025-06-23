Arduino PGA116 Library
An Arduino library for interfacing with the Texas Instruments PGA116 — a digitally controlled programmable gain amplifier with analog multiplexer.

(https://www.ti.com/product/de-de/PGA116)

Features
Simple interface to control the PGA116 over SPI

Select input channel and gain with one command

Easy setup with standard Arduino SPI library

Requirements
Arduino board (Uno, Mega, etc.)

PGA116 IC

SPI-compatible wiring

Arduino IDE (1.8.x or newer)

Installation
To install the library:

Clone or download this repository:

bash
Kopieren
Bearbeiten
git clone https://github.com/yourusername/Arduino-PGA116.git
Move the folder into your Arduino libraries directory.

Restart the Arduino IDE.

Usage
Include the library
cpp
Kopieren
Bearbeiten
#include <SPI.h>
#include "PGA116.h"
Initialize the PGA116
The PGA116 uses a Chip Select (CS) pin to communicate over SPI. You can define this in the constructor:

cpp
Kopieren
Bearbeiten
PGA116 pga(10); // Using pin 10 for chip select
Set Channel and Gain
Use the SetChannelAndGain() method to choose the input channel (0–7) and gain setting (see datasheet for valid gain values).

cpp
Kopieren
Bearbeiten
pga.SetChannelAndGain(3, 4); // Channel 3, Gain setting 4
Example
cpp
Kopieren
Bearbeiten
#include <SPI.h>
#include "PGA116.h"

PGA116 pga(10);

void setup() {
  SPI.begin();
  pga.SetChannelAndGain(0, 2); // Select channel 0 with gain 2
}

void loop() {
  // Your main code here
}
