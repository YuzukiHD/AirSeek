unsigned char* MQCO = (unsigned char*)"CO :";

int mq7() {
  static int val;
  val = analogRead(2);
  val = val / 10;
  return val;
}