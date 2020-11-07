/*BY DVR TECHNOLOGIES
since 2019
this project is created on 23/3/2019  1:05 am by rohit_d_h*/

#include <RTClib.h>
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);



RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup () {
  lcd.begin(16, 2);
    pinMode(6,OUTPUT);
    pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);

digitalWrite(9,HIGH);
digitalWrite(10,HIGH);
    digitalWrite(6,HIGH);
  Serial.begin(9600);

  delay(3000); // wait for console opening

  if (! rtc.begin()) {
    Serial.println("NO RTC");
    while (1);
  }

 
}

void loop () {  
  int a,b,c,i,z,d;
    DateTime now = rtc.now();
    
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
    
      a=now.hour();
    b=now.minute();
    c=now.dayOfTheWeek();
    d=now.second();

     Serial.println(a);
    Serial.println(b);
    Serial.println(c);
    Serial.println(d);

    

 
 lcd.setCursor(0, 1);
 lcd.print("CANARA ENGG.");

    if(a>00 && a<12)
     { 
       if(a>0 && a<=9)
         {
           lcd.setCursor(4, 0); 
           lcd.print(a); 
           lcd.setCursor(5, 0);
           lcd.print(" ");
           lcd.setCursor(6, 0);
           lcd.print(":");
           lcd.setCursor(10, 0);
           lcd.print("AM");
         }
       else
         {
          lcd.setCursor(4, 0); 
           lcd.print(a); 
           lcd.setCursor(6, 0);
           lcd.print(":");
           lcd.setCursor(10, 0);
           lcd.print("AM");
         }
     }
         
    
    else if(a==12)
     {
       lcd.setCursor(4, 0);
       lcd.print(a); 
       lcd.setCursor(6, 0);
       lcd.print(":");
       lcd.setCursor(10, 0);
       lcd.print("PM");
     }
      
   else if(a==00)
   {
    lcd.setCursor(4, 0);
    lcd.print("12"); 
    lcd.setCursor(6, 0);
    lcd.print(":");
    lcd.setCursor(10, 0);
    lcd.print("AM");
   }
      
    else
    {
      z=a-12;
      lcd.setCursor(4, 0);
      lcd.print(z); 
      lcd.setCursor(6, 0);
      lcd.print(":");
      lcd.setCursor(10, 0);
      lcd.print("PM");
    }

   if(b>=0 && b<=9)
   {
    lcd.setCursor(7, 0);
    lcd.print(b);
    lcd.setCursor(8, 0);
    lcd.print(" ");
   }
    else
    {
      lcd.setCursor(7, 0);
      lcd.print(b);
    }
    
    
    if(c==1 || c==3 || c==5 || c==7)
   {
        if(a==9 && b==0 && d==0)
        {digitalWrite(7,HIGH);
        delay(2000);
        digitalWrite(8,HIGH);
        delay(1200);
        lcd.setCursor(0, 0);
        lcd.print("   SHIRAGANI    ");
        
        
        digitalWrite(8,LOW);
        lcd.setCursor(0, 1);
        lcd.print("DVR SYSTEM M:ON");
        delay(10800000);
        digitalWrite(7,LOW);
        lcd.setCursor(0, 1);
        lcd.print("               ");
        lcd.setCursor(0, 0);
        lcd.print("               ");
        
        }
        

        
       
        else if(a==15 && b==0 && d==0)
        {digitalWrite(7,HIGH);
        delay(2000);
        digitalWrite(8,HIGH);
        delay(1500);
        digitalWrite(8,LOW);
        lcd.setCursor(0, 0);
        lcd.print("   SHIRAGANI    ");
        
        lcd.setCursor(0, 1);
        lcd.print("DVR SYSTEM M:ON");
        delay(10800000);
        digitalWrite(7,LOW);
        lcd.setCursor(0, 1);
        lcd.print("               ");
        
        lcd.setCursor(0, 0);
        lcd.print("               ");
        }
        else
        digitalWrite(8,LOW);
      
     
}
}
