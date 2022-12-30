// put your setup code here, to run once:

#define ledPin D7         // Device internal LED      
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#define SSD1306_128_64
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#include <Adafruit_GFX.h>  // Include core graphics library for the display
#include <Adafruit_SSD1306.h>  // Include Adafruit_SSD1306 library to drive the display

Adafruit_SSD1306 display;  // Create display


#include <Fonts/FreeMonoBold12pt7b.h>  // Add a custom font
#include <Fonts/FreeMono9pt7b.h>  // Add a custom font

int Variable1;  // Create a variable to have something dynamic to show on the display
int Variable2;  // Create a variable to have something dynamic to show on the display


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "222cc4afd9a8475fbc7ddeb5210f0e0c"; //Enter the Auth code which was send by Blink asi senzor kotel




// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "teplota";  //Enter your WIFI Name
char pass[] = "iot2018home";  //Enter your WIFI Password


SimpleTimer timer;


void setup()
{
  delay(100);  // This delay is needed to let the display to initialize

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Initialize display with the I2C address of 0x3C
 
  display.clearDisplay();  // Clear the buffer

  display.setTextColor(WHITE);  // Set color of the text

  display.setRotation(0);  // Set orientation. Goes from 0, 1, 2 or 3

  display.setTextWrap(false);  // By default, long lines of text are set to automatically “wrap” back to the leftmost column.
                               // To override this behavior (so text will run off the right side of the display - useful for
                               // scrolling marquee effects), use setTextWrap(false). The normal wrapping behavior is restored
                               // with setTextWrap(true).

  display.dim(0);  //Set brightness (0 is maximun and 1 is a little dim);
  
  Serial.begin(9600);              //  setup serial
  Blynk.begin(auth, ssid, pass, IPAddress(192, 168, 197, 70), 8080);
  
}


void loop()
{
  display.clearDisplay();  // Clear the display so we can refresh
  display.setFont(&FreeMono9pt7b);  // Set a custom font
  display.setTextSize(0);  // Set text size. We are using a custom font so you should always use the text size of 0

  display.setCursor(0, 10);  // (x,y)
  display.println(analogRead(A0));  // Text or value to print
  
  Blynk.run(); // Initiates Blynk
  timer.run(); // Initiates SimpleTimer

  Serial.println(analogRead(A0));
  delay(1000); // Print value every 1 sec.
}

