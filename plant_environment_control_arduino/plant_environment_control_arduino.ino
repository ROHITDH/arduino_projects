#include <dht.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>
#include <RTClib.h>
#include <Keypad.h>



int z1,z2,z3;
int y1,y2,y3,y4,y5,y6,y7,y8,y9,y10,y11,y12;
const int rs = A2, en = A3, d4 = 13, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int a1,b1;

float v1=0;
int val=0;//moisture sensor
dht DHT; //temp and humidity sensor

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {1,2,3,10},
  {4,5,6,11},
  {7,8,9,12},
  {60,100,50,40}
};
byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
int state=0;

RTC_DS3231 rtc;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
 
void setup(){
  pinMode(0,OUTPUT);
  digitalWrite(0,LOW);
 
  v1=  analogRead(A0);
   DHT.read11(A1);
   a1=DHT.humidity;
   b1=DHT.temperature;
 

  lcd.begin(16, 2);
      if (! rtc.begin()) {
        delay(1000);
      }
 }
 
void loop(){
  int a,b,c,i,z,d;
state=digitalRead(1);
    if(state==1){ 
DateTime now = rtc.now();
d=now.second();

if(d!=20){
 int key = keypad.getKey();
  if (key){
     EEPROM.update(0,key);
     lcd.setCursor(0, 1);
     lcd.print(key);
     delay(800);
  }
 }

if (d==20){    
    delay(200);
    
    a=now.hour();
    b=now.minute();
    c=now.dayOfTheWeek();
    
    
    

    if(a>00 && a<12)
     { 
       if(a>0 && a<=9)
         {
      lcd.setCursor(3, 1);
      lcd.print("                ");
           lcd.setCursor(4, 1); 
           lcd.print(a); 
           lcd.setCursor(5, 1);
           lcd.print(" ");
           lcd.setCursor(6, 1);
           lcd.print(":");
           lcd.setCursor(10, 1);
           lcd.print("AM");
         }
       else
         {
      lcd.setCursor(3, 1);
      lcd.print("                ");
          lcd.setCursor(4, 1); 
           lcd.print(a); 
           lcd.setCursor(6, 1);
           lcd.print(":");
           lcd.setCursor(10, 1);
           lcd.print("AM");
         }
     }
         
    
    else if(a==12)
     {
      lcd.setCursor(3, 1);
      lcd.print("                ");
       lcd.setCursor(4, 1);
       lcd.print(a); 
       lcd.setCursor(6, 1);
       lcd.print(":");
       lcd.setCursor(10, 1);
       lcd.print("PM");
     }
      
   else if(a==00)
   {
      lcd.setCursor(3, 1);
      lcd.print("                ");
    lcd.setCursor(4, 1);
    lcd.print("12"); 
    lcd.setCursor(6, 1);
    lcd.print(":");
    lcd.setCursor(10, 1);
    lcd.print("AM");
   }
      
    else
    {
      lcd.setCursor(3, 1);
      lcd.print("                ");
      z=a-12;
      lcd.setCursor(3, 1);
      lcd.print("                ");
      lcd.setCursor(4, 1);
      lcd.print(z); 
      lcd.setCursor(6, 1);
      lcd.print(":");
      lcd.setCursor(10, 1);
      lcd.print("PM");
    }

   if(b>=0 && b<=9)
   {
    lcd.setCursor(7, 1);
    lcd.print(b);
    lcd.setCursor(8, 1);
    lcd.print(" ");
   }
    else
    {
      lcd.setCursor(7, 1);
      lcd.print(b);
    }
 
//moisture sensor
   v1=  analogRead(A0);
   val=(100-((v1/1023.00)*100));
       //serial disp
    
//DHT sensor
    DHT.read11(A1);
   
    a1=DHT.humidity;
    b1=DHT.temperature;

    lcd.setCursor(0, 0);
    lcd.print("T:");
    lcd.setCursor(2, 0);
    lcd.print(b1);

    lcd.setCursor(5, 0);
    lcd.print("H:");
    lcd.setCursor(7, 0);
    lcd.print(a1);

    lcd.setCursor(10, 0);
    lcd.print("M:");
    lcd.setCursor(12, 0);
    lcd.print(val);
    
    
    //Serial disp
    z1=EEPROM.read(0);
    
    y1=EEPROM.read(1);
    y2=EEPROM.read(2);
    y3=EEPROM.read(3);
    y4=EEPROM.read(4);
    y5=EEPROM.read(5);
    y6=EEPROM.read(6);
    y7=EEPROM.read(7);
    y8=EEPROM.read(8);
    y9=EEPROM.read(9);
    y10=EEPROM.read(10);
    y11=EEPROM.read(11);
    y12=EEPROM.read(12);
    

//////////////////////////////////////////FOR VERY HIGH WATER////////////////////////////////////////////
  ///1///
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
      if(y1==1)  
       if(a1<100 && b1>29 && val<10)
        if(a==9 || a== 11 || a==13 || a==15)
         if(b==5)
          if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
       if(y1==1)
        if(a1>=60 && a1<100)
          if( b1<=29 && b1>20)
           if ( val>=10 && val<40)
            if(a==9 || a== 12 || a==15)
              if(b==5)
                if(d==0 || d==1 || d==2)
                 digitalWrite(0,HIGH);
    }

   if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y1==1)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==9 || a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

   if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
      if(y1==1)
       if ( val>=60)
         digitalWrite(0,LOW);
    }


  ///2///
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
      if(y2==1)  
       if(a1<100 && b1>29 && val<10)
        if(a==9 || a== 11 || a==13 || a==15)
         if(b==5)
          if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
       if(y2==1)
        if(a1>=60 && a1<100)
          if( b1<=29 && b1>20)
           if ( val>=10 && val<40)
            if(a==9 || a== 12 || a==15)
              if(b==5)
                if(d==0 || d==1 || d==2)
                 digitalWrite(0,HIGH);
    }

   if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y2==1)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==9 || a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

   if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
      if(y2==1)
       if ( val>=60)
         digitalWrite(0,LOW);
    }

  ///3///
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
      if(y3==1)  
       if(a1<100 && b1>29 && val<10)
        if(a==9 || a== 11 || a==13 || a==15)
         if(b==5)
          if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
       if(y3==1)
        if(a1>=60 && a1<100)
          if( b1<=29 && b1>20)
           if ( val>=10 && val<40)
            if(a==9 || a== 12 || a==15)
              if(b==5)
                if(d==0 || d==1 || d==2)
                 digitalWrite(0,HIGH);
    }

   if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y3==1)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==9 || a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

   if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
      if(y3==1)
       if ( val>=60)
         digitalWrite(0,LOW);
    }

  ///4///
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
      if(y4==1)  
       if(a1<100 && b1>29 && val<10)
        if(a==9 || a== 11 || a==13 || a==15)
         if(b==5)
          if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
       if(y4==1)
        if(a1>=60 && a1<100)
          if( b1<=29 && b1>20)
           if ( val>=10 && val<40)
            if(a==9 || a== 12 || a==15)
              if(b==5)
                if(d==0 || d==1 || d==2)
                 digitalWrite(0,HIGH);
    }

   if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y4==1)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==9 || a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

   if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
      if(y4==1)
       if ( val>=60)
         digitalWrite(0,LOW);
    }

  ///5///
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
      if(y5==1)  
       if(a1<100 && b1>29 && val<10)
        if(a==9 || a== 11 || a==13 || a==15)
         if(b==5)
          if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
       if(y5==1)
        if(a1>=60 && a1<100)
          if( b1<=29 && b1>20)
           if ( val>=10 && val<40)
            if(a==9 || a== 12 || a==15)
              if(b==5)
                if(d==0 || d==1 || d==2)
                 digitalWrite(0,HIGH);
    }

   if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y5==1)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==9 || a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

   if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
      if(y5==1)
       if ( val>=60)
         digitalWrite(0,LOW);
    }

  ///6///
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
      if(y6==1)  
       if(a1<100 && b1>29 && val<10)
        if(a==9 || a== 11 || a==13 || a==15)
         if(b==5)
          if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
       if(y6==1)
        if(a1>=60 && a1<100)
          if( b1<=29 && b1>20)
           if ( val>=10 && val<40)
            if(a==9 || a== 12 || a==15)
              if(b==5)
                if(d==0 || d==1 || d==2)
                 digitalWrite(0,HIGH);
    }

   if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y6==1)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==9 || a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

   if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
      if(y6==1)
       if ( val>=60)
         digitalWrite(0,LOW);
    }

  ///7///
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
      if(y7==1)  
       if(a1<100 && b1>29 && val<10)
        if(a==9 || a== 11 || a==13 || a==15)
         if(b==5)
          if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
       if(y7==1)
        if(a1>=60 && a1<100)
          if( b1<=29 && b1>20)
           if ( val>=10 && val<40)
            if(a==9 || a== 12 || a==15)
              if(b==5)
                if(d==0 || d==1 || d==2)
                 digitalWrite(0,HIGH);
    }

   if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y7==1)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==9 || a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

   if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
      if(y7==1)
       if ( val>=60)
         digitalWrite(0,LOW);
    }

  ///8///
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
      if(y8==1)  
       if(a1<100 && b1>29 && val<10)
        if(a==9 || a== 11 || a==13 || a==15)
         if(b==5)
          if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
       if(y8==1)
        if(a1>=60 && a1<100)
          if( b1<=29 && b1>20)
           if ( val>=10 && val<40)
            if(a==9 || a== 12 || a==15)
              if(b==5)
                if(d==0 || d==1 || d==2)
                 digitalWrite(0,HIGH);
    }

   if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y8==1)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==9 || a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

   if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
      if(y8==1)
       if ( val>=60)
         digitalWrite(0,LOW);
    }

  ///9///
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
      if(y9==1)  
       if(a1<100 && b1>29 && val<10)
        if(a==9 || a== 11 || a==13 || a==15)
         if(b==5)
          if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
       if(y9==1)
        if(a1>=60 && a1<100)
          if( b1<=29 && b1>20)
           if ( val>=10 && val<40)
            if(a==9 || a== 12 || a==15)
              if(b==5)
                if(d==0 || d==1 || d==2)
                 digitalWrite(0,HIGH);
    }

   if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y9==1)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==9 || a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

   if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
      if(y9==1)
       if ( val>=60)
         digitalWrite(0,LOW);
    }

  ///10///
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
      if(y10==1)  
       if(a1<100 && b1>29 && val<10)
        if(a==9 || a== 11 || a==13 || a==15)
         if(b==5)
          if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
       if(y10==1)
        if(a1>=60 && a1<100)
          if( b1<=29 && b1>20)
           if ( val>=10 && val<40)
            if(a==9 || a== 12 || a==15)
              if(b==5)
                if(d==0 || d==1 || d==2)
                 digitalWrite(0,HIGH);
    }

   if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y1==10)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==9 || a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

   if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
      if(y10==1)
       if ( val>=60)
         digitalWrite(0,LOW);
    }

  ///11///
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
      if(y1==11)  
       if(a1<100 && b1>29 && val<10)
        if(a==9 || a== 11 || a==13 || a==15)
         if(b==5)
          if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
       if(y11==1)
        if(a1>=60 && a1<100)
          if( b1<=29 && b1>20)
           if ( val>=10 && val<40)
            if(a==9 || a== 12 || a==15)
              if(b==5)
                if(d==0 || d==1 || d==2)
                 digitalWrite(0,HIGH);
    }

   if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y1==11)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==9 || a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

   if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
      if(y11==1)
       if ( val>=60)
         digitalWrite(0,LOW);
    }

  ///12///
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
      if(y12==1)  
       if(a1<100 && b1>29 && val<10)
        if(a==9 || a== 11 || a==13 || a==15)
         if(b==5)
          if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
       if(y12==1)
        if(a1>=60 && a1<100)
          if( b1<=29 && b1>20)
           if ( val>=10 && val<40)
            if(a==9 || a== 12 || a==15)
              if(b==5)
                if(d==0 || d==1 || d==2)
                 digitalWrite(0,HIGH);
    }

   if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y12==1)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==9 || a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

   if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
      if(y12==1)
       if ( val>=60)
         digitalWrite(0,LOW);
    }

