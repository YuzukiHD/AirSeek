#include <DS1302.h>
#include "pin.h"

DS1302 rtc(RTCRST, RTCDAT, RTCCLK);

unsigned char clock[] = {};

char* getMDStr() {
  static char buffer[10];
  Time t = rtc.getTime();
  int timeMon = (int)t.mon;
  int timeDay = (int)t.date;
  sprintf(buffer, "%d%s%d", timeMon, "-", timeDay);
  return buffer;
}