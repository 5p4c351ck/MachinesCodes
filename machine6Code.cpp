#if defined(ARDUINO_ESP32S2_DEV)
const int lowestPin = 1;
const int highestPin = 42;
#else
const int lowestPin = 2;
const int highestPin = 33;
#endif
#include <ESP32Servo.h>
Servo myservo;
int angle;
void setup() {
	Serial.begin(115200);
    ESP32PWM::allocateTimer(0);
	ESP32PWM::allocateTimer(1);
	ESP32PWM::allocateTimer(2);
	ESP32PWM::allocateTimer(3);
  myservo.attach(14);
  angle = 0;
  myservo.write(angle);
}

void loop() {
    delay(10000);
    for(;angle < 55; angle++){
      	myservo.write(angle);
        delay(5);
    }
    delay(25000);
    for (;angle > 0; angle--){
      myservo.write(angle);
      delay(5);
    }
}
