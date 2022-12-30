  // put your setup code here, to run once:

#define ledPin D7         // Device internal LED      
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
int MQ7sensorValue = 0;   // value read from the sensor 
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>


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
  Serial.begin(9600);              //  setup serial
  Blynk.begin(auth, ssid, pass, IPAddress(192,168,197,70), 8080);
 
}

void loop()
{
  
  Blynk.run(); // Initiates Blynk
  timer.run(); // Initiates SimpleTimer
}

