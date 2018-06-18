//
// Copyright 2015 Google Inc.


#include <ESP8266WiFi.h>
#include "FirebaseArduino.h"
#include "DHT.h"        // including the library of DHT11 temperature and humidity sensor
#define DHTTYPE DHT11

#define dht_dpin 0
DHT dht(dht_dpin, DHTTYPE);


// Set these to run example.
#define FIREBASE_HOST "ledtest-486c8.firebaseio.com"
#define FIREBASE_AUTH "P6SVRCYu9o5RgCr6RckzEt6UK44ZviLLLSYIhIIo"
#define WIFI_SSID "Saiarun"
#define WIFI_PASSWORD "vinayaga007"

void setup() {
  Serial.begin(9600);
   dht.begin();
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
      float h = dht.readHumidity();
    float t = dht.readTemperature();         
    Serial.print("Current humidity = ");  Serial.print(h);   Serial.print("%  ");
    Serial.print("temperature = ");   Serial.print(t);     Serial.println("C  ");
  delay(800);
 Firebase.pushFloat("/DHT/Humudity", h);
  // handle error
  if (Firebase.failed()) {
      Serial.print("pushing /Humidity failed:");
      Serial.println(Firebase.error());  
      return;
  }
Firebase.pushFloat("/DHT/Temperature", t);
  // handle error
  if (Firebase.failed()) {
      Serial.print("pushing /Temperature failed:");
      Serial.println(Firebase.error());  
      return;
  }
 
  delay(1000);
}
