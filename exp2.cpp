// Experiment 2: PIR Sensor Interfacing

int pirPin = 2;
int ledPin = 13;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int motionState = digitalRead(pirPin);

  if (motionState == HIGH) {
    digitalWrite(ledPin, HIGH);
    Serial.println("Motion detected!");
  }
  else {
    digitalWrite(ledPin, LOW);
    Serial.println("No motion detected.");
  }

  delay(1000);
}


// PIR sensor pin	Arduino Uno
// VCC	5V
// GND	GND
// OUT / Signal	Digital pin 2

// LED connections
// LED terminal	Arduino Uno
// Anode (+), longer leg	Pin 13 through 220Ω resistor
// Cathode (−), shorter leg	GND
