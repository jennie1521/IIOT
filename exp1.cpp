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
