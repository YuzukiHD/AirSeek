unsigned char* MQNH3 = (unsigned char*)"NH3:";

int mq135() {
  static int val;
  val = analogRead(1);
  val = val / 10;
  return val;
}