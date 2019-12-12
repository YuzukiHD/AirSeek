#include <DHT.h>
#include "pin.h"

// 温湿度传感器定义&初始化
#define DHTYPE DHT11
DHT dht(DHTDATA, DHTYPE);