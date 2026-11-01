// Experiment 1: Sending Alert Messages
// ESP32 + Potentiometer

const int potPin = 34;

int potValue = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
}

void loop() {

  // Read potentiometer value
  potValue = analogRead(potPin);

  // Check threshold condition
  if (potValue > 2000) {
    Serial.println("WARNING!");
  }

  // Print potentiometer value
  Serial.print("Potentiometer Value: ");
  Serial.println(potValue);

  delay(500);
}


// Click the GND pin of the potentiometer and connect it to ESP32 GND.
// Connect SIG to GPIO 34.
// Connect VCC to ESP32 3V3.

// Aim: Write a program for sending alert messages to the user for controlling and interacting with your environment. 
// Software Requirement: Arduino IDE 
// Hardware Requirement: ESP-WROOM 32 board, Micro USB Data Cable, bread board, Potentiometer 10K, Male to female wires, Laptop/PC. 
// Theory: The program is written in the Arduino programming language and is designed to read the value of a potentiometer connected to GPIO 34 (Analog ADC1_CH6) on an Arduino board.
//   It continuously reads the potentiometer value and prints it to the Serial Monitor. If the potentiometer value exceeds 2000, it also prints "warning" to the Serial Monitor. 
