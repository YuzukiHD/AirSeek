#include "LCD12864RSPI.h"

extern "C" {
#include <avr/pgmspace.h>
#include <inttypes.h>
#include <string.h>
#include "Arduino.h"
}

LCD12864RSPI::LCD12864RSPI() {
  this->DEFAULTTIME = 80;
  this->delaytime = DEFAULTTIME;
}

void LCD12864RSPI::delayns(void) {
  delayMicroseconds(delaytime);
}
void LCD12864RSPI::WriteByte(int dat) {
  digitalWrite(latchPin, HIGH);
  delayns();
  shiftOut(dataPin, clockPin, MSBFIRST, dat);
  digitalWrite(latchPin, LOW);
}

void LCD12864RSPI::WriteCommand(int CMD) {
  int H_data, L_data;
  H_data = CMD;
  H_data &= 0xf0;
  L_data = CMD;
  L_data &= 0x0f;
  L_data <<= 4;
  WriteByte(0xf8);
  WriteByte(H_data);
  WriteByte(L_data);
}

void LCD12864RSPI::WriteData(int CMD) {
  int H_data, L_data;
  H_data = CMD;
  H_data &= 0xf0;
  L_data = CMD;
  L_data &= 0x0f;
  L_data <<= 4;
  WriteByte(0xfa);
  WriteByte(H_data);
  WriteByte(L_data);
}

void LCD12864RSPI::Initialise() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  digitalWrite(latchPin, LOW);
  delayns();

  WriteCommand(0x30);
  WriteCommand(0x0c);
  WriteCommand(0x01);
  WriteCommand(0x06);
}

void LCD12864RSPI::CLEAR(void) {
  WriteCommand(0x30);
  WriteCommand(0x01);
}

void LCD12864RSPI::DisplayString(int X, int Y, uchar* ptr, int dat) {
  int i;

  switch (X) {
    case 0:
      Y |= 0x80;
      break;

    case 1:
      Y |= 0x90;
      break;

    case 2:
      Y |= 0x88;
      break;

    case 3:
      Y |= 0x98;
      break;

    default:
      break;
  }
  WriteCommand(Y);

  for (i = 0; i < dat; i++) {
    WriteData(ptr[i]);
  }
}

void LCD12864RSPI::DisplaySig(int M, int N, int sig) {
  switch (M) {
    case 0:
      N |= 0x80;
      break;

    case 1:
      N |= 0x90;
      break;

    case 2:
      N |= 0x88;
      break;

    case 3:
      N |= 0x98;
      break;

    default:
      break;
  }
  WriteCommand(N);
  WriteData(sig);
}

void LCD12864RSPI::DrawFullScreen(uchar* p) {
  int ygroup, x, y, i;
  int temp;
  int tmp;

  for (ygroup = 0; ygroup < 64; ygroup++) {
    if (ygroup < 32) {
      x = 0x80;
      y = ygroup + 0x80;
    } else {
      x = 0x88;
      y = ygroup - 32 + 0x80;
    }
    WriteCommand(0x34);
    WriteCommand(y);
    WriteCommand(x);
    WriteCommand(0x30);
    tmp = ygroup * 16;
    for (i = 0; i < 16; i++) {
      temp = p[tmp++];
      WriteData(temp);
    }
  }
  WriteCommand(0x34);
  WriteCommand(0x36);
}

LCD12864RSPI LCDA = LCD12864RSPI();