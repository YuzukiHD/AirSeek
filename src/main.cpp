#include <Arduino.h>
#include "12864.h"
#include "CH2O.h"
#include "DHT11.h"
#include "MQ135.h"
#include "MQ7.h"
#include "time1302.h"

// LOGGER记录器
void logger(char* time, double h, double t, int nh3, int co, int ch2o) {
  Serial.print(time);
  Serial.print(F(" Humidity: "));
  Serial.print(h);
  Serial.print(F("% Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(F(" NH3: "));
  Serial.print(nh3);
  Serial.print(F(" CO: "));
  Serial.print(co);
  Serial.print(F(" CH2O: "));
  Serial.print(ch2o);
  Serial.println("");
}

void setup() {
  dht.begin();         // 初始化DHT模块
  LCDA.Initialise();   // 初始化LCD模块
  Serial.begin(9600);  // 定义串口波特率
  LCDA.CLEAR();        // 清屏

  // pinMode(10, OUTPUT);  // 输出LED R
  // pinMode(11, OUTPUT);  // 输出LED G
  // pinMode(12, OUTPUT);  // 输出LED B
  
  // 设置时间
  // rtc.setDOW(MONDAY);        // Set Day-of-Week to FRIDAY
  // rtc.setTime(22, 25, 0);    // Set the time to 12:00:00 (24hr format)
  // rtc.setDate(9, 12, 2019);  // Set the date to August 6th, 2010
}

void loop() {
  LCDA.CLEAR();  // 清屏

  double h = dht.readHumidity();     // 读取湿度
  double t = dht.readTemperature();  // 读取温度
  int nh3 = mq135();                 // 读取氨气
  int co = mq7();                    // 读取一氧化碳
  int ch2o = ch2o_mod();             // 读取甲醛
  char* time = rtc.getTimeStr();

  // 判断DHT模块是否存活
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    delay(1000);
    return;
  }

  logger(time, h, t, nh3, co, ch2o);

  // 输出日期与时间
  unsigned char* dateStr = (unsigned char*)getMDStr();
  LCDA.DisplayString(0, 0, dateStr, 5);
  unsigned char* timeStr = (unsigned char*)time;
  LCDA.DisplayString(0, 4, timeStr, 8);

  // 输出温度与湿度
  LCDA.DisplayString(1, 0, TEMPCHAR, AR_SIZE(TEMPCHAR));
  LCDA.DisplayString(1, 2, (unsigned char*)i2c(t), AR_SIZE(i2c(t)));
  LCDA.DisplayString(1, 4, HUMCHAR, AR_SIZE(HUMCHAR));
  LCDA.DisplayString(1, 6, (unsigned char*)i2c(h), AR_SIZE(i2c(h)));

  // 输出空气质量：氨气，一氧化碳
  LCDA.DisplayString(2, 0, MQNH3, 4);
  LCDA.DisplayString(2, 2, (unsigned char*)i2c(nh3), 2);
  LCDA.DisplayString(2, 4, MQCO, 4);
  LCDA.DisplayString(2, 6, (unsigned char*)i2c(co), 2);

  // 输出甲醛
  LCDA.DisplayString(3, 0, CH2OSTR, 6);
  LCDA.DisplayString(3, 4, (unsigned char*)i2c(ch2o), 2);

  // 等待一秒
  delay(1000);
}