//////////////////////////////////////////FOR LEAST WATER///////////////////////////////////////////////
    ///1///
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y1==4)
      if(a1<100 && b1>29 && val<10)
       if(a==10 || a== 12 || a==14)
        if(b==5)
         if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y1==4) 
      if(a1>=60 && a1<100)
       if( b1<=29 && b1>20)
        if ( val>=10 && val<40)
          if(a==9 || a== 11 )
        if(b==5)
         if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y1==4)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
          if(a==15 )
        if(b==5)
         if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
       if(y1==4)
        if ( val>=60)
           digitalWrite(0,LOW);
    }


    ///2///
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y2==4)
      if(a1<100 && b1>29 && val<10)
       if(a==10 || a== 12 || a==14)
        if(b==5)
         if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y2==4) 
      if(a1>=60 && a1<100)
       if( b1<=29 && b1>20)
        if ( val>=10 && val<40)
          if(a==9 || a== 11 )
        if(b==5)
         if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y2==4)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
          if(a==15 )
        if(b==5)
         if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
       if(y2==4)
        if ( val>=60)
           digitalWrite(0,LOW);
    }
        ///3///
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y3==4)
      if(a1<100 && b1>29 && val<10)
       if(a==10 || a== 12 || a==14)
        if(b==5)
         if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y3==4) 
      if(a1>=60 && a1<100)
       if( b1<=29 && b1>20)
        if ( val>=10 && val<40)
          if(a==9 || a== 11 )
        if(b==5)
         if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y3==4)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
          if(a==15 )
        if(b==5)
         if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
       if(y3==4)
        if ( val>=60)
           digitalWrite(0,LOW);
    }
        ///4///
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y4==4)
      if(a1<100 && b1>29 && val<10)
       if(a==10 || a== 12 || a==14)
        if(b==5)
         if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y4==4) 
      if(a1>=60 && a1<100)
       if( b1<=29 && b1>20)
        if ( val>=10 && val<40)
          if(a==9 || a== 11 )
        if(b==5)
         if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y4==4)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
          if(a==15 )
        if(b==5)
         if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
       if(y4==4)
        if ( val>=60)
           digitalWrite(0,LOW);
    }
        ///5///
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y1==5)
      if(a1<100 && b1>29 && val<10)
       if(a==10 || a== 12 || a==14)
        if(b==5)
         if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y5==4) 
      if(a1>=60 && a1<100)
       if( b1<=29 && b1>20)
        if ( val>=10 && val<40)
          if(a==9 || a== 11 )
        if(b==5)
         if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y5==4)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
          if(a==15 )
        if(b==5)
         if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
       if(y5==4)
        if ( val>=60)
           digitalWrite(0,LOW);
    }
        ///6///
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y6==4)
      if(a1<100 && b1>29 && val<10)
       if(a==10 || a== 12 || a==14)
        if(b==5)
         if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y6==4) 
      if(a1>=60 && a1<100)
       if( b1<=29 && b1>20)
        if ( val>=10 && val<40)
          if(a==9 || a== 11 )
        if(b==5)
         if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y6==4)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
          if(a==15 )
        if(b==5)
         if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
       if(y6==4)
        if ( val>=60)
           digitalWrite(0,LOW);
    }
        ///7///
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y7==4)
      if(a1<100 && b1>29 && val<10)
       if(a==10 || a== 12 || a==14)
        if(b==5)
         if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y7==4) 
      if(a1>=60 && a1<100)
       if( b1<=29 && b1>20)
        if ( val>=10 && val<40)
         if(a==9 || a== 11 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y7==4)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y7==4)
      if ( val>=60)
       digitalWrite(0,LOW);
    }
        ///8///
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y8==4)
      if(a1<100 && b1>29 && val<10)
       if(a==10 || a== 12 || a==14)
        if(b==5)
         if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y8==4) 
      if(a1>=60 && a1<100)
       if( b1<=29 && b1>20)
        if ( val>=10 && val<40)
         if(a==9 || a== 11 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y8==4)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
       if(y8==4)
        if ( val>=60)
         digitalWrite(0,LOW);
    }
        ///9///
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y9==4)
      if(a1<100 && b1>29 && val<10)
       if(a==10 || a== 12 || a==14)
        if(b==5)
         if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y9==4) 
      if(a1>=60 && a1<100)
       if( b1<=29 && b1>20)
        if ( val>=10 && val<40)
         if(a==9 || a== 11 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y9==4)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y9==4)
      if ( val>=60)
       digitalWrite(0,LOW);
    }
        ///10///
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y10==4)
      if(a1<100 && b1>29 && val<10)
       if(a==10 || a== 12 || a==14)
        if(b==5)
         if(d==0 || d==1 || d==2)
          digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y10==4) 
      if(a1>=60 && a1<100)
       if( b1<=29 && b1>20)
        if ( val>=10 && val<40)
         if(a==9 || a== 11 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y10==4)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y10==4)
      if ( val>=60)
        digitalWrite(0,LOW);
    }
        ///11///
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y11==4)
      if(a1<100 && b1>29 && val<10)
       if(a==10 || a== 12 || a==14)
        if(b==5)
         if(d==0 || d==1 || d==2)
          digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y11==4) 
      if(a1>=60 && a1<100)
       if( b1<=29 && b1>20)
        if ( val>=10 && val<40)
         if(a==9 || a== 11 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y11==4)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
      if(y11==4)
       if ( val>=60)
        digitalWrite(0,LOW);
    }
     
        ///12///
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y12==4)
      if(a1<100 && b1>29 && val<10)
       if(a==10 || a== 12 || a==14)
        if(b==5)
         if(d==0 || d==1 || d==2)
          digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y12==4) 
      if(a1>=60 && a1<100)
       if( b1<=29 && b1>20)
        if ( val>=10 && val<40)
         if(a==9 || a== 11 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y12==4)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y12==4)
      if ( val>=60)
       digitalWrite(0,LOW);
    }

