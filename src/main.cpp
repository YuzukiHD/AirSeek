#include <Arduino.h>
#include "12864.h"
#include "DHT11.h"
#include "MQ135.h"
#include "time1302.h"

void setup() {
  dht.begin();         // 初始化DHT模块
  LCDA.Initialise();   // 初始化LCD模块
  Serial.begin(9600);  // 定义串口波特率
  LCDA.CLEAR();        // 清屏
  // rtc.setDOW(SUNDAY);        // Set Day-of-Week to FRIDAY
  // rtc.setTime(23, 27, 0);    // Set the time to 12:00:00 (24hr format)
  // rtc.setDate(8, 12, 2019);  // Set the date to August 6th, 2010
}

void loop() {
  LCDA.CLEAR();  // 清屏

  double h = dht.readHumidity();
  double t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    delay(1000);
    return;
  }

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("% Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.println("");
  Serial.println(mq135());

  LCDA.DisplayString(0, 0, clock, 2);

  unsigned char* dateStr = (unsigned char*)getMDStr();
  LCDA.DisplayString(1, 0, dateStr, 5);

  unsigned char* timeStr = (unsigned char*)rtc.getTimeStr();
  LCDA.DisplayString(0, 4, timeStr, 8);

  LCDA.DisplayString(1, 0, TEMPCHAR, AR_SIZE(TEMPCHAR));
  LCDA.DisplayString(1, 2, (unsigned char*)i2c(t), AR_SIZE(i2c(t)));
  LCDA.DisplayString(1, 4, HUMCHAR, AR_SIZE(HUMCHAR));
  LCDA.DisplayString(1, 6, (unsigned char*)i2c(h), AR_SIZE(i2c(h)));

  LCDA.DisplayString(2, 0, MQNH3, 3);
  LCDA.DisplayString(2, 2, (unsigned char*)i2c(mq135()), 2);

  delay(1000);
}