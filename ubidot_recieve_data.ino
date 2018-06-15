#include "UbidotsMicroESP8266.h"
#include "DHT.h"        // including the library of DHT11 temperature and humidity sensor
#define DHTTYPE DHT11   // DHT 11


#define dht_dpin 0
DHT dht(0, DHTTYPE); 
#define TOKEN  "BBFF-ASn8iQUDLz97JxlYiWoe9O2oZqTkE4"  // Put here your Ubidots TOKEN
#define ID_1 "5b21a32e642ab6124379dd00" 
// Put your variable ID here
#define ID_2 "5b239d5d642ab62dffbf32ba"
#define WIFISSID "one plus" // Put here your Wi-Fi SSID
#define PASSWORD "asdfghjkl1" // Put here your Wi-Fi password

Ubidots client(TOKEN);

void setup(){
    Serial.begin(115200);
    client.wifiConnection(WIFISSID, PASSWORD);


    //client.setDebug(true); // Uncomment this line to set DEBUG on
}

void loop(){
    int chk=dht.read(2);
    float x=client.getValue(ID_2); //recieve data command
    Serial.println(x);
    delay(6000);
    float t = dht.readTemperature();       
    
    delay(1000);
    client.add(ID_1, t);
    client.sendAll(false);
    delay(5000);
}