//////////////////////////////////////////MEDIUM/////////////////////////////////////////////
//1//
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y1==3)
      if(a1<100 && b1>29 && val<10)
       if(a==10 || a== 12 || a==15)
        if(b==5)
         if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y1==3)
      if(a1>=60 && a1<100)
       if( b1<=29 && b1>20)
        if ( val>=10 && val<40)
         if(a==9 || a== 10 || a==15)
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y1==3)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==11 || a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y1==3)
      if ( val>=60)
       digitalWrite(0,LOW);
    }


//2//
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y2==3)
      if(a1<100 && b1>29 && val<10)
       if(a==10 || a== 12 || a==15)
        if(b==5)
         if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y2==3)
      if(a1>=60 && a1<100)
       if( b1<=29 && b1>20)
        if ( val>=10 && val<40)
         if(a==9 || a== 10 || a==15)
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y2==3)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==11 || a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y2==3)
      if ( val>=60)
       digitalWrite(0,LOW);
    }


//3//
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y3==3)
      if(a1<100 && b1>29 && val<10)
       if(a==10 || a== 12 || a==15)
        if(b==5)
         if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y3==3)
      if(a1>=60 && a1<100)
       if( b1<=29 && b1>20)
        if ( val>=10 && val<40)
         if(a==9 || a== 10 || a==15)
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y3==3)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==11 || a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y3==3)
      if ( val>=60)
       digitalWrite(0,LOW);
    }


