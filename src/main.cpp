#include <Arduino.h>

// Define motor pins
const int motorPin1 = 5;   // D5
const int motorPin2 = 18;  // D18
const int motorPin3 = 19;  // D19
const int motorPin4 = 21;  // D21

// Built-in LED pin
const int builtInLed = 2;  // Built-in LED pin

void moveForward() {
  digitalWrite(motorPin1, LOW);  // Left Backward
  digitalWrite(motorPin2, HIGH); // Left Forward
  digitalWrite(motorPin3, HIGH); // Right Forward
  digitalWrite(motorPin4, LOW);  // Right Backward
  Serial.println("Moving forward");

  // Blink the built-in LED 3 times
  for (int i = 0; i < 3; i++) {
    digitalWrite(builtInLed, HIGH);
    delay(200);
    digitalWrite(builtInLed, LOW);
    delay(200);
  }
}

void moveBackward() {
  digitalWrite(motorPin1, HIGH);  // Left Backward
  digitalWrite(motorPin2, LOW);   // Left Forward
  digitalWrite(motorPin3, LOW);   // Right Forward
  digitalWrite(motorPin4, HIGH);  // Right Backward
  Serial.println("Moving backward");

  // Blink the built-in LED 3 times
  for (int i = 0; i < 3; i++) {
    digitalWrite(builtInLed, HIGH);
    delay(200);
    digitalWrite(builtInLed, LOW);
    delay(200);
  }
}

// Function to turn off all motors (brake)
void motorBrake(){
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  Serial.println("Braking");

  // Turn on the built-in LED to indicate braking
    digitalWrite(builtInLed, HIGH);
}

// Function to make the motors turn left
void turnLeft() {
  digitalWrite(motorPin1, LOW);   // Left Backward
  digitalWrite(motorPin2, HIGH);  // Left Forward
  digitalWrite(motorPin3, LOW);   // Right Forward
  digitalWrite(motorPin4, HIGH);  // Right Backward
  Serial.println("Turning left");

  // Blink the built-in LED 2 times
  for (int i = 0; i < 2; i++) {
    digitalWrite(builtInLed, HIGH);
    delay(200);
    digitalWrite(builtInLed, LOW);
    delay(200);
  }
}

// Function to make the motors turn right
void turnRight() {
  digitalWrite(motorPin1, HIGH);  // Left Backward
  digitalWrite(motorPin2, LOW);   // Left Forward
  digitalWrite(motorPin3, HIGH);  // Right Forward
  digitalWrite(motorPin4, LOW);   // Right Backward
  Serial.println("Turning right");

  // Blink the built-in LED 2 times
  for (int i = 0; i < 2; i++) {
    digitalWrite(builtInLed, HIGH);
    delay(200);
    digitalWrite(builtInLed, LOW);
    delay(200);
  }
}

void setup() {
  // Initialize motor pins as outputs
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);

  // Initialize built-in LED pin as output
  pinMode(builtInLed, OUTPUT);

  // Initial brake to ensure motors are stopped initially
  motorBrake();

  Serial.begin(9600);
  Serial.println("Motor Control Initialized");
}

void loop() {
  // Move forward
  moveForward();
  delay(8000);

  motorBrake();
  delay(2000);

  // Move backward
  moveBackward();
  delay(8000);

  motorBrake();
  delay(2000);

  // Turn left
  turnLeft();
  delay(8000);

  motorBrake();
  delay(2000);

  // Turn right
  turnRight();
  delay(8000);
}
