//include DHT library:
#include <DHT.h>;
#include <String.h>
// include the SD library:
#include <SD.h>
#include <SPI.h>
#include <SoftwareSerial.h>
//Constants
#define DHTPIN 7     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22 
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

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
const int TEMP_THRESHOLD_UPPER = 25; // upper threshold of temperature, change to your desire value
const int TEMP_THRESHOLD_LOWER = 20; // lower threshold of temperature, change to your desire value

 
// set up variables using the SD utility library functions:
Sd2Card card;
SdVolume volume;
SdFile root;
 
// change this to match your SD shield or module;
// Arduino Ethernet shield: pin 4
// Adafruit SD shields and modules: pin 10
// Sparkfun SD shield: pin 8
// MKRZero SD: SDCARD_SS_PIN
const int chipSelect = 10;

void setup() {
 SETUP();

}

void loop() {
fan();
gas();
gsm();
sdCard();
temperature();
}
