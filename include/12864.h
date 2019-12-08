#include <LCD12864RSPI.h>
#include <stdio.h>

#define AR_SIZE(a) sizeof(a) / sizeof(a[0])

unsigned char TEMPCHAR[] = {0xCE, 0xC2, 0xB6, 0xC8};

unsigned char HUMCHAR[] = {0xCA, 0xAA, 0xB6, 0xC8};

char* i2c(double t) {
  static char buffer[10];
  sprintf(buffer, "%d", static_cast<int>(t));
  return buffer;
}