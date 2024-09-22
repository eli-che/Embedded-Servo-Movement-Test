# Embedded Servo Movement Test

This project demonstrates how to control a servo motor using an ESP32, allowing the servo to rotate smoothly between 0 and 180 degrees and back. The code runs a continuous loop to move the servo over a 3-second period in both directions.

## Features
- **Servo Movement**: Rotates the servo from 0 to 180 degrees, then returns it back to 0 degrees.
- **Smooth Transition**: The servo moves gradually over 3 seconds to simulate a smooth motion.
- **Serial Output**: Displays movement messages on the serial monitor to track the servo's position.

## Components
- **ESP32 (ESP32-S3-WROOM)**
- **Servo Motor**
- **Wires & Breadboard**

## Pin Configuration

| Component       | GPIO Pin  | Function        |
|-----------------|-----------|-----------------|
| Servo Signal Pin| GPIO 6    | Controls servo angle |

## Circuit Diagram
- Connect the servo motor’s signal pin to GPIO 6.
- Power the servo with the appropriate voltage (typically 5V) from the ESP32 or external power supply.
  
## Code Explanation
The code uses the **ESP32Servo** library to control the servo. It allows setting the servo angle between 0 and 180 degrees. The code runs a loop:
1. Moves the servo from 0 to 180 degrees.
2. Pauses at 180 degrees for 1 second.
3. Moves the servo back from 180 to 0 degrees.
4. Pauses at 0 degrees for 1 second.

```cpp
#include <ESP32Servo.h>

Servo myservo;  // Create a servo object to control the servo motor

int servoPin = 6;  // GPIO pin for the servo

void setup() {
  myservo.attach(servoPin);  // Attach the servo to the defined GPIO pin
  Serial.begin(115200);  // Initialize serial communication for debugging
}

void loop() {
  // Move the servo from 0 to 180 degrees over 3 seconds
  Serial.println("Moving from 0 to 180 degrees...");
  for (int pos = 0; pos <= 180; pos++) {
    myservo.write(pos);  // Set the servo position
    delay(3000 / 180);   // Smooth movement with delay
  }

  delay(1000);  // Pause for 1 second at 180 degrees

  // Move the servo back from 180 to 0 degrees over 3 seconds
  Serial.println("Moving back from 180 to 0 degrees...");
  for (int pos = 180; pos >= 0; pos--) {
    myservo.write(pos);  // Set the servo position
    delay(3000 / 180);   // Smooth movement with delay
  }

  delay(1000);  // Pause for 1 second at 0 degrees
}
```

## How to Use
1. **Hardware Setup**:
   - Assemble the circuit by connecting the servo's signal wire to GPIO 6 of the ESP32.
2. **Software Setup**:
   - Install the required **ESP32Servo** library: [ESP32Servo Library](https://github.com/madhephaestus/ESP32Servo).
   - Upload the provided code to your ESP32 using the Arduino IDE.
3. **Run the Project**:
   - Open the serial monitor to observe the movement logs.
   - Watch the servo move smoothly between 0 and 180 degrees.

## Future Improvements
- Add support for multiple servos.
- Implement different speed controls for the servo’s movement.
- Integrate user input to control the servo angle via serial commands or a web interface.

## License
This project is open-source under the MIT License. Feel free to modify and distribute as needed.

---

This `README.md` should help others understand and use your project. Let me know if you need any adjustments!
