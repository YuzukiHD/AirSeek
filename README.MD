# AirSeek
一个气象台

需要PlatformIO IDE进行编译安装

```
Executing task: platformio.exe run --target upload <

Processing nanoatmega328 (platform: atmelavr; board: nanoatmega328; framework: arduino)
--------------------------------------------------------------------------------------------------------------------------------------------------

Verbose mode can be enabled via `-v, --verbose` option
CONFIGURATION: https://docs.platformio.org/page/boards/atmelavr/nanoatmega328.html
PLATFORM: Atmel AVR 2.0.0 > Arduino Nano ATmega328
HARDWARE: ATMEGA328P 16MHz, 2KB RAM, 30KB Flash
PACKAGES: toolchain-atmelavr 1.50400.190710 (5.4.0), framework-arduino-avr 5.0.0, tool-avrdude 1.60300.190424 (6.3.0)
LDF: Library Dependency Finder -> http://bit.ly/configure-pio-ldf
LDF Modes: Finder ~ chain, Compatibility ~ soft
Found 8 compatible libraries
Scanning dependencies...
Dependency Graph
|-- <LCD12864RSPI>
|-- <DHT>
|-- <DS1302>
Building in release mode
Compiling .pio\build\nanoatmega328\src\main.cpp.o
Linking .pio\build\nanoatmega328\firmware.elf
Checking size .pio\build\nanoatmega328\firmware.elf
Building .pio\build\nanoatmega328\firmware.hex
Advanced Memory Usage is available via "PlatformIO Home > Project Inspect"
DATA:    [==        ]  15.7% (used 322 bytes from 2048 bytes)
PROGRAM: [===       ]  28.9% (used 8864 bytes from 30720 bytes)
Configuring upload protocol...
AVAILABLE: arduino
CURRENT: upload_protocol = arduino
Looking for upload port...
Auto-detected: COM5
Uploading .pio\build\nanoatmega328\firmware.hex

avrdude: AVR device initialized and ready to accept instructions

Reading | ################################################## | 100% 0.00s

avrdude: Device signature = 0x1e950f (probably m328p)
avrdude: reading input file ".pio\build\nanoatmega328\firmware.hex"
avrdude: writing flash (8864 bytes):

Writing | ################################################## | 100% 2.56s

avrdude: 8864 bytes of flash written
avrdude: verifying flash memory against .pio\build\nanoatmega328\firmware.hex:
avrdude: load data flash data from input file .pio\build\nanoatmega328\firmware.hex:
avrdude: input file .pio\build\nanoatmega328\firmware.hex contains 8864 bytes
avrdude: reading on-chip flash data:

Reading | ################################################## | 100% 1.92s

avrdude: verifying ...
avrdude: 8864 bytes of flash verified

avrdude: safemode: Fuses OK (E:00, H:00, L:00)

avrdude done.  Thank you.

```