//4//
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y4==3)
      if(a1<100 && b1>29 && val<10)
       if(a==10 || a== 12 || a==15)
        if(b==5)
         if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y4==3)
      if(a1>=60 && a1<100)
       if( b1<=29 && b1>20)
        if ( val>=10 && val<40)
         if(a==9 || a== 10 || a==15)
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y4==3)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==11 || a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y4==3)
      if ( val>=60)
       digitalWrite(0,LOW);
    }


//5//
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y5==3)
      if(a1<100 && b1>29 && val<10)
       if(a==10 || a== 12 || a==15)
        if(b==5)
         if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y5==3)
      if(a1>=60 && a1<100)
       if( b1<=29 && b1>20)
        if ( val>=10 && val<40)
         if(a==9 || a== 10 || a==15)
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y5==3)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==11 || a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y5==3)
      if ( val>=60)
       digitalWrite(0,LOW);
    }


//6//
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y6==3)
      if(a1<100 && b1>29 && val<10)
       if(a==10 || a== 12 || a==15)
        if(b==5)
         if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y6==3)
      if(a1>=60 && a1<100)
       if( b1<=29 && b1>20)
        if ( val>=10 && val<40)
         if(a==9 || a== 10 || a==15)
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y6==3)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==11 || a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y6==3)
      if ( val>=60)
       digitalWrite(0,LOW);
    }


