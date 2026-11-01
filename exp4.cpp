#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

int potPin = 34;
int potValue = 0;

WebServer server(80);

void handleRoot() {
  potValue = analogRead(potPin);

  String webpage = "<!DOCTYPE html><html><head>";
  webpage += "<title>ESP32 Sensor Data</title>";
  webpage += "</head><body style='text-align:center;'>";
  webpage += "<h1>ESP32 Potentiometer Monitoring</h1>";
  webpage += "<h2>Potentiometer Value: ";
  webpage += String(potValue);
  webpage += "</h2>";
  webpage += "<p>Sensor data displayed using ESP32 Web Server</p>";
  webpage += "</body></html>";

  server.send(200, "text/html", webpage);
}

void setup() {
  Serial.begin(115200);

  pinMode(potPin, INPUT);

  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, handleRoot);

  server.begin();

  Serial.println("Web Server Started!");
}

void loop() {
  server.handleClient();
}



// Potentiometer	ESP32
// VCC	3.3V
// Middle pin	GPIO 34
// GND	GND
