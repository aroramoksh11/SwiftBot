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
