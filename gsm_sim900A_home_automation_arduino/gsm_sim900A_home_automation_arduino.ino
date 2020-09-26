//code by ROHIT_D_H
#include <SoftwareSerial.h>
 
// Configure software serial port
SoftwareSerial SIM900(7, 8);

String textMessage;


 const String inf;
// Create a variable to store Lamp state
String relayState = "LOW";
String oneState = "LOW";
String twoState = "LOW";
String threeState = "LOW";
 
// Relay connected to pin 12
const int relay  = 10;
const int one    = 11;
const int two    = 12;
const int three  = 13; 
 
   void setup() {
  // Automatically turn on the shield
 
  
  // Set relay as OUTPUT
    pinMode(relay, OUTPUT);
    pinMode(one, OUTPUT);
    pinMode(two, OUTPUT);
    pinMode(three, OUTPUT);
 
  // By default the relay is off
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  
  // Initializing serial commmunication
  Serial.begin(19200); 
  SIM900.begin(19200);
 
  // Give time to your GSM shield log on to network
  delay(20000);
  Serial.print("SIM900 is ready to send receive sms");
 
  // AT command to set SIM900 to SMS mode
  SIM900.print("AT+CMGF=1\r"); 
  delay(100);
  // Set module to send SMS data to serial out upon receipt 
  SIM900.print("AT+CNMI=2,2,0,0,0\r");
  delay(100);
}
 
void loop(){
  if(SIM900.available()>0){
    textMessage = SIM900.readString();
    Serial.print(textMessage);    
    delay(10);
  } 
  if(textMessage.indexOf("relayOn1234")>=0){
    // Turn on relay and save current state
    digitalWrite(relay, HIGH);
    relayState = "HIGH";
    Serial.println("Relay is ON");  
    textMessage = "";   
  }
    if(textMessage.indexOf("oneOn1234")>=0){
    // Turn on ONE and save current state
    
    digitalWrite(one, HIGH);
    delay(200);
    digitalWrite(one, LOW);
delay(200);
    digitalWrite(one, HIGH);
    delay(200);
    digitalWrite(one, LOW);
delay(200);
    digitalWrite(one, HIGH);
    delay(200);
    digitalWrite(one, LOW);
delay(200);
    digitalWrite(one, HIGH);
    delay(200);
    digitalWrite(one, LOW);
    
    oneState = "HIGH";
    Serial.println("ONE is ON");  
    textMessage = "";   
  }
    
if(textMessage.indexOf("twoOn1234")>=0){
    // Turn on TWO and save current state
    digitalWrite(two, HIGH);
    delay(4000);
    digitalWrite(two, LOW);
    twoState = "HIGH";
    Serial.println("TWO is ON");  
    textMessage = "";   
  }
    if(textMessage.indexOf("threeOn1234")>=0){
    // Turn on THREE and save current state
    digitalWrite(three, HIGH);
    threeState = "HIGH";
    Serial.println("THREE is ON");  
    textMessage = "";   
  }
    
 if(textMessage.indexOf("relayOff1234")>=0){
    // Turn off relay and save current state
    digitalWrite(relay, LOW);
    relayState = "LOW"; 
    Serial.println("Relay is OFF");
    textMessage = ""; 
  }

if(textMessage.indexOf("oneOff1234")>=0){
    // Turn OFF ONE and save current state
    digitalWrite(one,LOW );
    oneState = "off";
    Serial.println("ONE is OFF");  
    textMessage = "";   
  }

if(textMessage.indexOf("twoOff1234")>=0){
    // Turn OFF TWO and save current state
    digitalWrite(two, LOW);
    twoState = "off";
    Serial.println("TWO is OFF");  
    textMessage = "";   
  }
    if(textMessage.indexOf("threeOff1234")>=0){
    // Turn off THREE and save current state
    digitalWrite(three, LOW);
    threeState = "off";
    Serial.println("THREE is OFF");  
    textMessage = "";   
  }
    

    

  if(textMessage.indexOf("STATE1234")>=0){
    
    
  
      // Initializing serial commmunication
  Serial.begin(19200); 
  SIM900.begin(19200);
  Serial.println("SIM900 is ready to send receive sms");
 
  // AT command to set SIM900 to SMS mode
  SIM900.print("AT+CMGF=1\r"); 
  delay(1000);
    String message = inf;
    sendSMS(message);
    Serial.println("PUMP state resquest");
    textMessage = "";
  }
}  
 
// Function that sends SMS
void sendSMS(String message){
  // AT command to set SIM900 to SMS mode
  SIM900.print("AT+CMGF=1\r"); 
  delay(100);
 
  // change to your sim900's your phone number
  SIM900.println("AT + CMGS = \"6362839877\""); 
  delay(100);
  // Send the SMS
  SIM900.println(message); 
  delay(100);
 
  // End AT command with a ^Z, ASCII code 26
  SIM900.println((char)26); 
  delay(100);
  SIM900.println();
  // Give module time to send SMS
  delay(5000);  
}


  
  // Set module to send SMS data to serial out upon receipt
