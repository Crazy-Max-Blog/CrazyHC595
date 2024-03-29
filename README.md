[![latest](https://img.shields.io/github/v/release/Crazy-Max-Blog/CrazyHC595.svg?color=brightgreen)](https://codeload.github.com/Crazy-Max-Blog/CrazyHC595/zip/refs/heads/main)
[![Foo](https://img.shields.io/badge/page-on%20website-blue.svg?style=flat-square)](https://crazymax.is-a.dev/CrazyHC595/)
[![Foo](https://img.shields.io/badge/page-on%20github-blue.svg?style=flat-square)](https://github.com/Crazy-Max-Blog/CrazyHC595/)

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
- [Баги и обратная связь](#баги-и-обратная-связь)

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

### Один чип
![scheme](/doc/scheme.png)

- Q0.. Q7 - управляемые выходы
- VCC/GND - питание
- MR - потключить к **VCC**
- OE - потключить к **GND**
- DS - вход данных, **dataPin**
- STCP - chip select, **latchPin**
- SHCP - вход тактирования, **clockPin**
- Q7S - выход данных (никуда не подключен, если чип один)

### Каскад
![scheme](/doc/scheme2.png)

Можно соединить несколько микросхем 74HC595 "каскадом":
- Пины SHCP, STCP, VCC, GND, а также OE и MR подключаются параллельно у всех микросхем
- Вход данных DS *первой микросхемы* подключается к выходу данных с микроконтроллера (пин DT/MOSI)
- Пин Q7S *первой микросхемы* подключается к DS второй микросхемы, и так далее по цепочке

## Инициализация
```cpp
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
#include <CrazyHC595.h>

CrazyHC595 hc(2,3,4);// создание экземпляра с названием hc и пинами по порядку: dataPin, latchPin, clockPin

void setup() {
  Serial.begin(115200);
}

void loop() {
  static long timer;
  if(millis()-timer>=100) {
    timer=millis();
    hc.write_pin(0, !hc.get_pin(0));
  }
}
```

## Версии
- v0.1 - поехали
- v0.1.1 - написана дока, исправлен баг с clear()

## Баги и обратная связь
При нахождении багов создавайте **Issue**, а лучше сразу пишите в коментариях под сообщением в [телеграм-канале](https://t.me/crazylibs_updates/6)
Библиотека открыта для доработки и ваших **Pull Request**'ов!
