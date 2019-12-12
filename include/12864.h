#include <LCD12864RSPI.h>
#include <stdio.h>

#define AR_SIZE(a) sizeof(a) / sizeof(a[0])

unsigned char STARTUP_0[] = "STARTING...";

unsigned char STARTUP_1[] = "STARTING...";

unsigned char TEMPCHAR[] = "TEM:";

unsigned char HUMCHAR[] = "HUM:";

char* i2c(double t) {
  static char buffer[10];
  sprintf(buffer, "%d", static_cast<int>(t));
  return buffer;
}