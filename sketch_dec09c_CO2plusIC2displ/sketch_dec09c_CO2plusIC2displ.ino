// Example sketch for testing OLED display

// We need to include Wire.h for I2C communication
#include <Wire.h>
#include "OLED.h"

// Declare OLED display
// display(SDA, SCL);
// SDA and SCL are the GPIO pins of ESP8266 that are connected to respective pins of display.
OLED display(4, 5);

float t;
String strTemp;
char bufTemp[5]; 

void setup() {
  Serial.begin(9600);
  Serial.println("Inicializaace Senzoru CO2");

  // Initialize display
  display.begin();

  // Test message
  display.print("Scan and detect CO2");
  delay(3*1000);

  // Test long message
  display.print("CO2 detect CO2 CO2 detect CO2 CO2 detect CO2 CO2 detect CO2 CO2 detect CO2 CO2 detect CO2 ");
  delay(3*1000);

  // Test display clear
  display.clear();
  delay(3*1000);

  // Test display ON
  display.on();
  delay(3*1000);

  display.print((bufTemp),7,1);
  
}

int r = 0, c = 0;

void loop() {
  r = r % 8;
  c = micros() % 6;

  if (r == 0)
    display.clear();

  t = analogRead(A0);
  char bufTemp[5]; 
  strTemp = String(t); 
  strTemp.toCharArray(bufTemp,5); 
  display.print((bufTemp),5,1); 

  Serial.println(analogRead(A0));
  delay(500);
}
