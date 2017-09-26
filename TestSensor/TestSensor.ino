int voltageFlipPin1 = 3;
int voltageFlipPin2 = 4;
int sensorPin = A0;
int flipTimer = 1000;//1 sec

void setup() {
  pinMode(voltageFlipPin1, OUTPUT);
  pinMode(voltageFlipPin2, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
} 

void loop() { 
  readSoil();
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
}

