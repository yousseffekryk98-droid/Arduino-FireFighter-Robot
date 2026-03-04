// --- Motor Pins (L298N) ---
const int IN1 = 2; 
const int IN2 = 3;
const int IN3 = 4;
const int IN4 = 5;

// --- Sensor Pins ---
const int leftFlame = A0;  // Left Flame Sensor
const int rightFlame = A1; // Right Flame Sensor

// --- Pump Pin ---
const int pump = 13; 

// Change this based on your sensor (Digital vs Analog)
// If using Digital pins, fire is usually LOW (0)
int fireDetected = LOW; 

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(pump, OUTPUT);
  
  pinMode(leftFlame, INPUT);
  pinMode(rightFlame, INPUT);
  
  digitalWrite(pump, LOW); // Ensure pump is off at start
}

void loop() {
  int leftVal = digitalRead(leftFlame);
  int rightVal = digitalRead(rightFlame);

  if (leftVal == fireDetected && rightVal == fireDetected) {
    // Fire is right in front
    stopRobot();
    activatePump();
  } 
  else if (leftVal == fireDetected) {
    // Fire is to the left
    turnLeft();
    digitalWrite(pump, LOW);
  } 
  else if (rightVal == fireDetected) {
    // Fire is to the right
    turnRight();
    digitalWrite(pump, LOW);
  } 
  else {
    // No fire detected - remain idle
    stopRobot();
    digitalWrite(pump, LOW);
  }
}

// --- Movement Functions ---

void moveForward() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
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

void activatePump() {
  digitalWrite(pump, HIGH);
  delay(500); // Spray for half a second
}
