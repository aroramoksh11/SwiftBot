void setup() {
  pinMode(sensorLeftPin, INPUT);
  pinMode(sensorRightPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(leftMotorForwardPin, OUTPUT);
  pinMode(leftMotorReversePin, OUTPUT);
  pinMode(rightMotorForwardPin, OUTPUT);
  pinMode(rightMotorReversePin, OUTPUT);
  
  // Start in line following mode
  currentMode = LINE_FOLLOW;
}
