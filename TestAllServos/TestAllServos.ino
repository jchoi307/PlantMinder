
#include <Servo.h>
Servo armServo;        // Create Servo object to control the servo 
Servo valveServo;
int counterClockwise = 1700;
int clockwise = 1300;
int stopping = 1500;

void setup() { 
  armServo.attach(6);  // Servo is connected to digital pin 6
  valveServo.attach(7); //Servo connected to pin 7
  Serial.begin(9600);
} 

void loop() { 
  delay(3000);
  armServo.writeMicroseconds(counterClockwise);//ARM COUNTER
  delay(300);
  armServo.writeMicroseconds(stopping);//ARM STOPPED
  delay(2000);
  //Turn on valve
  valveServo.writeMicroseconds(clockwise);//VALVE ON
  delay(500);
  valveServo.writeMicroseconds(stopping);//VALVE STOPPED
  delay(5000);//CHANGE THIS TO ALLOW WATER FLOW
  valveServo.writeMicroseconds(counterClockwise);//VALVE OFF
  delay(525);
  valveServo.writeMicroseconds(stopping);//VALVE STOPPED
  delay(5000);
  armServo.writeMicroseconds(clockwise);//ARM CLOCK
  delay(300);
  armServo.writeMicroseconds(stopping);//ARM STOPPED
  delay(3000);//CAN REMOVE ONCE EVERYTHING WORKS
}

