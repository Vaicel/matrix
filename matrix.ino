#include <SPI.h>
#define SS_PIN 10


void setup() {
  SPI.begin();
  pinMode(SS_PIN, OUTPUT);
}

byte mosinloh[8]{
  0b00011000,
  0b00100100,
  0b01100110,
  0b10011001,
  0b10011001,
  0b01100110,
  0b00100100,
  0b00011000,
};

void loop() {
  for(int row = 0; row < 8; row++) {
    digitalWrite(SS_PIN,LOW);
    SPI.transfer(0xFF - (1<<row));
    SPI.transfer(mosinloh[row]);
    digitalWrite(SS_PIN,HIGH);
    delay(1);
  }
}
