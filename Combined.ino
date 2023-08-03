// Libraries
#include <NewPing.h>

// Pin Definitions
const int sensorLeftPin = A0;
const int sensorRightPin = A1;
const int trigPin = 2;
const int echoPin = 3;
const int leftMotorForwardPin = 4;
const int leftMotorReversePin = 5;
const int rightMotorForwardPin = 6;
const int rightMotorReversePin = 7;

// Constants
const int threshold = 500; // Adjust this threshold based on your sensor readings
const int obstacleDistance = 20; // Adjust this distance based on your needs

// Objects
NewPing sonar(trigPin, echoPin);

// Enum for robot modes
enum Mode {
  LINE_FOLLOW,
  AVOID_OBSTACLE
};
Mode currentMode = LINE_FOLLOW;

void setup() {
  pinMode(sensorLeftPin, INPUT);
  pinMode(sensorRightPin, INPUT);
  pinMode(leftMotorForwardPin, OUTPUT);
  pinMode(leftMotorReversePin, OUTPUT);
  pinMode(rightMotorForwardPin, OUTPUT);
  pinMode(rightMotorReversePin, OUTPUT);

  // Start in line following mode
  currentMode = LINE_FOLLOW;
}

void loop() {
  switch (currentMode) {
    case LINE_FOLLOW:
      lineFollow();
      break;
    case AVOID_OBSTACLE:
      avoidObstacle();
      break;
    // You can add more modes and conditions based on your requirements
    default:
      // Default to line following if no specific mode is defined
      lineFollow();
  }
}

void lineFollow() {
  int sensorLeftValue = analogRead(sensorLeftPin);
  int sensorRightValue = analogRead(sensorRightPin);

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

void avoidObstacle() {
  float distance = getUltrasonicDistance();

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
  unsigned int duration = sonar.ping_median();
  return duration * 0.0343 / 2; // Speed of sound in air is approximately 343 m/s
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
