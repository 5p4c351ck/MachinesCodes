#include <Servo.h>

int left = 4;
int right = 5;
int up = 7;
int down = 6;
int udv = 0;
int lrv = 0;
Servo udservo;
Servo lrservo;
Servo clawservo;

void setup() {
    pinMode(down, INPUT_PULLUP);
    pinMode(up, INPUT_PULLUP);
    pinMode(right, INPUT_PULLUP);
    pinMode(left, INPUT_PULLUP);

    udservo.attach(3);
    lrservo.attach(2);
    clawservo.attach(13);
    
}
void loop() {
if (digitalRead(down) == LOW && (udv > 0)){     
    udv -= 7;
    udservo.write(udv);
}
else if (digitalRead(up) == LOW && (udv < 180)){ 
    udv += 7;
    udservo.write(udv);
}


else if (digitalRead(right) == LOW && (lrv > 0)){
    lrv -= 7;
    lrservo.write(lrv);
}
else if (digitalRead(left) == LOW && (lrv < 180)){
    lrv += 7;
    lrservo.write(lrv);
}

int PotValue = analogRead(A0);
int ClawServoValue = map(PotValue, 0, 1023, 0, 180);
clawservo.write(ClawServoValue);

delay(30);
}