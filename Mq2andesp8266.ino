#include <ThingSpeak.h>
#include <DHT.h> // Including library for dht
#include "ESP8266WiFi.h"
String apiKey = "MSDQAFP3C28IP7BI";  // Enter your Write API key from ThingSpeak
const char *ssid = "Codehive";  // replace with your wifi ssid and wpa2 key
const char *pass = "codehive!";
const char* server = "api.thingspeak.com";
int sensorValue = A0;
int Threshold = 350;

WiFiClient client;
void setup()
{
    pinMode(sensorValue,INPUT);
    Serial.begin(9600);
    delay(10);
    Serial.println("Gas sensor warming up!");

    Serial.println("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, pass);
   while (WiFi.status() != WL_CONNECTED)
   {
      delay(500);
      Serial.print(".");
   }
   Serial.println("");
   Serial.println("WiFi connected");
}
void loop()
{
   int sensorValue = analogRead(sensorValue); // read analog input pin 0
     Serial.print("Sensor Value: ");
      Serial.print(sensorValue); 
      Serial.println("");
      delay(2000); // wait 2s for next reading
     
    
    if( sensorValue < Threshold ){
    
    Serial.print(" |  Air pollutant detected!");
    
    
    }
    else if( sensorValue > Threshold ){
    
    Serial.print(" | No Air pollutant detected!");
 
    

   
    
  }
             if (client.connect(server,80)) // "184.106.153.149" orapi.thingspeak.com
           {
               String postStr = apiKey;
               postStr +="&field1=";
               postStr += String(sensorValue);
               postStr += "\r\n\r\n";
               client.print("POST /update HTTP/1.1\n");
               client.print("Host:api.thingspeak.com\n");
               client.print("Connection: close\n");
               client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
               client.print("Content-Type: application/x-www-form-urlencoded\n");
               client.print("Content-Length: ");
               client.print(postStr.length());
               client.print("\n\n");
               client.print(postStr);
               Serial.print("SensorValue: ");
               Serial.print(sensorValue);
               Serial.println("%. Send to Thingspeak.");
            }
     client.stop();
     Serial.println("Waiting...");
 // thingspeak needs minimum 15 sec delay between updates
 delay(1000);
}
