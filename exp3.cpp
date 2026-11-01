#include <WiFi.h>
#include <WebServer.h>

// WiFi details for Wokwi
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// Create web server on port 80
WebServer server(80);

// LED pins
int led1 = 12;
int led2 = 14;

// Webpage
String webpage = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <title>ESP32 LED Control</title>
  <style>
    body {
      text-align: center;
      font-family: Arial;
      margin-top: 50px;
    }
    button {
      padding: 12px 25px;
      margin: 10px;
      font-size: 18px;
    }
  </style>
</head>
<body>
  <h1>ESP32 LED Control</h1>

  <h2>LED 1 - GPIO 12</h2>
  <a href="/12/on"><button>ON</button></a>
  <a href="/12/off"><button>OFF</button></a>

  <h2>LED 2 - GPIO 14</h2>
  <a href="/14/on"><button>ON</button></a>
  <a href="/14/off"><button>OFF</button></a>
</body>
</html>
)rawliteral";

void setup() {
  Serial.begin(115200);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  // Connect to WiFi
  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected!");
  Serial.print("ESP32 IP Address: ");
  Serial.println(WiFi.localIP());

  // Main webpage
  server.on("/", []() {
    server.send(200, "text/html", webpage);
  });

  // LED 1 controls
  server.on("/12/on", []() {
    digitalWrite(led1, HIGH);
    server.send(200, "text/html", webpage);
  });

  server.on("/12/off", []() {
    digitalWrite(led1, LOW);
    server.send(200, "text/html", webpage);
  });

  // LED 2 controls
  server.on("/14/on", []() {
    digitalWrite(led2, HIGH);
    server.send(200, "text/html", webpage);
  });

  server.on("/14/off", []() {
    digitalWrite(led2, LOW);
    server.send(200, "text/html", webpage);
  });

  server.begin();
  Serial.println("Web Server Started!");
}

void loop() {
  server.handleClient();
}



// LED	ESP32 connection
// LED 1 anode (+)	GPIO 12 through 220Ω resistor
// LED 1 cathode (-)	GND
// LED 2 anode (+)	GPIO 14 through 220Ω resistor
// LED 2 cathode (-)	GND
