#include <ESP32Servo.h> 

Servo myservo;  // create servo object to control a servo

int servoPin = 6;  // Pin to which the servo is connected

void setup() {
  // put your setup code here, to run once:
  myservo.attach(servoPin);  // attaches the servo on pin 13 to the servo object
  Serial.begin(115200);
}

void loop() {
  // Move the servo from 0 to 180 degrees over 3 seconds
  Serial.println("Moving from 0 to 180 degrees...");
  for (int pos = 0; pos <= 180; pos++) {
    myservo.write(pos);  // Set the servo position
    delay(3000 / 180);   // Delay for smooth movement (3 seconds divided by 180 steps)
  }

  delay(1000);  // Wait for 1 second at 180 degrees

  // Move the servo back from 180 to 0 degrees over 3 seconds
  Serial.println("Moving back from 180 to 0 degrees...");
  for (int pos = 180; pos >= 0; pos--) {
    myservo.write(pos);  // Set the servo position
    delay(3000 / 180);   // Delay for smooth movement
  }

  delay(1000);  // Wait for 1 second at 0 degrees
}