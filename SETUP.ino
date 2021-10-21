 void SETUP(){
  Serial.begin(9600); // sets the serial port to 9600
pinMode(13, OUTPUT);
pinMode( 3, INPUT);

Serial.begin(9600);
  dht.begin();

   // initialize digital pin A5 as an output.
  pinMode(RELAY_PIN, OUTPUT);

  //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
Serial.begin(9600);

//Begin serial communication with Arduino and SIM900
gprsSerial.begin(9600);

Serial.println("Initializing...");
delay(1000);

gprsSerial.println("AT");  //Handshaking with SIM900
updateSerial();
gprsSerial.println("AT+CSQ");  //Signal quality test, value range is 0-31, 31 is the best
updateSerial();
gprsSerial.println("AT+CCID");  //Read SIM information to confirm wheteher the SIM is plugged
updateSerial();
gprsSerial.println("AT+CREG?");  //Check whether it has registered in the network
updateSerial();
  }