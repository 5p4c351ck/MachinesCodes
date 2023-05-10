#include <ESP32Servo.h>
 
Servo myservo;

 
int pos = 0;
int servoPin = 13;
int val;
int angle = 90;
void setup() {
  Serial.begin(115200);
	ESP32PWM::allocateTimer(0);
	ESP32PWM::allocateTimer(1);
	ESP32PWM::allocateTimer(2);
	ESP32PWM::allocateTimer(3);
	myservo.setPeriodHertz(50);
	myservo.attach(servoPin);
  myservo.write(angle);
}
 
void loop() {

val = analogRead(34);
Serial.println(val);
if (val == 0){
 angle = 180;
}
if (val == 4095){
 angle = 0;
}
myservo.write(angle);
angle = 90;
delay(50);
}
