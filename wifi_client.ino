#include <WiFi.h>

// WiFi credentials
const char* ssid = "ESP32_AP";
const char* password = "12345678";

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  // Connect to WiFi
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("\nWiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}


void loop() {
  // put your main code here, to run repeatedly:

}
#include <WiFi.h>

const char* ssid = "ESP32_Server";
const char* password = "12345678";

const char* host = "192.168.4.1"; // Server IP

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }

  Serial.println("Connected to WiFi");
}

void loop() {
  WiFiClient client;

  if (client.connect(host, 80)) {
    Serial.println("Connected to Server");

    client.println("Hello from ESP32 Client");

    while (client.available()) {
      String response = client.readStringUntil('\n');
      Serial.println("Server: " + response);
    }

    client.stop();
  } else {
    Serial.println("Connection failed");
  }

  delay(3000);
}