//7//
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y7==3)
      if(a1<100 && b1>29 && val<10)
       if(a==10 || a== 12 || a==15)
        if(b==5)
         if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y7==3)
      if(a1>=60 && a1<100)
       if( b1<=29 && b1>20)
        if ( val>=10 && val<40)
         if(a==9 || a== 10 || a==15)
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y7==3)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==11 || a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y7==3)
      if ( val>=60)
       digitalWrite(0,LOW);
    }


//8//
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y8==3)
      if(a1<100 && b1>29 && val<10)
       if(a==10 || a== 12 || a==15)
        if(b==5)
         if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y8==3)
      if(a1>=60 && a1<100)
       if( b1<=29 && b1>20)
        if ( val>=10 && val<40)
         if(a==9 || a== 10 || a==15)
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y8==3)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==11 || a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y8==3)
      if ( val>=60)
       digitalWrite(0,LOW);
    }


//9//
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y9==3)
      if(a1<100 && b1>29 && val<10)
       if(a==10 || a== 12 || a==15)
        if(b==5)
         if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y9==3)
      if(a1>=60 && a1<100)
       if( b1<=29 && b1>20)
        if ( val>=10 && val<40)
         if(a==9 || a== 10 || a==15)
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y9==3)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==11 || a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y9==3)
      if ( val>=60)
       digitalWrite(0,LOW);
    }


