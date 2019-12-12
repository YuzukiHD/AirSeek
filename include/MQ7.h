#include "pin.h"

unsigned char* MQCO = (unsigned char*)"CO :";

int mq7() {
  static int val;
  val = analogRead(MQ7);
  val = val / 10;
  return val;
}