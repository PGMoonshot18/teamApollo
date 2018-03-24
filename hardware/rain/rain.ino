const int sensorMin = 0;     // sensor minimum
const int sensorMax = 1024;  // sensor maximum
int redPin = 9;
int greenPin = 10;
int yellowPin = 11;
int stat = 0;
float timer = 0;
int current = 0;
float masterList[3][2];

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(yellowPin, LOW);
}

void loop() {
  int sensorReading = analogRead(A0);
  Serial.println(sensorReading);
  if ((stat == 0) && (sensorReading <= 500)) {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, LOW);
    stat = 1;
    masterList[current][0] = timer;
  }
  else if ((stat == 1) && (sensorReading <= 160)) {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, HIGH);
    stat = 2;
    masterList[current][2] = timer;
  }
  else if ((stat == 2) && (sensorReading <= 180) && (masterList[current][1] - masterList[current][2] >= 3)) {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(yellowPin, LOW);
  }
  else if (((masterList[current][1] - masterList[current][2] >= 10) && (stat == 2)) || ((masterList[current][1] - masterList[current][0] >= 10) && (stat == 1))) {
//    for (int i = 0; i < 3; i++) {
//      Serial.println(masterList[current][i]);
//    }
    current = current + 1;
    stat = 0;
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, LOW);
  }
  delay(100);
  timer = timer + 0.1;
  masterList[current][1] = timer;
}

