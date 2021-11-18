#include "DHT.h"
#define RELAY_FAN_PIN 5 // Arduino pin connected to relay which connected to fan
#define RELAY_FAN_PIN1 6 // Arduino pin connected to relay which connected to fan
#define DHTPIN 4        // Arduino pin connected to relay which connected to DHT sensor
#define DHTTYPE DHT22


DHT dht(DHTPIN, DHTTYPE);


const int TEMP_THRESHOLD_UPPER = 25; // upper threshold of temperature, change to your desire value
const int TEMP_THRESHOLD_LOWER = 21;// lower threshold of temperature, change to your desire value
int chk;
float hum;
float temp;    // temperature in Celsius
int sensorValue = A0;
int Threshold = 350;

void setup()
{
  pinMode(sensorValue,INPUT);
  Serial.begin(115200); // initialize serial
  
  Serial.println("Gas sensor warming up!");
  dht.begin();        // initialize the sensor
  pinMode(RELAY_FAN_PIN, OUTPUT); // initialize digital pin as an output
  pinMode(RELAY_FAN_PIN1, OUTPUT); // initialize digital pin as an output

}
void loop()
{
  // wait a few seconds between measurements.
  delay(2000);
  hum = dht.readHumidity();
  temp = dht.readTemperature();;  // read temperature in Celsius

  int sensorValue = analogRead(sensorValue); // read analog input pin 0
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue); 
  Serial.println("");
  delay(2000); // wait 2s for next reading
  
  if (isnan(temp)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    if(temp < TEMP_THRESHOLD_UPPER && sensorValue > Threshold ){
    Serial.println("The fan is turned on");
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.println(" Celsius");
    Serial.print(" |  Air pollutant detected!");
    digitalWrite(RELAY_FAN_PIN, HIGH); // turn off
    
    }
    else if(temp >TEMP_THRESHOLD_LOWER && sensorValue < Threshold ){
    Serial.println("The fan is turned off");
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.println(" Celsius");
    Serial.print(" | No Air pollutant detected!");
    digitalWrite(RELAY_FAN_PIN, LOW); // turn off
    
    }
  }
  digitalWrite(RELAY_FAN_PIN1, HIGH); // turn on
  delay(10000);
  digitalWrite(RELAY_FAN_PIN1, LOW); // turn off
  delay(15000);
  }
