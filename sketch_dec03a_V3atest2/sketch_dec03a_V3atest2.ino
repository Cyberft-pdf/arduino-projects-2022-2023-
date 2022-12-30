// put your setup code here, to run once:

#define ledPin D7         // Device internal LED      
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <Wire.h>
#include "OLED.h"
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>

OLED display(4, 5);





// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "222cc4afd9a8475fbc7ddeb5210f0e0c"; //Enter the Auth code which was send by Blink asi senzor kotel




// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "";  //Enter your WIFI Name
char pass[] = "";  //Enter your WIFI Password


SimpleTimer timer;


void setup()
{
   // Initialize display
  display.begin();
  float i = analogRead(A0);

  
  
  Serial.begin(9600);              //  setup serial
  Blynk.begin(auth, ssid, pass, IPAddress(192, 168, 197, 70), 8080);
  
}

int r = 0, c = 0;

void loop()
{
  r = r % 8;
  c = micros() % 6;

  int sensorVal = analogRead (A0);
  float voltage = sensorVal * 1;
      
  Blynk.run(); // Initiates Blynk
  timer.run(); // Initiates SimpleTimer

 

  Serial.println(analogRead(A0));
  delay(1000); // Print value every 1 sec.
}

