unsigned char* CH2OSTR = (unsigned char*)"CH2O:";

int ch2o_mod() {
  static int val;
  val = analogRead(4);
  val = val / 10;
  return val;
}