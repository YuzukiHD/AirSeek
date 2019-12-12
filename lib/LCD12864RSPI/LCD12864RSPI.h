#include <Arduino.h>
#ifndef LCD12864RSPI_h
#define LCD12864RSPI_h
#include <avr/pgmspace.h>
#include <inttypes.h>

#define LCDRS 4  // latchPin
#define LCDRW 5  // dataPin
#define LCDE 6   // clockPin

class LCD12864RSPI {
  typedef unsigned char uchar;

 public:
  LCD12864RSPI();

  void Initialise(void);
  void delayns(void);

  void WriteByte(int dat);
  void WriteCommand(int CMD);
  void WriteData(int CMD);

  void CLEAR(void);
  void DisplayString(int X, int Y, uchar* ptr, int dat);
  void DisplaySig(int M, int N, int sig);
  void DrawFullScreen(uchar* p);

  int delaytime;
  int DEFAULTTIME;

  static const int latchPin = LCDRS;
  static const int clockPin = LCDE;
  static const int dataPin = LCDRW;
};
extern LCD12864RSPI LCDA;
#endif
