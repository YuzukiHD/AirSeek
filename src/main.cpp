#include <Arduino.h>
#include "12864.h"
#include "DHT11.h"
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
  unsigned char* timeStr = (unsigned char*)rtc.getTimeStr();
  LCDA.DisplayString(0, 0, timeStr, 8);

  unsigned char* dateStr = (unsigned char*)getMDStr();
  LCDA.DisplayString(0, 5, dateStr, 5);

  LCDA.DisplayString(1, 0, TEMPCHAR, AR_SIZE(TEMPCHAR));
  LCDA.DisplayString(1, 2, (unsigned char*)i2c(t), AR_SIZE(i2c(t)));
  LCDA.DisplayString(1, 4, HUMCHAR, AR_SIZE(HUMCHAR));
  LCDA.DisplayString(1, 6, (unsigned char*)i2c(h), AR_SIZE(i2c(h)));

  delay(1000);
}