#include <Servo.h>

#define ServoPin 3  
#define a 9         
Servo MyServo1; 
Servo MyServo2; 
void setup()
{
 MyServo1.attach(ServoPin);
 MyServo2.attach(a); 
  
}
void loop()
{
  int PotValue1 = analogRead(A0);
  int PotValue2 = analogRead(A5);
  int ServoValue1 = map(PotValue1, 0, 1023, 0, 180);
  int ServoValue2 = map(PotValue2, 0, 1023, 0, 180);
  
  MyServo1.write(ServoValue1);
  MyServo2.write(ServoValue2);
 delay (100);
}