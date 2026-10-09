#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2     
#define DHTTYPE DHT22   

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  dht.begin();
  lcd.setCursor(0,0);
  lcd.print("Init Meteo...");
  delay(2000);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print(" C");

  lcd.setCursor(0,1);
  lcd.print("Hum:  ");
  lcd.print(h);
  lcd.print(" %");
  
  delay(2000);
}