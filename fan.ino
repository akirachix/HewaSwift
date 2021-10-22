// the loop function runs over and over again forever
void fan() 
  digitalWrite(RELAY_PIN, HIGH); // turn on fan 5 seconds
  delay(5000);
  digitalWrite(RELAY_PIN, LOW);  // turn off fan 5 seconds
  delay(5000);
}