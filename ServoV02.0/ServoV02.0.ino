
#include <Servo.h>
Servo myServo;        // Create Servo object to control the servo 

void setup() { 
  myServo.attach(7);  // Servo is connected to digital pin 7
} 

void loop() { 
  myServo.writeMicroseconds(1700);  // Counter clockwise
  delay(1000);                      // Wait 2 seconds
  myServo.writeMicroseconds(1500);  // Stop
  delay(1000); 
  myServo.writeMicroseconds(1300);  // Clockwise
  delay(1000);
  myServo.writeMicroseconds(1500);  // Stop
  delay(2000); 
}

void armMove() {
  armServo.writeMicroseconds(1700);//Counter-clockwise
  delay(1000);
  armServo.writeMicroseconds(1500);//Stop
  delay(1000);
  armServo.writeMicroseconds(1300);//Clockwise
  delay(1000);
  armServo.writeMicroseconds(1500);//Stop
}

