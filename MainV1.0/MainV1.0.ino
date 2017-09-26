
#include <Servo.h>
Servo armServo;        // Create Servo object to control the servo 
Servo valveServo;
int counter = 0;
int avg = 0;
int voltageFlipPin1 = 3;
int voltageFlipPin2 = 4;
int sensorPin = A0;
int flipTimer = 1000;//1 sec
int counterClockwise = 1700;
int clockwise = 1300;
int stopping = 1500;

void setup() { 
  armServo.attach(6);  // Servo is connected to digital pin 6
  valveServo.attach(7); //Servo connected to pin 7
  pinMode(voltageFlipPin1, OUTPUT);
  pinMode(voltageFlipPin2, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
} 

void loop() { 
  if(counter != 5) {
    avg += readSoil();
    Serial.println(avg);
    counter = counter + 1;
  } else {
    avg = avg / 5;
    Serial.println("Taking avg");
    Serial.println(avg);
    if(avg > 240) {
      Serial.println("DRY");
      //////////////////NOT WET/////////////////////
      //Turn Arm to be over the plant
      armServo.writeMicroseconds(counterClockwise);
      delay(500);
      armServo.writeMicroseconds(stopping);
      delay(2000);
      //Turning on the valve
      valveServo.writeMicroseconds(clockwise);
      delay(600);
      valveServo.writeMicroseconds(stopping);
      delay(3000);//CHANGE THIS TO ALLOW WATER FLOW
      //Turning off the valve
      valveServo.writeMicroseconds(counterClockwise);
      delay(625);
      valveServo.writeMicroseconds(stopping);
      delay(5000); //Wait for water to drain out
      //Turn Arm to waiting position
      armServo.writeMicroseconds(clockwise);
      delay(500);
      armServo.writeMicroseconds(stopping);
      counter = 0;
      avg = 0;
    } else {
      Serial.println("WET");
      //WET So do nothing? 
      //May not need this else statement
      counter = 0;
      avg = 0;
    }
  }
}

void setSensorPolarity(boolean flip) {
  if(flip) {
    digitalWrite(voltageFlipPin1, HIGH);
    digitalWrite(voltageFlipPin2, LOW);
  } else {
    digitalWrite(voltageFlipPin1, LOW);
    digitalWrite(voltageFlipPin2, HIGH);
  }
}

int reportLevels(int val1, int val2) {
  int avg = (val1 + val2) / 2;
  String msg = "avg: ";
  msg += avg;
  Serial.println(msg);
  return avg;
}

int readSoil() {
  setSensorPolarity(true);
  delay(flipTimer);
  int val1 = analogRead(sensorPin);
  delay(flipTimer);
  setSensorPolarity(false);
  delay(flipTimer);
  //invert the reading
  int val2 = 1023 - analogRead(sensorPin);

  int reading = reportLevels(val1, val2);
  return reading;
}

