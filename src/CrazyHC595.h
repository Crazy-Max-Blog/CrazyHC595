#include <Arduino.h>

#include "GyverIO.h"

class CrazyHC595 {
public:
  CrazyHC595(byte dataPin, byte latchPin, byte clockPin) {
    _dPin  = dataPin;
    _lPin = latchPin;
    _cPin = clockPin;
    pinMode(_dPin, OUTPUT);
    pinMode(_lPin, OUTPUT);
    pinMode(_cPin, OUTPUT);
  }

  void update() {
    gio::low(_lPin);
    gio::shift::send_byte(_dPin, _cPin, LSBFIRST, buf);
    gio::high(_lPin);
  }

  void send_byte(byte data) {
    buf=data;
    update();
  }

  void write_pin(byte pin, bool value) {
    buf^=(value?bit(7-pin):0);
    update();
  }

  void clear() {
    send_byte(0x00);
  }

  bool get_pin(byte pin) {
    return bitRead(buf, pin);
  }

  // VARS
  byte buf=0b00000000; // buffer

protected:
  
private:
  byte _dPin, _lPin, _cPin;
};
