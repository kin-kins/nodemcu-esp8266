
#include <ESP8266WiFi.h>
#include "FirebaseArduino.h"

#define FIREBASE_HOST "onlinespade.firebaseio.com"
#define FIREBASE_AUTH "zOfOLC5PdFzasY46IwX5VdQK9KaMIYCgozAN12zN"
#define WIFI_SSID "Temp"
#define WIFI_PASSWORD "yyyyyyyy"

void setup() {
  Serial.begin(9600);
   
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
    
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  //Firebase.set("Temp", 1);
  //Firebase.set("Humidity", 1);
}

void loop() {
  int h = analogRead(A0);
   
 Firebase.pushFloat("/NODEMCU/Moisture", h);
  // handle error
  if (Firebase.failed()) {
      Serial.print("pushing /Moisture failed:");
      Serial.println(Firebase.error());  
      return;
  }

  delay(1000);
}
