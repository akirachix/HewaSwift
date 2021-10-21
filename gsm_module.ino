void gsm(){
 updateSerial();
 
  if (gprsSerial.available()){
  Serial.write(gprsSerial.read());
 
  gprsSerial.println("AT");
  delay(1000);
 
  gprsSerial.println("AT+CPIN?");
  delay(1000);
 
  gprsSerial.println("AT+CREG?");
  delay(1000);
 
  gprsSerial.println("AT+CGATT?");
  delay(1000);
 
  gprsSerial.println("AT+CIPSHUT");
  delay(1000);
 
  gprsSerial.println("AT+CIPSTATUS");
  delay(2000);
 
  gprsSerial.println("AT+CIPMUX=0");
  delay(2000);
 
  updateSerial();
 
  gprsSerial.println("AT+CSTT=\"airtelgprs.com\"");//start task and setting the APN,
  delay(1000);
 
    updateSerial();
 
  gprsSerial.println("AT+CIICR");//bring up wireless connection
  delay(3000);
 
    updateSerial();
 
  gprsSerial.println("AT+CIFSR");//get local IP adress
  delay(2000);
   updateSerial();
 
  gprsSerial.println("AT+CIPSPRT=0");
  delay(3000);
 
  updateSerial();
 
  gprsSerial.println("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",\"80\"");//start up the connection
  delay(6000);
 
   updateSerial();
 
  gprsSerial.println("AT+CIPSEND");//begin send data to remote server
  delay(4000);
    updateSerial();
 
  String str = "GET  https://api.thingspeak.com/update?api_key=WA1ERQI8JE9HJLQP&field1=0";
  Serial.println(str);
  gprsSerial.println(str);//begin send data to remote server
 
  delay(4000);
   updateSerial();
 
  gprsSerial.println((char)26);//sending
  delay(5000);//waitting for reply, important! the time is base on the condition of internet
  gprsSerial.println();
  updateSerial();
 
  gprsSerial.println("AT+CIPSHUT");//close the connection
  delay(100);
  updateSerial();
  }}


void updateSerial() {

  while (gprsSerial.available() != 0){
    Serial.write(gprsSerial.read());
  delay(5000);
  }
}