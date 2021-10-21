void gas()

{

sensorValue = analogRead(0); // read analog input pin 0

digitalValue = digitalRead(2); 
if(sensorValue>400)
{
digitalWrite(13, HIGH);
}
else
digitalWrite(13, LOW);
Serial.println(sensorValue, DEC); // prints the value read
Serial.println(digitalValue, DEC);

delay(1000); // wait 100ms for next reading

}