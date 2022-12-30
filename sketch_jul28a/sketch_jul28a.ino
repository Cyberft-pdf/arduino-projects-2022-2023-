void setup() {
  
  Serial.begin(9600);//
  pinMode(7, OUTPUT);// connected to S terminal of Relay

}

void loop() {

  digitalWrite(7,HIGH);// turn relay ON
      Serial.println("Pin 7 Zapnuto");
  delay(10000);// keep it ON for 3 seconds

  digitalWrite(7, LOW);// turn relay OFF
      Serial.println("Pin 7 Vypnuto");
 delay(10000);// keep it OFF for 5 seconds
     
}