//10//
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y10==3)
      if(a1<100 && b1>29 && val<10)
       if(a==10 || a== 12 || a==15)
        if(b==5)
         if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y10==3)
      if(a1>=60 && a1<100)
       if( b1<=29 && b1>20)
        if ( val>=10 && val<40)
         if(a==9 || a== 10 || a==15)
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y10==3)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==11 || a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y10==3)
      if ( val>=60)
       digitalWrite(0,LOW);
    }


//11//
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y11==3)
      if(a1<100 && b1>29 && val<10)
       if(a==10 || a== 12 || a==15)
        if(b==5)
         if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y11==3)
      if(a1>=60 && a1<100)
       if( b1<=29 && b1>20)
        if ( val>=10 && val<40)
         if(a==9 || a== 10 || a==15)
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y11==3)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==11 || a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y11==3)
      if ( val>=60)
       digitalWrite(0,LOW);
    }

//12//
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y12==3)
      if(a1<100 && b1>29 && val<10)
       if(a==10 || a== 12 || a==15)
        if(b==5)
         if(d==0 || d==1 || d==2)
           digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y12==3)
      if(a1>=60 && a1<100)
       if( b1<=29 && b1>20)
        if ( val>=10 && val<40)
         if(a==9 || a== 10 || a==15)
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y12==3)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==11 || a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y12==3)
      if ( val>=60)
       digitalWrite(0,LOW);
    }


///////////////////////////////////////////////HIGH//////////////////////////////////////////////////////

