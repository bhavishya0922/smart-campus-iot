/**
 * Project: Smart Campus Environmental & Occupancy Monitoring Node
 * Status: Student Prototype (B.Tech CSE Semester Coursework)
 * Author: Bhavishya Dewangan
 * Hardware: ESP32, DHT22, LDR (Light), HC-SR04 (Doorway Counter), SSD1306 OLED
 */
#include <WiFi.h>
#include <WebServer.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT22
#define LDR_PIN 34
#define TRIG_PIN 5
#define ECHO_PIN 19

DHT dht(DHTPIN, DHTTYPE);
Adafruit_SSD1306 display(128, 64, &Wire, -1);
WebServer server(80);

const char* ssid = "Campus_IoT_WLAN";
const char* password = "CampusSecurePass";

int roomOccupancy = 0;
float currentTemp = 24.5;
float currentHumidity = 52.0;
int lightLevel = 650;

void updateOLED() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("SMART CLASSROOM B-204");
  display.println("---------------------");
  display.printf("Temp: %.1f C\n", currentTemp);
  display.printf("Humidity: %.1f %%\n", currentHumidity);
  display.printf("Occupancy: %d people\n", roomOccupancy);
  display.printf("Light Lux: %d\n", lightLevel);
  display.display();
}

void handleTelemetryApi() {
  String json = "{";
  json += "\"node_id\":\"CAMPUS-CSE-B204\",";
  json += "\"temperature\":" + String(currentTemp, 1) + ",";
  json += "\"humidity\":" + String(currentHumidity, 1) + ",";
  json += "\"occupancy\":" + String(roomOccupancy) + ",";
  json += "\"light_level\":" + String(lightLevel) + ",";
  json += "\"energy_mode\":\"" + String(roomOccupancy > 0 ? "ACTIVE" : "STANDBY") + "\"";
  json += "}";
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "application/json", json);
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Wire.begin(21, 22);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

  Serial.println("[NODE] Smart Campus Prototype initialized.");
  WiFi.begin(ssid, password);

  server.on("/api/telemetry", handleTelemetryApi);
  server.begin();
  updateOLED();
}

void loop() {
  server.handleClient();
}
