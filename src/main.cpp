#include <Arduino.h>
#include <DHT.h>

// 温湿度传感器定义&初始化
#define DHTPIN 3
#define DHTYPE DHT11
DHT dht(DHTPIN, DHTYPE);

void setup() {
  dht.begin();         //  初始化DHT模块
  Serial.begin(9600);  //  定义串口波特率
}

void loop() {
  int h = dht.readHumidity();
  int t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("% Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.println("");
  delay(1000);
}