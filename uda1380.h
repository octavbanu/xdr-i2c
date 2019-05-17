#ifndef UDA1380
#define UDA1380 1

#include <i2c_t3.h>

#define UDA1380_ADDR               (0x18)

#define UDA1380_REG_EVALCLK        0x00
#define UDA1380_REG_I2S         0x01
#define UDA1380_REG_PWRCTRL       0x02
#define UDA1380_REG_ANAMIX        0x03
#define UDA1380_REG_HEADAMP       0x04
#define UDA1380_REG_MSTRVOL       0x10
#define UDA1380_REG_MIXVOL        0x11
#define UDA1380_REG_MODEBBT       0x12
#define UDA1380_REG_MSTRMUTE      0x13
#define UDA1380_REG_MIXSDO        0x14
#define UDA1380_REG_DECVOL        0x20
#define UDA1380_REG_PGA         0x21
#define UDA1380_REG_ADC         0x22
#define UDA1380_REG_AGC         0x23

#define UDA1380_REG_L3          0x7f
#define UDA1380_REG_HEADPHONE     0x18
#define UDA1380_REG_DEC         0x28

const uint8_t UDA1380InitData[][3] =
{
  /*
   *  Software reset
   */
  {UDA1380_REG_L3,          0x00, 0x00},
    
  /*
   *  Enable power for PGA & ADC
   */
  {UDA1380_REG_PWRCTRL,     0b00000000, 0b00001111},
  
  /*
   *  Clock only ADC, from SYSCLK, divisor 256fs
   */ 
  {UDA1380_REG_EVALCLK,     0b00011100, 0b00000000},
  
  /*
   *  Enable default I2S mode
   */
  {UDA1380_REG_I2S,         0x00, 0x00},

  /*
   *  Analog mixer input gain -inf
   */
  {UDA1380_REG_ANAMIX,      0b00111111, 0b00111111},
  
  /* 
   *  Enable headphone short circuit protection
   */
  {UDA1380_REG_HEADAMP,     0b00000010, 0b00000010},

  /*
   *  Master volume - no attenuation
   */
  {UDA1380_REG_MSTRVOL,     0b00000000, 0b00000000},

  /*
   *  Digital mixer volume -inf
   */
  {UDA1380_REG_MIXVOL,      0b11111111, 0b11111111},

  /*
   *  Boost treble just a notch
   */
  {UDA1380_REG_MODEBBT,     0b01010000, 0b00010000},  
  
  /*
   *  Disable mute and de-emphasis
   */
  {UDA1380_REG_MSTRMUTE,    0b00000000, 0b00000000},
  
  /*
   *  Mixer off, other settings off
   */
  {UDA1380_REG_MIXSDO,      0b00000000, 0b00000000},
  
  /*
   *  ADC decimator volume 0dB
   */
  {UDA1380_REG_DECVOL,      0b00000000, 0b00000000},
  
  /*
   *  No PGA mute, 0dB gain
   */ 
  {UDA1380_REG_PGA,         0b00000000, 0b00000000},
  
  /*
   *  Select line in, no mic, DC filter enabled
   */
  {UDA1380_REG_ADC,         0b00000000, 0b00000001},
  
  /*
   *  Disable AGC 
   */
  {UDA1380_REG_AGC,         0b00000000, 0b00000000},
 
    /*
     *End of list
   */
  {0xFF,                    0xFF, 0xFF}
};


bool uda1380_init();
#endif
