#include <DHT.h>

// 温湿度传感器定义&初始化
#define DHTPIN 3
#define DHTYPE DHT11
DHT dht(DHTPIN, DHTYPE);