#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP32Servo.h>

// Screen setup (128x64)
Adafruit_SSD1306 display(128, 64, &Wire, -1);

// Servo setup
Servo myServo;

void setup() {
  Serial.begin(115200);

  // Initialize Display
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.display();
  delay(2000);
  display.clearDisplay();
  
  // Initialize Servo
  myServo.attach(18); // Change 18 to your actual GPIO pin
  
  Serial.println("Alex-botv3 Initialized!");
}

void loop() {
  // Your robot logic goes here
  // For example, display test:
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("Alex-botv3 Online");
  display.display();
  
  delay(1000);
}
