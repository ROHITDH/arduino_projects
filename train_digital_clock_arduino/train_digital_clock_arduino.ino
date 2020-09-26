/*BY DVR TECHNOLOGIES
since 2019
this project is created on 22/07/2019 11:45 pm by rohit_d_h*/

#include <RTClib.h>
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);



RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday" ,"Friday","Saturday"};

void setup () {
    pinMode(13,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(3,OUTPUT);

  digitalWrite(13,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(3,HIGH);
  lcd.begin(16, 2);
    
  
    
    Serial.begin(9600);
    
    
    digitalWrite(6,LOW);
    digitalWrite(5,LOW);
    
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

 if(a<=9)
 {
 lcd.setCursor(0, 1);
 lcd.print("0");
 lcd.setCursor(1, 1);
 lcd.print(a);
 lcd.setCursor(2,1);
 lcd.print(":");
 }
 
 if(a>9)
 {
 lcd.setCursor(0, 1);
 lcd.print(a);
 lcd.setCursor(2,1);
 lcd.print(":"); 
 }

 if(b<=9)
 {lcd.setCursor(3,1);
  lcd.print("0");
  lcd.setCursor(11,1);
  lcd.print("0");
  lcd.setCursor(4,1);
  lcd.print(b); 
  lcd.setCursor(12,1);
  lcd.print(b);
  lcd.setCursor(13,1);
  lcd.print(" "); 
 }
 if(b>9)
 { lcd.setCursor(3,1);
   lcd.print(b);
   lcd.setCursor(11,1);
   lcd.print(b);
  } 

  if(a>00 && a<12)
     { 
       if(a>0 && a<=9)
         {
           lcd.setCursor(8,1);
           lcd.print("0"); 
 
           lcd.setCursor(9, 1); 
           lcd.print(a); 
           lcd.setCursor(10, 1);
           lcd.print(":");
           lcd.setCursor(14, 1);
           lcd.print("AM");
         }
       else
         {
          lcd.setCursor(8, 1); 
           lcd.print(a); 
           lcd.setCursor(10, 1);
           lcd.print(":");
           lcd.setCursor(14, 1);
           lcd.print("AM");
         }
     }
         
    
    else if(a==12)
     {
       lcd.setCursor(8, 1);
       lcd.print(a); 
       lcd.setCursor(10, 1);
       lcd.print(":");
       lcd.setCursor(14, 1);
       lcd.print("PM");
     }
      
   else if(a==00)
   {
    lcd.setCursor(8, 1);
    lcd.print("12"); 
    lcd.setCursor(10, 1);
    lcd.print(":");
    lcd.setCursor(14, 1);
    lcd.print("AM");
   }
      
    else
    {
      z=a-12;
      if(z>=1 && z<=9)
      {
      lcd.setCursor(8, 1);
      lcd.print("0");
      lcd.setCursor(9, 1);
      lcd.print(z); 
      lcd.setCursor(10, 1);
      lcd.print(":");
      lcd.setCursor(14, 1);
      lcd.print("PM");
      }

      if(z>9)
      {
      lcd.setCursor(8, 1);
      lcd.print(z); 
      lcd.setCursor(10, 1);
      lcd.print(":");
      lcd.setCursor(14, 1);
      lcd.print("PM");
      }



}

if(a==9)
 if (b>=0 && b<=59)
 {lcd.setCursor(3,0);
  lcd.print("MUMBAI-AHAMAD");
  delay(400);
  lcd.setCursor(2,0);
  lcd.print("MUMBAI-AHAMADA");
  delay(400);
  lcd.setCursor(1,0);
  lcd.print("MUMBAI-AHAMADAB");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("MUMBAI-AHAMADABA");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("UMBAI-AHAMADABAD");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("MBAI-AHAMADABAD ");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("BAI-AHAMADABAD 1");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("AI-AHAMADABAD 10");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("AI-AHAMADABAD 10:");
  delay(50);
  lcd.setCursor(0,0);
  lcd.print("I-AHAMADABAD 10:0");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("-AHAMADABAD 10:00");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("AHAMADABAD 10:00 ");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("HAMADABAD 10:00  ");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("AMADABAD 10:00   ");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("MADABAD 10:00    ");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("                ");
 }  

 if(a==10)
 if (b>=0 && b<=50)
 {lcd.setCursor(3,0);
  lcd.print("KOLKATTA-PURI");
  delay(400);
  lcd.setCursor(2,0);
  lcd.print("KOLKATTA-PURI ");
  delay(400);
  lcd.setCursor(1,0);
  lcd.print("KOLKATTA-PURI 1");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("KOLKATTA-PURI 10");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("OLKATTA-PURI 10:");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("LKATTA-PURI 10:5");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("KATTA-PURI 10:51");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("ATTA-PURI 10:51 ");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("TTA-PURI 10:51  ");
  delay(50);
  lcd.setCursor(0,0);
  lcd.print("TA-PURI 10:51   ");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("                ");
 }  

 if(a==11)
 if (b>=0 && b<=59)
 {lcd.setCursor(3,0);
  lcd.print("MANGALORE-KUM");
  delay(400);
  lcd.setCursor(2,0);
  lcd.print("MANGALORE-KUMA");
  delay(400);
  lcd.setCursor(1,0);
  lcd.print("MANGALORE-KUMAT");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("MANGALORE-KUMATA");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("ANGALORE-KUMATA ");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("NGALORE-KUMATA 1");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("GALORE-KUMATA 12");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("ALORE-KUMATA 12:");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("LORE-KUMATA 12:0");
  delay(50);
  lcd.setCursor(0,0);
  lcd.print("ORE-KUMATA 12:00");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("RE-KUMATA 12:00 ");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("E-KUMATA 12:00  ");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("-KUMATA 12:00   ");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("                ");
 }  

if(a==12)
 if (b>=0 && b<=53)
 {lcd.setCursor(3,0);
  lcd.print("PUNE- NEW DEL");
  delay(400);
  lcd.setCursor(2,0);
  lcd.print("PUNE- NEW DELH");
  delay(400);
  lcd.setCursor(1,0);
  lcd.print("PUNE- NEW DELHI");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("PUNE- NEW DELHI ");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("UNE- NEW DELHI 1");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("NE- NEW DELHI 12");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("E- NEW DELHI 12:");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("- NEW DELHI 12:5");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print(" NEW DELHI 12:54");
  delay(50);
  lcd.setCursor(0,0);
  lcd.print("NEW DELHI 12:54 ");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("                ");
 }  

if(a==13)
 if (b>=0 && b<=59)
 {lcd.setCursor(3,0);
  lcd.print("PUNE-JAMMU TA");
  delay(400);
  lcd.setCursor(2,0);
  lcd.print("PUNE-JAMMU TAW");
  delay(400);
  lcd.setCursor(1,0);
  lcd.print("PUNE-JAMMU TAWI");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("PUNE-JAMMU TAWI ");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("UNE-JAMMU TAWI 1");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("NE-JAMMU TAWI 14");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("E-JAMMU TAWI 14:");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("-JAMMU TAWI 14:0");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("JAMMU TAWI 14:00");
  delay(50);
  lcd.setCursor(0,0);
  lcd.print("AMMU TAWI 14:00 ");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("MMU TAWI 14:00  ");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("MU TAWI 14:00   ");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("U TAWI 14:00    ");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print(" TAWI 14:00     ");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("                ");
 }  


if(a==14)
 if (b>=0 && b<=59)
 {lcd.setCursor(3,0);
  lcd.print("MANGALORE-BAN");
  delay(400);
  lcd.setCursor(2,0);
  lcd.print("MANGALORE-BANG");
  delay(400);
  lcd.setCursor(1,0);
  lcd.print("MANGALORE-BANGA");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("MANGALORE-BANGAL");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("ANGALORE-BANGALO");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("NGALORE-BANGALOR");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("GALORE-BANGALORE");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("ALORE-BANGALORE ");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("LORE-BANGALORE 1");
  delay(50);
  lcd.setCursor(0,0);
  lcd.print("LORE-BANGALORE 15");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("ORE-BANGALORE 15:");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("RE-BANGALORE 15:0");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("E-BANGALORE 15:00");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("-BANGALORE 15:00 ");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("BANGALORE 15:00  ");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("ANGALORE 15:00   ");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("NGALORE 15:00    ");
  delay(400);
  lcd.setCursor(0,0);
  lcd.print("                ");
 }  
if(a>15 && a<=22)
 if(b>=0 && b<=59)
  {lcd.setCursor(0,0);
  lcd.print("PUNE-HUBLI 23:02");
  delay(500);
  lcd.setCursor(0,0);
  lcd.print("                ");
 }

if(a>1 && a<8)
  if(b<=59)
  { lcd.setCursor(0,0);
  lcd.print("PUNE-UDUPI 09:01");
  delay(500);
  lcd.setCursor(0,0);
  lcd.print("                ");
  }
}