///1///
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y1==2)
      if(a1<100 && b1>29 && val<10)
       if(a==9 || a== 10 || a==14 || a==15)
        if(b==5)
         if(d==0 || d==1 || d==2)
          digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y1==2)
      if(a1>=60 && a1<100)
       if( b1<=29 && b1>20)
        if ( val>=10 && val<40)
         if(a==9 || a== 10 || a==15)
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y1==2)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==9 || a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y1==2)
      if ( val>=60)
       digitalWrite(0,LOW);
    }

///2///
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y2==2)
      if(a1<100 && b1>29 && val<10)
       if(a==9 || a== 10 || a==14 || a==15)
        if(b==5)
         if(d==0 || d==1 || d==2)
          digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y2==2)
      if(a1>=60 && a1<100)
       if( b1<=29 && b1>20)
        if ( val>=10 && val<40)
         if(a==9 || a== 10 || a==15)
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y2==2)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==9 || a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y2==2)
      if ( val>=60)
       digitalWrite(0,LOW);
    }


///3///
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y3==2)
      if(a1<100 && b1>29 && val<10)
       if(a==9 || a== 10 || a==14 || a==15)
        if(b==5)
         if(d==0 || d==1 || d==2)
          digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y3==2)
      if(a1>=60 && a1<100)
       if( b1<=29 && b1>20)
        if ( val>=10 && val<40)
         if(a==9 || a== 10 || a==15)
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y3==2)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==9 || a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y3==2)
      if ( val>=60)
       digitalWrite(0,LOW);
    }


///4///
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y4==2)
      if(a1<100 && b1>29 && val<10)
       if(a==9 || a== 10 || a==14 || a==15)
        if(b==5)
         if(d==0 || d==1 || d==2)
          digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y4==2)
      if(a1>=60 && a1<100)
       if( b1<=29 && b1>20)
        if ( val>=10 && val<40)
         if(a==9 || a== 10 || a==15)
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y4==2)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==9 || a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y4==2)
      if ( val>=60)
       digitalWrite(0,LOW);
    }


///5///
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y5==2)
      if(a1<100 && b1>29 && val<10)
       if(a==9 || a== 10 || a==14 || a==15)
        if(b==5)
         if(d==0 || d==1 || d==2)
          digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y5==2)
      if(a1>=60 && a1<100)
       if( b1<=29 && b1>20)
        if ( val>=10 && val<40)
         if(a==9 || a== 10 || a==15)
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y5==2)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==9 || a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y5==2)
      if ( val>=60)
       digitalWrite(0,LOW);
    }


///6///
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y6==2)
      if(a1<100 && b1>29 && val<10)
       if(a==9 || a== 10 || a==14 || a==15)
        if(b==5)
         if(d==0 || d==1 || d==2)
          digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y6==2)
      if(a1>=60 && a1<100)
       if( b1<=29 && b1>20)
        if ( val>=10 && val<40)
         if(a==9 || a== 10 || a==15)
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y6==2)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==9 || a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y6==2)
      if ( val>=60)
       digitalWrite(0,LOW);
    }


///7///
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y7==2)
      if(a1<100 && b1>29 && val<10)
       if(a==9 || a== 10 || a==14 || a==15)
        if(b==5)
         if(d==0 || d==1 || d==2)
          digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y7==2)
      if(a1>=60 && a1<100)
       if( b1<=29 && b1>20)
        if ( val>=10 && val<40)
         if(a==9 || a== 10 || a==15)
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y7==2)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==9 || a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y7==2)
      if ( val>=60)
       digitalWrite(0,LOW);
    }


///8///
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y8==2)
      if(a1<100 && b1>29 && val<10)
       if(a==9 || a== 10 || a==14 || a==15)
        if(b==5)
         if(d==0 || d==1 || d==2)
          digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y8==2)
      if(a1>=60 && a1<100)
       if( b1<=29 && b1>20)
        if ( val>=10 && val<40)
         if(a==9 || a== 10 || a==15)
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y8==2)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==9 || a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y8==2)
      if ( val>=60)
       digitalWrite(0,LOW);
    }


