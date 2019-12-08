#include <Arduino.h>
#include "12864.h"
#include "DHT11.h"

void setup() {
  dht.begin();         // 初始化DHT模块
  LCDA.Initialise();   // 初始化LCD模块
  Serial.begin(9600);  // 定义串口波特率
  LCDA.CLEAR();        // 清屏
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

  LCDA.DisplayString(0, 0, TEMPCHAR, AR_SIZE(TEMPCHAR));
  LCDA.DisplayString(0, 3, (unsigned char*)temp(t), AR_SIZE(temp(t)));
  LCDA.DisplayString(0, 4, CCHAR, AR_SIZE(CCHAR));
  delay(1000);
}