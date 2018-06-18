
#include <ESP8266WiFi.h>
#include "FirebaseArduino.h"

// Set these to run example.
#define FIREBASE_HOST "https://rgbled-2e30a.firebaseio.com"
#define FIREBASE_AUTH "jElO9bZoVMkblw63r6ay5qikAGMqzBOtyOJ6rIwp"
#define WIFI_SSID "one plus"
#define WIFI_PASSWORD "asdfghjkl1"

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
  pinMode(LED_BUILTIN,OUTPUT);
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

}

void loop() {
  delay(800);

  Firebase.setString("message", "hello world");
  Firebase.set("Temp", 123);
  char B[5];
  Firebase.getString("Button").toCharArray(B,sizeof(B));
  delay(10);
  int value = atoi(B);
   //digitalWrite(LED_BUILTIN, value);
   Serial.print("Value = "); Serial.println(value);
   if (value == 1)
    digitalWrite(LED_BUILTIN, HIGH);
    else
      digitalWrite(LED_BUILTIN, LOW);
   
  delay(1000);
}