///9///
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y9==2)
      if(a1<100 && b1>29 && val<10)
       if(a==9 || a== 10 || a==14 || a==15)
        if(b==5)
         if(d==0 || d==1 || d==2)
          digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y9==2)
      if(a1>=60 && a1<100)
       if( b1<=29 && b1>20)
        if ( val>=10 && val<40)
         if(a==9 || a== 10 || a==15)
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y9==2)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==9 || a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y9==2)
      if ( val>=60)
       digitalWrite(0,LOW);
    }




///10///
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y10==2)
      if(a1<100 && b1>29 && val<10)
       if(a==9 || a== 10 || a==14 || a==15)
        if(b==5)
         if(d==0 || d==1 || d==2)
          digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y10==2)
      if(a1>=60 && a1<100)
       if( b1<=29 && b1>20)
        if ( val>=10 && val<40)
         if(a==9 || a== 10 || a==15)
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y10==2)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==9 || a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y10==2)
      if ( val>=60)
       digitalWrite(0,LOW);
    }


///11///
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y11==2)
      if(a1<100 && b1>29 && val<10)
       if(a==9 || a== 10 || a==14 || a==15)
        if(b==5)
         if(d==0 || d==1 || d==2)
          digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y11==2)
      if(a1>=60 && a1<100)
       if( b1<=29 && b1>20)
        if ( val>=10 && val<40)
         if(a==9 || a== 10 || a==15)
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y11==2)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==9 || a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y11==2)
      if ( val>=60)
       digitalWrite(0,LOW);
    }


///12///
    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y12==2)
      if(a1<100 && b1>29 && val<10)
       if(a==9 || a== 10 || a==14 || a==15)
        if(b==5)
         if(d==0 || d==1 || d==2)
          digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y12==2)
      if(a1>=60 && a1<100)
       if( b1<=29 && b1>20)
        if ( val>=10 && val<40)
         if(a==9 || a== 10 || a==15)
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y12==2)
      if(a1>=60)
       if( b1<=29)
        if ( val>=40 && val<=55)
         if(a==9 || a==15 )
          if(b==5)
           if(d==0 || d==1 || d==2)
            digitalWrite(0,HIGH);
    }

    if(z1==1 || z1==2 || z1==3 || z1==4 || z1==5 || z1==6 || z1==7 || z1==8 || z1==9 || z1==10 || z1==11 || z1==12){
     if(y12==2)
      if ( val>=60)
       digitalWrite(0,LOW);
    }


/// all off
       if(a==10 ||a==11 || a==12 || a==13 || a==14 || a==15 || a==16)
        if(b==0)
         if(d==0 || d==1 || d==2)
           digitalWrite(0,LOW);


    delay(2000);   
    }
 }


 if(state!=1)
 {         turn1: 
           lcd.clear();
            lcd.setCursor(0, 0); 
           lcd.print("ENTER NUMBER TO"); 
           
            lcd.setCursor(0, 1); 
           lcd.print("ADD");
            z2 = keypad.waitForKey();
            lcd.setCursor(6, 1);
            lcd.print(z2);
             delay(500);
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("ENTER WATER REQ");
            z3=keypad.waitForKey();
            lcd.setCursor(6, 1);
            lcd.print(z2);
            delay(500);
                    if(z2==1)
                    EEPROM.update(1,z3);
                    if(z2==2)
                    EEPROM.update(2,z3);
                    if(z2==3)
                    EEPROM.update(3,z3);
                    if(z2==4)
                    EEPROM.update(4,z3);
                    if(z2==5)
                    EEPROM.update(5,z3);
                    if(z2==6)
                    EEPROM.update(6,z3);
                    if(z2==7)
                    EEPROM.update(7,z3);
                    if(z2==8)
                    EEPROM.update(8,z3);
                    if(z2==9)
                    EEPROM.update(9,z3);
                    if(z2==10)
                    EEPROM.update(10,z3);
                    if(z2==11)
                    EEPROM.update(11,z3);
                    if(z2==12)
                    EEPROM.update(12,z3);
                  
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("   RECORDED");
            delay(500);
            lcd.clear();
    }
 }
