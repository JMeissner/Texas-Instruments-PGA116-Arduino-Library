# Arduino PGA116 Library

An Arduino library for interfacing with the Texas Instruments PGA116 — a digitally controlled programmable gain amplifier with analog multiplexer.

[Product Datasheet](https://www.ti.com/product/de-de/PGA116)

## Features

- Simple interface to control the PGA116 over SPI
- Select input channel and gain with one command
- Easy setup with standard Arduino SPI library

## Requirements

- Arduino IDE compatible board (tested on ESP32-C3 SuperMini)
- PGA116 IC
- SPI-compatible wiring

## Installation

To install the library:

1. Clone or download this repository:
   ```bash
   git clone https://github.com/JMeissner/Texas-Instruments-PGA116-Arduino-Library.git
   ```

2. Move the folder into your Arduino libraries directory.

3. Restart the Arduino IDE.

## Usage

### Include the library

```cpp
#include <SPI.h>
#include "PGA116.h"
```

### Initialize the PGA116

The PGA116 uses a Chip Select (CS) pin to communicate over SPI. You can define this in the constructor:

```cpp
PGA116 pga(10); // Using pin 10 for chip select
```

### Set Channel and Gain

Use the `SetChannelAndGain()` method to choose the input channel (0–7) and gain setting (see datasheet for valid gain values).

```cpp
pga.SetChannelAndGain(3, 4); // Channel 3, Gain setting 4
```

## Example

```cpp
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
```
