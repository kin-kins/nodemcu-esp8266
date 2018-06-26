
#include<ESP8266WiFi.h>
void setup() {
  // put your setup code here, to run once:
WiFi.softAP("node","asdfghjkl1");
Serial.begin(115200);
   
}
 
void loop() {
  // put your main code here, to run repeatedly:
 IPAddress myIP= WiFi.softAPIP();
  Serial.print("Adress of the connector ");
  Serial.println (myIP);
  delay(2000);
//Serial.println(Wifi.localIP());
}
