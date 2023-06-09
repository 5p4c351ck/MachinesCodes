#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


RF24 radio(7, 8);
const byte addresses[][6] = {"00001", "00002"};
void setup() {

  radio.begin();
  radio.openWritingPipe(addresses[1]);
  radio.openReadingPipe(1, addresses[0]);
  radio.setPALevel(RF24_PA_MIN);
}
void loop() {
  delay(5);
  radio.stopListening();
  int potValue = analogRead(A0);
  int angleValue = map(potValue, 0, 1023, 0, 180);
  radio.write(&angleValue, sizeof(angleValue));
  delay(5);
}
