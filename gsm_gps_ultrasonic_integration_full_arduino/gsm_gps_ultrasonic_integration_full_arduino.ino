///code by ROHIT_D_H
#include <SoftwareSerial.h>
#include <TinyGPS++.h>

// Configure software serial port
SoftwareSerial SIM900(7, 8);/*rx tx*/
SoftwareSerial GPS_SoftSerial(4, 3);/*rx, tx*/

TinyGPSPlus gps;   
 
// Variable to store text message and gps location
String textMessage;
const String inf;
int trigPin = 12;    // Trigger
int echoPin = 13;    // Echo
long duration, cm;
volatile float minutes, seconds , minutes1 , seconds1;
volatile int degree, secs, mins , degree1, secs1, mins1;

 
void setup() {

pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
pinMode(5, OUTPUT);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
   // Initializing serial commmunication
  Serial.begin(19200); 
  SIM900.begin(19200);
  delay(6000);
  Serial.println("SIM900 is ready to send receive sms");
 
  // AT command to set SIM900 to SMS mode
  SIM900.print("AT+CMGF=1\r"); 
  delay(1000);
  // Set module to send SMS data to serial out upon receipt 
  
}
 
void loop() {
digitalWrite(5,HIGH);
digitalWrite(11,HIGH);
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delay(80);
  digitalWrite(trigPin, HIGH);
  delay(80);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
   // Divide by 74 or multiply by 0.0135
  
  
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
if (cm>=7 &&  cm<20)
{digitalWrite(10,HIGH);
Serial.println("break applied");}

else if (cm<=5)
{  digitalWrite(10,HIGH);
  GPS_SoftSerial.begin(9600);
  gpsval();
   
  
   String message = inf;
    // Initializing serial commmunication
  Serial.begin(19200); 
  SIM900.begin(19200);
  Serial.println("SIM900 is ready to send receive sms");
 
  // AT command to set SIM900 to SMS mode
  SIM900.print("AT+CMGF=1\r"); 
  delay(1000);
    sendSMS(message);    
 Serial.println("SENDING MESSAGE");
 textMessage = "";
 delay(1000000);
 }
else
{digitalWrite(10,LOW);
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

static void smartDelay(unsigned long ms)
{
  unsigned long start = millis();
  do 
  {
    while (GPS_SoftSerial.available())  /* Encode data read from GPS while data is available on serial port */
      gps.encode(GPS_SoftSerial.read());
    /* Encode basically is used to parse the string received by the GPS and to store it in a buffer so that information can be extracted from it */
  } while (millis() - start < ms);
}

void DegMinSec( double tot_val)   /* Convert data in decimal degrees into degrees minutes seconds form */
{  
  degree = (int)tot_val;
  minutes = tot_val - degree;
  seconds = 60 * minutes;
  minutes = (int)seconds;
  mins = (int)minutes;
  seconds = seconds - minutes;
  seconds = 60 * seconds;
  secs = (int)seconds;
}

void DegMinSec1( double tot_val)   /* Convert data in decimal degrees into degrees minutes seconds form */
{  
  degree1 = (int)tot_val;
  minutes1 = tot_val - degree1;
  seconds1 = 60 * minutes1;
  minutes1 = (int)seconds1;
  mins1 = (int)minutes1;
  seconds1 = seconds1 - minutes1;
  seconds1 = 60 * seconds1;
  secs1 = (int)seconds1;
}

void gpsval(){
  int i;
  for(i=0;i<2;i++)
  {
 smartDelay(1000); /* Generate precise delay of 1ms */
        unsigned long start;
        double lat_val, lng_val, alt_m_val;
        uint8_t hr_val, min_val, sec_val;
        bool loc_valid, alt_valid, time_valid;
        char time_string[32];
        lat_val = gps.location.lat(); /* Get latitude data */
        loc_valid = gps.location.isValid(); /* Check if valid location data is available */
        lng_val = gps.location.lng(); /* Get longtitude data */
        alt_m_val = gps.altitude.meters();  /* Get altitude data in meters */
        alt_valid = gps.altitude.isValid(); /* Check if valid altitude data is available */
        hr_val = gps.time.hour(); /* Get hour */
        min_val = gps.time.minute();  /* Get minutes */
        sec_val = gps.time.second();  /* Get seconds */
        time_valid = gps.time.isValid();  /* Check if valid time data is available */

     
       
          DegMinSec(lat_val);
          Serial.print("Latitude in Decimal Degrees : ");
          Serial.println(lat_val, 6);
          Serial.print("Latitude in Degrees Minutes Seconds : ");
          Serial.print(degree);
          Serial.print("\t");
          Serial.print(mins);
          Serial.print("\t");
          Serial.println(secs);
          
          DegMinSec1(lng_val); /* Convert the decimal degree value into degrees minutes seconds form */
          Serial.print("Longitude in Decimal Degrees : ");
          Serial.println(lng_val, 6);
          Serial.print("Longitude in Degrees Minutes Seconds : ");
          Serial.print(degree1);
          Serial.print("\t");
          Serial.print(mins1);
          Serial.print("\t");
          Serial.println(secs1);
          Serial.print("Altitude : ");
          Serial.println(alt_m_val, 6);   
       String rohit="latitude = ";
       String dattatraya="        longitude = ";
       inf =rohit + lat_val + dattatraya +lng_val ;
       
  } 
  
  // Set module to send SMS data to serial out upon receipt
        }
