#include <LCD12864RSPI.h>
#include <stdio.h>

#define AR_SIZE(a) sizeof(a) / sizeof(a[0])

unsigned char TEMPCHAR[] = {0xCE, 0xC2, 0xB6, 0xC8, 0x3A, 0x00};
unsigned char CCHAR[] = "C";

char* temp(double t) {
  static char buffer[10];
  sprintf(buffer, "%d", static_cast<int>(t));
  return buffer;
}