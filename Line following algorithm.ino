void lineFollow() {
  sensorLeftValue = analogRead(sensorLeftPin);
  sensorRightValue = analogRead(sensorRightPin);

  // Adjust motor speeds based on sensor readings
  if (sensorLeftValue > threshold && sensorRightValue > threshold) {
    // Both sensors on the line, move forward
    moveForward();
  } else if (sensorLeftValue > threshold) {
    // Only left sensor on the line, turn right
    turnRight();
  } else if (sensorRightValue > threshold) {
    // Only right sensor on the line, turn left
    turnLeft();
  } else {
    // Lost the line, stop
    stopMotors();
  }
}

void moveForward() {
  // Set motor directions to move forward
  digitalWrite(leftMotorForwardPin, HIGH);
  digitalWrite(leftMotorReversePin, LOW);
  digitalWrite(rightMotorForwardPin, HIGH);
  digitalWrite(rightMotorReversePin, LOW);
}

void turnLeft() {
  // Set motor directions to turn left
  digitalWrite(leftMotorForwardPin, LOW);
  digitalWrite(leftMotorReversePin, HIGH);
  digitalWrite(rightMotorForwardPin, HIGH);
  digitalWrite(rightMotorReversePin, LOW);
}

void turnRight() {
  // Set motor directions to turn right
  digitalWrite(leftMotorForwardPin, HIGH);
  digitalWrite(leftMotorReversePin, LOW);
  digitalWrite(rightMotorForwardPin, LOW);
  digitalWrite(rightMotorReversePin, HIGH);
}

void stopMotors() {
  // Stop both motors
  digitalWrite(leftMotorForwardPin, LOW);
  digitalWrite(leftMotorReversePin, LOW);
  digitalWrite(rightMotorForwardPin, LOW);
  digitalWrite(rightMotorReversePin, LOW);
}
