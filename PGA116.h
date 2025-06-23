#ifndef __PGA116_H__
#define __PGA116_H__

#include <SPI.h>

// PGA116 Commands
#define CMD_WRITE 0x2A00  // Write command
#define CMD_SHUTDOWN_EN 0xE1F1  // Shutdown Enable
#define CMD_SHUTDOWN_DIS 0xE100  // Shutdown Disable

// Channel definitions
#define CH0 0x00
#define CH1 0x01
#define CH2 0x02
#define CH3 0x03
#define CH4 0x04
#define CH5 0x05
#define CH6 0x06
#define CH7 0x07
#define CH8 0x08
#define CH9 0x09

// Gain definitions
#define GAIN_1 0x00
#define GAIN_2 0x01
#define GAIN_4 0x02
#define GAIN_8 0x03
#define GAIN_16 0x04
#define GAIN_32 0x05
#define GAIN_64 0x06
#define GAIN_128 0x07

class PGA116 {
    public:
        PGA116(int cs_pin);
        void SendCommand(uint16_t command);
        void SetChannelAndGain(uint8_t channel, uint8_t gain);
    private:
        int _cs_pin;
};

#endif