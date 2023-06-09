#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>



RF24 radio(7, 8);
const byte addresses[][6] = {"00001", "00002"};
Servo myServo;



void setup() {

  myServo.attach(5);
  radio.begin();
  radio.openWritingPipe(addresses[0]);
  radio.openReadingPipe(1, addresses[1]);
  radio.setPALevel(RF24_PA_MIN);
}
void loop() {
  delay(5);
  radio.startListening();
  if ( radio.available()) 
{
    while (radio.available()) 
{
      int angleV = 0;
      radio.read(&angleV, sizeof(angleV));
      myServo.write(angleV);
    }
  }
}
