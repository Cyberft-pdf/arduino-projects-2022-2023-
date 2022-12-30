#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char* ssid = "iot2018";
const char* password = "aaaaa";

ESP8266WebServer server(80);

const int output1 = 12;


boolean device1 = true;


void handleRoot() {
  //digitalWrite(led, 1);
  //server.send(200, "text/plain", "hello from esp8266!");
  //digitalWrite(led, 0);

  String cmd;     
      cmd += "<!DOCTYPE HTML>\r\n";
      cmd += "<html>\r\n";
      //cmd += "<header><title>ESP8266 Webserver</title><h1>\"ESP8266 Web Server Control\"</h1></header>";
      cmd += "<head>";
      cmd += "<meta http-equiv='refresh' content='5'/>";
      cmd += "</head>";
      
      if(device1){
        cmd +=("<br/>Device1  : ON");
      }
      else{
        cmd +=("<br/>Device1  : OFF");
      }
      
        
      cmd += "<html>\r\n";
      server.send(200, "text/html", cmd);
}

void handleNotFound(){
  //digitalWrite(led, 1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
  //digitalWrite(led, 0);
}

void setup(void){
  pinMode(output1, OUTPUT);
  
  digitalWrite(output1, LOW); 
     
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("."); 
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

 

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);

  server.on("/status1=1", [](){
    server.send(200, "text/plain", "device1 = ON");
    digitalWrite(output1, HIGH); 
    device1 = true;
  });
    
   server.on("/status1=0", [](){
    server.send(200, "text/plain", "device1 = OFF");
    digitalWrite(output1, LOW); 
    device1 = false;
  });
  
  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("HTTP server started");
}

void loop(void){
  server.handleClient();
}
