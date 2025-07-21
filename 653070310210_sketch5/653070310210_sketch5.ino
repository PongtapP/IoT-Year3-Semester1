#include "DHT.h"
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET -1
Adafruit_SSD1306 OLED(OLED_RESET);

#define DHTTYPE DHT11
#define DHTPIN D4
DHT dht(DHTPIN, DHTTYPE, 15);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  OLED.begin(SSD1306_SWITCHCAPVCC, 0x3c);
}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    OLED.clearDisplay();
    OLED.setTextColor(WHITE);
    OLED.setCursor(0, 0);
    OLED.setTextSize(1);
    OLED.print(String("H:") + String(h, 0) + "%  ");
    // OLED.setCursor(0, 30);
    OLED.print(String("T:") + String(t, 0) + "");
    OLED.write(247);
    OLED.print("C");
    OLED.display();
    delay(1000);

    // OLED.clearDisplay();
    // OLED.setTextColor(WHITE);
    // OLED.setCursor(0, 0);
    // OLED.setTextSize(3);
    // OLED.println(String("H:") + String(h, 0) + " %");
    // OLED.setCursor(0, 30);
    // OLED.print(String("T:") + String(t, 0) + " ");
    // OLED.write(247);
    // OLED.print("C");
    // OLED.display();
  }
}
