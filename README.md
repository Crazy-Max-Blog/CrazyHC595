[![latest](https://img.shields.io/github/v/release/Crazy-Max-Blog/CrazyHC595.svg?color=brightgreen)](https://codeload.github.com/Crazy-Max-Blog/CrazyHC595/zip/refs/heads/main)

[![Foo](https://img.shields.io/badge/ПОДПИСАТЬСЯ-НА%20ОБНОВЛЕНИЯ-brightgreen.svg?style=social&logo=telegram&color=blue)](https://t.me/CrazyLibs_updates)

# CrazyHC595
Библиотека для сдвигового регистра 74HC595

## Содержание
- [Установка](#установка)
- [Подключение](#подключение)
- [Инициализация](#инициализация)
- [Использование](#использование)
- [Пример](#пример)
- [Версии](#версии)
- [Баги и обратная связь](#баги%20и%20обратная%20связь)

## Установка
- Библиотеку можно найти по названию **CrazyHC595** и установить через менеджер библиотек в:
    - Arduino IDE
    - Arduino IDE v2
    - PlatformIO
- [Скачать библиотеку](https://codeload.github.com/Crazy-Max-Blog/CrazyHC595/zip/refs/heads/main) .zip архивом для ручной установки:
    - Распаковать и положить в *C:\Program Files (x86)\Arduino\libraries* (Windows x64)
    - Распаковать и положить в *C:\Program Files\Arduino\libraries* (Windows x32)
    - Распаковать и положить в *Документы/Arduino/libraries/*
    - (Arduino IDE) автоматическая установка из .zip: *Скетч/Подключить библиотеку/Добавить .ZIP библиотеку…* и указать скачанный архив

## Подключение
### Общая схема
![scheme](/doc/scheme.png)

### Один чип
- Q0.. Q7 - управляемые выходы
- VCC/GND - питание
- MR - потключить к **VCC**
- OE - потключить к **GND**
- DS - вход данных, **dataPin**
- STCP - chip select, **latchPin**
- SHCP - вход тактирования, **clockPin**
- Q7S - выход данных (никуда не подключен, если чип один)

### Каскад
Можно соединить несколько микросхем 74HC595 "каскадом":
- Пины SHCP, STCP, VCC, GND, а также OE и MR подключаются параллельно у всех микросхем
- Вход данных DS *первой микросхемы* подключается к выходу данных с микроконтроллера (пин DT/MOSI)
- Пин Q7S *первой микросхемы* подключается к DS второй микросхемы, и так далее по цепочке

## Инициализация
```cpp
Crazy74HC595 hc(dataPin, latchPin, clockPin);//создание экземпляра с названием hc и пинами dataPin, latchPin, clockPin
CrazyHC595(byte dataPin, byte latchPin, byte clockPin) //конструктор с пинами dataPin, latchPin, clockPin
```

## Использование
```cpp
// методы
void update()                        // отправить данные из буфера на дисплей
void send_byte(byte data)            // отправить байт на дисплей (например send_byte(0x10101010))
void write_pin(byte pin, bool value) // установить значение на определённый пин
void clear()                         // очистить всё
bool get_pin(byte pin)               // получить значение с указанного пина

// переменные
byte buf=0b00000000;                 // буфер
```

## Пример
Остальные примеры смотри в **examples**!
```cpp
#include <GyverHC595.h>

GyverHC595<2, HC_SPI, 8000000> reg(10); // аппаратный SPI, кастомная скорость
//GyverHC595<2, HC_PINS> reg(10, 11, 13); // программный SPI (bit bang)

void setup() {
  reg.set(0);       // включить пин 0
  reg.write(8, 1);  // включить пин 8
  reg.write(8, 0);  // выключить пин 8
  
  reg.update();     // обновить
}

void loop() {
}
```

## Версии
- v0.1 - поехали
- 
## Баги и обратная связь
При нахождении багов создавайте **Issue**, а лучше сразу пишите на почту [alex@alexgyver.ru](mailto:alex@alexgyver.ru)  
Библиотека открыта для доработки и ваших **Pull Request**'ов!
