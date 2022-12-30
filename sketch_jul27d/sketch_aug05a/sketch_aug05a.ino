
//Celsius to Fahrenheit conversion
double Fahrenheit(double celsius)
{
  return 1.8 * celsius + 32;
}

// fast integer version with rounding
//int Celcius2Fahrenheit(int celcius)
//{
//  return (celsius * 18 + 5)/10 + 32;
//}


//Celsius to Kelvin conversion
double Kelvin(double celsius)
{
  return celsius + 273.15;
}

// dewPoint function NOAA
// reference (1) : http://wahiduddin.net/calc/density_algorithms.htm
// reference (2) : http://www.colorado.edu/geography/weather_station/Geog_site/about.htm
//
double dewPoint(double celsius, double humidity)
{
  // (1) Saturation Vapor Pressure = ESGG(T)
  double RATIO = 373.15 / (273.15 + celsius);
  double RHS = -7.90298 * (RATIO - 1);
  RHS += 5.02808 * log10(RATIO);
  RHS += -1.3816e-7 * (pow(10, (11.344 * (1 - 1/RATIO ))) - 1) ;
  RHS += 8.1328e-3 * (pow(10, (-3.49149 * (RATIO - 1))) - 1) ;
  RHS += log10(1013.246);

        // factor -3 is to adjust units - Vapor Pressure SVP * humidity
  double VP = pow(10, RHS - 3) * humidity;

        // (2) DEWPOINT = F(Vapor Pressure)
  double T = log(VP/0.61078);   // temp var
  return (241.88 * T) / (17.558 - T);
}

// delta max = 0.6544 wrt dewPoint()
// 6.9 x faster than dewPoint()
// reference: http://en.wikipedia.org/wiki/Dew_point
double dewPointFast(double celsius, double humidity)
{
  double a = 17.271;
  double b = 237.7;
  double temp = (a * celsius) / (b + celsius) + log(humidity*0.01);
  double Td = (b * temp) / (a - temp);
  return Td;
}






#include <dht11.h>

dht11 DHT11;

/* Define the DIO pin that will be used to communicate with the sensor */
#define DHT11_DIO 2


void setup()
{
  /* Setup the serial port for displaying the output of the sensor */
  Serial.begin(9600);
}

/* Main program loop */
void loop()
{
  /* Perform a read of the sensor and check if data was read OK */
  if (DHT11.read(DHT11_DIO) == DHTLIB_OK)
  {
    /* If so then output the current temperature and humidity to 
    the serial port */
    Serial.print("Temperature: ");
    Serial.print((float)DHT11.temperature, 2);
    Serial.print("oC\t");
    Serial.print("Humidity: ");
    Serial.print((float)DHT11.humidity, 2);
    Serial.println("%");
    Serial.print("Dew Point (°C): ");
    Serial.println(dewPoint(DHT11.temperature, DHT11.humidity));
    Serial.print("Dew PointFast (°C): ");
    Serial.println(dewPointFast(DHT11.temperature, DHT11.humidity));

  }else
  {
    /* If there was a problem reading from then sensor then output 
    an error */
    Serial.println("ERROR");
  }
  
  delay(500);
}

