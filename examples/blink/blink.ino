#include <CrazyHC595.h>

//Crazy74HC595 hc(dataPin, latchPin, clockPin);// создание экземпляра с названием hc и пинами dataPin, latchPin, clockPin
CrazyHC595 hc(2,3,4);

void setup() {
  Serial.begin(115200);
}

void loop() {
  // Async blink
  static long timer;
  if(millis()-timer>=100) {
    timer=millis();
    hc.write_pin(0, !hc.get_pin(0));
  }
  
  //  Sync blink
  //hc.write_pin(0, HIGH);
  //delay(100);
  //hc.write_pin(0, LOW);
  //delay(100);
}
