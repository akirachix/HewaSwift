#include <DHT.h>;
#include <String.h>
//Constants
#define DHTPIN 7     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22 
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino
#include <SoftwareSerial.h>

//Create software serial object to communicate with SIM900
SoftwareSerial gprsSerial(7, 8); //SIM900 Tx & Rx is connected to Arduino #7 & #8

//Variables
int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value

int digitalValue;
int sensorValue;

// constants won't change
const int RELAY_PIN = A5;  // the Arduino pin, which connects to the IN pin of relay

void setup() {
 SETUP();

}

void loop() {
gas();
fan();
temperature();
gsm();

}