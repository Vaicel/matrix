/*
 * Распиновка модуля (сверху вниз)
 * VCC
 * MOSI - D11
 * SS - D10
 * SCK - D13
 * GND
*/

#include <SPI.h>
#define SS_PIN 10


void setup() {
  SPI.begin();
  pinMode(SS_PIN, OUTPUT);
}

int shift=0, timer=0, timerPrev=0, len=19;

byte flower[]{
  0b00000000,
  0b00011000,
  0b00100100,
  0b01100110,
  0b10011001,
  0b10011001,
  0b01100110,
  0b00100100,
  0b00011000,
  0b00000000,
  0b00011000,
  0b00100100,
  0b01100110,
  0b10011001,
  0b10011001,
  0b01100110,
  0b00100100,
  0b00011000,
  0b00000000,
};

void loop() {

  timer = millis();                 
  if (timer-timerPrev>80){
    shift++;                        
    if (shift==len-10)shift=0;
    timerPrev=timer;
  }

  for(int col = 0; col < 8; col++) {
    digitalWrite(SS_PIN,LOW);
    SPI.transfer(0xFF-flower[col+shift]);
    SPI.transfer(1<<(col));
    digitalWrite(SS_PIN,HIGH);
    delay(1);
  }

}
