void avoidObstacle() {
  distance = getUltrasonicDistance();

  if (distance > obstacleDistance) {
    // No obstacle ahead, keep moving forward
    moveForward();
  } else {
    // Obstacle detected, turn right to avoid
    turnRight();
    delay(500); // Adjust this delay to control the turning angle
    moveForward();
    delay(1000); // Adjust this delay to control the duration of avoiding
  }
}

float getUltrasonicDistance() {
  // Trigger the ultrasonic sensor and measure the echo duration to calculate distance
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  float duration = pulseIn(echoPin, HIGH);
  return duration * 0.0343 / 2; // Speed of sound in air is approximately 343 m/s
}
