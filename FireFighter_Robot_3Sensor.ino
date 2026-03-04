// --- Motor Control Pins ---
const int ENA = 11; // Speed Left
const int IN1 = 10;
const int IN2 = 9;
const int IN3 = 7;
const int IN4 = 6;
const int ENB = 5;  // Speed Right

// --- Sensor Pins ---
const int flameLeft   = 13;
const int flameCenter = 12;
const int flameRight  = 8; // Adjusted from 12 to 8 to avoid conflict

// --- Pump Pin ---
const int pump = 4; 

// Logic: Most sensors are LOW when they detect fire
int fire = LOW; 

void setup() {
  pinMode(ENA, OUTPUT); pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT); pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);
  pinMode(pump, OUTPUT);
  
  pinMode(flameLeft, INPUT);
  pinMode(flameCenter, INPUT);
  pinMode(flameRight, INPUT);

  // Set speed (0-255)
  analogWrite(ENA, 200); 
  analogWrite(ENB, 200);
}

void loop() {
  int L = digitalRead(flameLeft);
  int C = digitalRead(flameCenter);
  int R = digitalRead(flameRight);

  if (C == fire) {
    // Fire is directly in front
    stopRobot();
    digitalWrite(pump, HIGH); 
  } 
  else if (L == fire) {
    // Fire is to the left
    digitalWrite(pump, LOW);
    turnLeft();
  } 
  else if (R == fire) {
    // Fire is to the right
    digitalWrite(pump, LOW);
    turnRight();
  } 
  else {
    // No fire detected
    stopRobot();
    digitalWrite(pump, LOW);
  }
}

void turnLeft() {
  digitalWrite(IN1, LOW);  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}

void turnRight() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);  digitalWrite(IN4, HIGH);
}

void stopRobot() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
}
