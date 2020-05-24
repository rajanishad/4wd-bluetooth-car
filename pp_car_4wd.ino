#include <AFMotor.h>
AF_DCMotor right_motor1(1,MOTOR12_64KHZ);
AF_DCMotor left_motor1(2, MOTOR12_64KHZ);
AF_DCMotor right_motor2(4,MOTOR12_64KHZ);
AF_DCMotor left_motor2(3, MOTOR12_64KHZ);

String readString;

void setup() {
  Serial.begin(9600);
  right_motor1.setSpeed(255);
  left_motor1.setSpeed(255);
    right_motor2.setSpeed(255);
  left_motor2.setSpeed(255);
}

void loop() {
  while(Serial.available()){
    delay(50);
    char c=Serial.read();
    readString+=c;
  }
  if(readString.length()>0){
    Serial.println(readString);
    if (readString =="FORWARD"){
      right_motor1.run (FORWARD);
      left_motor1.run (FORWARD);
            right_motor2.run (FORWARD);
      left_motor2.run (FORWARD);
      delay(500);
    }
    if (readString =="BACKWARD"){
      right_motor1.run (BACKWARD);
      left_motor1.run (BACKWARD);
            right_motor2.run (BACKWARD);
      left_motor2.run (BACKWARD);
      delay(500);
    }
    if (readString =="LEFT"){
      right_motor1.run (FORWARD);
      left_motor1.run (BACKWARD);
            right_motor2.run (FORWARD);
      left_motor2.run (BACKWARD);
      delay(500);
    }
    if (readString =="RIGHT"){
      right_motor1.run (BACKWARD);
      left_motor1.run (FORWARD);
            right_motor2.run (BACKWARD);
      left_motor2.run (FORWARD);
      delay(500);
    }
    if (readString =="STOP"){
      right_motor1.run (RELEASE);
      left_motor1.run (RELEASE);
            right_motor2.run (RELEASE);
      left_motor2.run (RELEASE);
      delay(500);
    }

    readString="";
  }
}
