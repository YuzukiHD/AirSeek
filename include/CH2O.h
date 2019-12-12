#include "pin.h"
unsigned char* CH2OSTR = (unsigned char*)"CH2O:";

int ch2o_mod() {
  static int val;
  val = analogRead(CH2O);
  val = val / 10;
  return val;
}