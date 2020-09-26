/*BY DVR TECHNOLOGIES
since 2019
this project is created on 23/3/2019  1:05 am by rohit_d_h*/

#include <RTClib.h>
#include <LiquidCrystal.h>
#include <Keypad.h>
#include <EEPROM.h>

   int z1;  int y1;
   int z2;  int y2;
   int z3;  int y3;
   int z4;  int y4;
   int z5;  int y5;
   int z6;  int y6;
   int z7;  int y7;
   int z8;  int y8;
   int z9;  int y9;
   int z10; int y10;
   int z11; int y11;
   int z12; int y12;
    int sel;
    int h11,m11,m12;
    int m1;
    
   int meridian;


const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {1,2,3,10},
  {4,5,6,11},
  {7,8,9,12},
  {60,100,50,40}
};
byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {9, 8, 7, 6}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
const int rs = A0, en = A1, d4 = A2, d5 = A3, d6 = 10, d7 = 11;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int button = 12; 
int state=0;

int ir1 = 0;
int is1;

RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup () {
 pinMode(ir1, INPUT);
  
z1=EEPROM.read(0);
y1=EEPROM.read(1);
z2=EEPROM.read(2);
y2=EEPROM.read(3);
z3=EEPROM.read(4);
y3=EEPROM.read(5);
z4=EEPROM.read(6);
y4=EEPROM.read(7);
z5=EEPROM.read(8);
y5=EEPROM.read(9);
z6=EEPROM.read(10);
y6=EEPROM.read(11);
z7=EEPROM.read(12);
y7=EEPROM.read(13);
z8=EEPROM.read(14);
y8=EEPROM.read(15);
z9=EEPROM.read(16);
y9=EEPROM.read(17);
z10=EEPROM.read(18);
y10=EEPROM.read(19);
z11=EEPROM.read(20);
y11=EEPROM.read(21);
z12=EEPROM.read(22);
y12=EEPROM.read(23);

state=digitalRead(button);
  lcd.begin(16, 2);
    pinMode(13,OUTPUT);
    pinMode(0,OUTPUT);
    pinMode(12,INPUT);
    Serial.begin(9600);
   digitalWrite(0,HIGH);

Serial.println(z1);
Serial.println(y1);

Serial.println(z2);
Serial.println(y2);
Serial.println(z3);
Serial.println(y3);
Serial.println(z4);
Serial.println(y4);
Serial.println(z5);
Serial.println(y5);
Serial.println(z6);
Serial.println(y6);
Serial.println(z7);
Serial.println(y7);
Serial.println(z8);
Serial.println(y8);
Serial.println(z9);
Serial.println(y9);
Serial.println(z10);
Serial.println(y10);
Serial.println(z11);
Serial.println(y11);
Serial.println(z12);
Serial.println(y12);



    delay(3000); // wait for console opening

   if (! rtc.begin()) {
    Serial.println("NO RTC");
    while (1);
  }
}

void loop () { 
main:
  is1 = digitalRead(ir1);
 if(is1==HIGH)
{ digitalWrite(13,HIGH);
  lcd.setCursor(0, 1);
  lcd.print("DVR SYSTEM B:ON");
  delay(1000);
  digitalWrite(13,LOW);
  lcd.clear();
}
  state=digitalRead(12);
  int a,b,c,i,z,d;
  if(state==1){
 
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
      lcd.setCursor(3, 0);
      lcd.print("                ");
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
      lcd.setCursor(3, 0);
      lcd.print("                ");
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
      lcd.setCursor(3, 0);
      lcd.print("                ");
       lcd.setCursor(4, 0);
       lcd.print(a); 
       lcd.setCursor(6, 0);
       lcd.print(":");
       lcd.setCursor(10, 0);
       lcd.print("PM");
     }
      
   else if(a==00)
   {
      lcd.setCursor(3, 0);
      lcd.print("                ");
    lcd.setCursor(4, 0);
    lcd.print("12"); 
    lcd.setCursor(6, 0);
    lcd.print(":");
    lcd.setCursor(10, 0);
    lcd.print("AM");
   }
      
    else
    {
      lcd.setCursor(3, 0);
      lcd.print("                ");
      z=a-12;
      lcd.setCursor(3, 0);
      lcd.print("                ");
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
 
    
   if(c!=0)
      {  //bell 1
        if(a==z1 && b==y1 && d==0)
        {
        digitalWrite(13,HIGH);
        lcd.setCursor(0, 1);
        lcd.print("DVR SYSTEM B:ON");
        delay(8000);
        digitalWrite(13,LOW);
        lcd.setCursor(0, 1);
        lcd.print("               ");
        }
        
  //bell 2
        
        else if(a==z2 && b==y2 && d==0)
        {
        digitalWrite(13,HIGH);
        lcd.setCursor(0, 1);
        lcd.print("DVR SYSTEM B:ON");
        delay(5000);
        digitalWrite(13,LOW);
        lcd.setCursor(0, 1);
        lcd.print("               ");
        }

    //bell 3    
        else if(a==z3 && b==y3 && d==0)
        {
        digitalWrite(13,HIGH);
        lcd.setCursor(0, 1);
        lcd.print("DVR SYSTEM B:ON");
        delay(5000);
        digitalWrite(13,LOW);
        lcd.setCursor(0, 1);
        lcd.print("               ");
        }

    //bell 4
        else if(a==z4 && b==y4 && d==0)
        {
        digitalWrite(13,HIGH);
        lcd.setCursor(0, 1);
        lcd.print("DVR SYSTEM B:ON");
        delay(5000);
        digitalWrite(13,LOW);
        lcd.setCursor(0, 1);
        lcd.print("               ");
        }

  //bell 5
        else if(a==z5 && b==y5 && d==0)
        {
        digitalWrite(13,HIGH);
        lcd.setCursor(0, 1);
        lcd.print("DVR SYSTEM B:ON");
        delay(5000);
        digitalWrite(13,LOW);
        lcd.setCursor(0, 1);
        lcd.print("               ");
        }

    //bell 6
        else if(a==z6 && b==y6 && d==0)
        {
        digitalWrite(13,HIGH);
        lcd.setCursor(0, 1);
        lcd.print("DVR SYSTEM B:ON");
        delay(5000);
        digitalWrite(13,LOW);
        lcd.setCursor(0, 1);
        lcd.print("               ");
        }
        
    //bell 7
        else if(a==z7 && b==y7 && d==0)
        {
        digitalWrite(13,HIGH);
        lcd.setCursor(0, 1);
        lcd.print("DVR SYSTEM B:ON");
        delay(5000);
        digitalWrite(13,LOW);
        lcd.setCursor(0, 1);
        lcd.print("               ");
        }
        
        //bell 8
        
        else if(a==z8 && b==y8 && d==0)
        {
        digitalWrite(13,HIGH);
        lcd.setCursor(0, 1);
        lcd.print("DVR SYSTEM B:ON");
        delay(5000);
        digitalWrite(13,LOW);
        lcd.setCursor(0, 1);
        lcd.print("               ");
        }

//bell 9

        else if(a==z9 && b==y9 && d==0)
        {
        digitalWrite(13,HIGH);
        lcd.setCursor(0, 1);
        lcd.print("DVR SYSTEM B:ON");
        delay(5000);
        digitalWrite(13,LOW);
        lcd.setCursor(0, 1);
        lcd.print("               ");
        }

//bell 10

        else if(a==z10 && b==y10 && d==0)
        {
        digitalWrite(13,HIGH);
        lcd.setCursor(0, 1);
        lcd.print("DVR SYSTEM B:ON");
        delay(5000);
        digitalWrite(13,LOW);
        lcd.setCursor(0, 1);
        lcd.print("               ");
        }

 //bell 11
        else if(a==z11 && b==y11 && d==0)
        {
        digitalWrite(13,HIGH);
        lcd.setCursor(0, 1);
        lcd.print("DVR SYSTEM B:ON");
        delay(5000);
        digitalWrite(13,LOW);
        lcd.setCursor(0, 1);
        lcd.print("               ");
        }

// bell 12
        else if(a==z12 && b==y12 && d==0)
        {
        digitalWrite(13,HIGH);
        lcd.setCursor(0, 1);
        lcd.print("DVR SYSTEM B:ON");
        delay(8000);
        digitalWrite(13,LOW);
        lcd.setCursor(0, 1);
        lcd.print("               ");

        }

        else
        digitalWrite(13,LOW);
      }
     
  
}
if(state==0)
    { 
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("ENTER TIME MODE");
       sel = keypad.waitForKey();
       lcd.setCursor(1,1);
       lcd.print(sel);
       delay(1000);
       lcd.clear();
       switch(sel)
       {
         case 1:
               {
                lcd.setCursor(0,0);
                lcd.print("ENTER TIME HOUR");
                h11 = keypad.waitForKey();
                lcd.setCursor(3,1);
                lcd.print(h11);
                lcd.setCursor(6,1);
                lcd.print(":");
                lcd.setCursor(0,0);
                lcd.print("ENTER TIME MIN ");
                m11 = keypad.waitForKey();
                if(m11==100)
                   m11=0;
                
                 if(m11>=10)
                 {
                  y1=m11;
                  EEPROM.write(1,y1);
                  lcd.setCursor(8,1);
                  lcd.print(m11);
                  lcd.setCursor(0,0);
                  lcd.print("ENTER TIME AM/PM");
                  meridian = keypad.waitForKey();
                  if (meridian==50)
                    { z1=h11;
                      EEPROM.update(0,z1);
                      Serial.print("initialized value of z1 is =  ");
                      Serial.println(z1);
                      lcd.setCursor(11,1);
                      lcd.print("AM");
                      delay(300);
                    }
                  else if (meridian==40)
                    { if(h11==12)
                      z1=12;
                      else{
                      z1=h11+12;
                    EEPROM.update(0,z1);
                       Serial.println("initialized value of z1 is =");
                      lcd.setCursor(11,1);
                      lcd.print("PM");
                      delay(300);
                    }}
                  lcd.clear();
                  lcd.setCursor(0,0);
                  lcd.print("TIME 1 SUCCESS.");
                  lcd.setCursor(3,1);
                  lcd.print("RECORDED");
                  delay(5000);
                  lcd.clear();
                
                 }
                else
                { 
                lcd.setCursor(8,1);
                lcd.print(m11);
                m12 = keypad.waitForKey();
                if(m12==100)
                   m12=0;
                
                lcd.setCursor(9,1);
                lcd.print(m12);
                m1=(m11*10)+(m12*1);
                y1=m1;
                EEPROM.update(1,y1);
                 Serial.println("initialized value of y1 is =");
                lcd.setCursor(0,0);
                  lcd.print("ENTER TIME AM/PM");
                  meridian = keypad.waitForKey();
                  if (meridian==50)
                    { z1=h11;
                    EEPROM.update(0,z1);
                     Serial.println("initialized value of z1 is =");
                      lcd.setCursor(11,1);
                      lcd.print("AM");
                      delay(300);
                    }
                  else if (meridian==40)
                    { if(h11==12)
                      z1=12;
                      else{
                      z1=h11+12;
                    EEPROM.update(0,z1);
                     Serial.println("initialized value of z1 is =");
                      lcd.setCursor(11,1);
                      lcd.print("PM");
                      delay(300);
                    }}
                  lcd.clear();
                  lcd.setCursor(0,0);
                  lcd.print("TIME 1 SUCCESS.");
                  lcd.setCursor(3,1);
                  lcd.print("RECORDED");
                  delay(5000);
                  lcd.clear();
                   }
       
       }
       break;

       case 2 :
       {
        lcd.setCursor(0,0);
                lcd.print("ENTER TIME HOUR");
                h11 = keypad.waitForKey();
                lcd.setCursor(3,1);
                lcd.print(h11);
                lcd.setCursor(6,1);
                lcd.print(":");
                lcd.setCursor(0,0);
                lcd.print("ENTER TIME MIN ");
                m11 = keypad.waitForKey();
                if(m11==100)
                   m11=0;
                
                 if(m11>=10)
                 {
                  y2=m11;
                  EEPROM.update(3,y2);
                  lcd.setCursor(8,1);
                  lcd.print(m11);
                  lcd.setCursor(0,0);
                  lcd.print("ENTER TIME AM/PM");
                  meridian = keypad.waitForKey();
                  if (meridian==50)
                    { z2=h11;
                      EEPROM.update(2,z2);
                      Serial.println("initialized value of z2 is =  " );
                      
                      lcd.setCursor(11,1);
                      lcd.print("AM");
                      delay(300);
                    }
                  else if (meridian==40)
                    { if(h11==12)
                      z2=12;
                      else{
                      z2=h11+12;
                    EEPROM.update(2,z2);
                       Serial.println("initialized value of z2 is =" );
                      lcd.setCursor(11,1);
                      lcd.print("PM");
                      delay(300);
                    }}
                  lcd.clear();
                  lcd.setCursor(0,0);
                  lcd.print("TIME 2 SUCCESS.");
                  lcd.setCursor(3,1);
                  lcd.print("RECORDED");
                  delay(5000);
                  lcd.clear();
                
                 }
                else
                { 
                lcd.setCursor(8,1);
                lcd.print(m11);
                m12 = keypad.waitForKey();
                if(m12==100)
                   m12=0;
                
                lcd.setCursor(9,1);
                lcd.print(m12);
                m1=(m11*10)+(m12*1);
                y2=m1;
                EEPROM.update(3,y2);
                 Serial.println("initialized value of y2 is =");
                lcd.setCursor(0,0);
                  lcd.print("ENTER TIME AM/PM");
                  meridian = keypad.waitForKey();
                  if (meridian==50)
                    { z2=h11;
                    EEPROM.update(2,z2);
                     Serial.println("initialized value of z2 is =" );
                      lcd.setCursor(11,1);
                      lcd.print("AM");
                      delay(300);
                    }
                  else if (meridian==40)
                    { if(h11==12)
                      z2=12;
                      else{
                      z2=h11+12;
                    EEPROM.update(2,z2);
                     Serial.println("initialized value of z2 is =");
                      lcd.setCursor(11,1);
                      lcd.print("PM");
                      delay(300);
                    }}
                  lcd.clear();
                  lcd.setCursor(0,0);
                  lcd.print("TIME 2 SUCCESS.");
                  lcd.setCursor(3,1);
                  lcd.print("RECORDED");
                  delay(5000);
                  lcd.clear();
                }
       }
       break;

       case 3:
       {
        lcd.setCursor(0,0);
                lcd.print("ENTER TIME HOUR");
                h11 = keypad.waitForKey();
                lcd.setCursor(3,1);
                lcd.print(h11);
                lcd.setCursor(6,1);
                lcd.print(":");
                lcd.setCursor(0,0);
                lcd.print("ENTER TIME MIN ");
                m11 = keypad.waitForKey();
                if(m11==100)
                   m11=0;
                
                 if(m11>=10)
                 {
                  y3=m11;
                  EEPROM.update(5,y3);
                  lcd.setCursor(8,1);
                  lcd.print(m11);
                  lcd.setCursor(0,0);
                  lcd.print("ENTER TIME AM/PM");
                  meridian = keypad.waitForKey();
                  if (meridian==50)
                    { z3=h11;
                      EEPROM.update(4,z3);
                      Serial.println("initialized value of z3 is ="  );
                      lcd.setCursor(11,1);
                      lcd.print("AM");
                      delay(300);
                    }
                  else if (meridian==40)
                    { if(h11==12)
                      z3=12;
                      else{
                      z3=h11+12;
                    EEPROM.update(4,z3);
                       Serial.println("initialized value of z3 is =" );
                      lcd.setCursor(11,1);
                      lcd.print("PM");
                      delay(300);
                    }}
                  lcd.clear();
                  lcd.setCursor(0,0);
                  lcd.print("TIME 3 SUCCESS.");
                  lcd.setCursor(3,1);
                  lcd.print("RECORDED");
                  delay(5000);
                  lcd.clear();
                
                 }
                else
                { 
                lcd.setCursor(8,1);
                lcd.print(m11);
                m12 = keypad.waitForKey();
                if(m12==100)
                   m12=0;
                
                lcd.setCursor(9,1);
                lcd.print(m12);
                m1=(m11*10)+(m12*1);
                y3=m1;
                EEPROM.update(5,y3);
                 Serial.println("initialized value of y3 is ="  );
                lcd.setCursor(0,0);
                  lcd.print("ENTER TIME AM/PM");
                  meridian = keypad.waitForKey();
                  if (meridian==50)
                    { z3=h11;
                    EEPROM.update(4,z3);
                     Serial.println("initialized value of z3 is =" );
                      lcd.setCursor(11,1);
                      lcd.print("AM");
                      delay(300);
                    }
                  else if (meridian==40)
                    { if(h11==12)
                      z3=12;
                      else{
                      z3=h11+12;
                    EEPROM.update(4,z3);
                     Serial.println("initialized value of z3 is ="  );
                      lcd.setCursor(11,1);
                      lcd.print("PM");
                      delay(300);
                    }}
                  lcd.clear();
                  lcd.setCursor(0,0);
                  lcd.print("TIME 3 SUCCESS.");
                  lcd.setCursor(3,1);
                  lcd.print("RECORDED");
                  delay(5000);
                  lcd.clear();
                   }
       
       }break;
       case 4:
       {
                lcd.setCursor(0,0);
                lcd.print("ENTER TIME HOUR");
                h11 = keypad.waitForKey();
                lcd.setCursor(3,1);
                lcd.print(h11);
                lcd.setCursor(6,1);
                lcd.print(":");
                lcd.setCursor(0,0);
                lcd.print("ENTER TIME MIN ");
                m11 = keypad.waitForKey();
                if(m11==100)
                   m11=0;
                 if(m11>=10)
                 {
                  y4=m11;
                  EEPROM.update(7,y4);
                  lcd.setCursor(8,1);
                  lcd.print(m11);
                  lcd.setCursor(0,0);
                  lcd.print("ENTER TIME AM/PM");
                  meridian = keypad.waitForKey();
                  if (meridian==50)
                    { z4=h11;
                      EEPROM.update(6,z4);
                      Serial.println("initialized value of z4 is ="  );
                      lcd.setCursor(11,1);
                      lcd.print("AM");
                      delay(300);
                    }
                  else if (meridian==40)
                    { if(h11==12)
                      z4=12;
                      else{
                      z4=h11+12;
                    EEPROM.update(6,z4);
                       Serial.println("initialized value of z4 is =" );
                      lcd.setCursor(11,1);
                      lcd.print("PM");
                      delay(300);
                    }}
                  lcd.clear();
                  lcd.setCursor(0,0);
                  lcd.print("TIME 4 SUCCESS.");
                  lcd.setCursor(3,1);
                  lcd.print("RECORDED");
                  delay(5000);
                  lcd.clear();
                
                 }
                else
                { 
                lcd.setCursor(8,1);
                lcd.print(m11);
                m12 = keypad.waitForKey();
                if(m12==100)
                   m12=0;
                lcd.setCursor(9,1);
                lcd.print(m12);
                m1=(m11*10)+(m12*1);
                y4=m1;
                EEPROM.update(7,y4);
                 Serial.println("initialized value of y4 is ="  );
                lcd.setCursor(0,0);
                  lcd.print("ENTER TIME AM/PM");
                  meridian = keypad.waitForKey();
                  if (meridian==50)
                    { z4=h11;
                    EEPROM.update(6,z4);
                     Serial.println("initialized value of z4 is ="  );
                      lcd.setCursor(11,1);
                      lcd.print("AM");
                      delay(300);
                    }
                  else if (meridian==40)
                    { if(h11==12)
                      z4=12;
                      else{
                      z4=h11+12;
                    EEPROM.update(6,z4);
                     Serial.println("initialized value of z4 is ="  );
                      lcd.setCursor(11,1);
                      lcd.print("PM");
                      delay(300);
                    }}
                  lcd.clear();
                  lcd.setCursor(0,0);
                  lcd.print("TIME 4 SUCCESS.");
                  lcd.setCursor(3,1);
                  lcd.print("RECORDED");
                  delay(5000);
                  lcd.clear();
                   }
       
       }break;
       case 5:
       {
        lcd.setCursor(0,0);
                lcd.print("ENTER TIME HOUR");
                h11 = keypad.waitForKey();
                lcd.setCursor(3,1);
                lcd.print(h11);
                lcd.setCursor(6,1);
                lcd.print(":");
                lcd.setCursor(0,0);
                lcd.print("ENTER TIME MIN ");
                m11 = keypad.waitForKey();
                if(m11==100)
                   m11=0;
                
                 if(m11>=10)
                 {
                  y5=m11;
                  EEPROM.update(9,y5);
                  lcd.setCursor(8,1);
                  lcd.print(m11);
                  lcd.setCursor(0,0);
                  lcd.print("ENTER TIME AM/PM");
                  meridian = keypad.waitForKey();
                  if (meridian==50)
                    { z5=h11;
                      EEPROM.update(8,z5);
                      Serial.println("initialized value of z5 is ="  );
                      lcd.setCursor(11,1);
                      lcd.print("AM");
                      delay(300);
                    }
                  else if (meridian==40)
                    { if(h11==12)
                      z5=12;
                      else{
                      z5=h11+12;
                    EEPROM.update(8,z5);
                       Serial.println("initialized value of z5 is ="  );
                      lcd.setCursor(11,1);
                      lcd.print("PM");
                      delay(300);
                    }}
                  lcd.clear();
                  lcd.setCursor(0,0);
                  lcd.print("TIME 5 SUCCESS.");
                  lcd.setCursor(3,1);
                  lcd.print("RECORDED");
                  delay(5000);
                  lcd.clear();
                
                 }
                else
                { 
                lcd.setCursor(8,1);
                lcd.print(m11);
                m12 = keypad.waitForKey();
                if(m12==100)
                   m12=0;
                
                lcd.setCursor(9,1);
                lcd.print(m12);
                m1=(m11*10)+(m12*1);
                y5=m1;
                EEPROM.update(9,y5);
                 Serial.println("initialized value of y5 is =" );
                lcd.setCursor(0,0);
                  lcd.print("ENTER TIME AM/PM");
                  meridian = keypad.waitForKey();
                  if (meridian==50)
                    { z5=h11;
                    EEPROM.update(8,z5);
                     Serial.println("initialized value of z5 is ="  );
                      lcd.setCursor(11,1);
                      lcd.print("AM");
                      delay(300);
                    }
                  else if (meridian==40)
                    { if(h11==12)
                      z5=12;
                      else{
                      z5=h11+12;
                    EEPROM.update(8,z5);
                     Serial.println("initialized value of z5 is ="  );
                      lcd.setCursor(11,1);
                      lcd.print("PM");
                      delay(300);
                    }}
                  lcd.clear();
                  lcd.setCursor(0,0);
                  lcd.print("TIME 5 SUCCESS.");
                  lcd.setCursor(3,1);
                  lcd.print("RECORDED");
                  delay(5000);
                  lcd.clear();
                   }
       }break;
       case 6:
       {
        lcd.setCursor(0,0);
                lcd.print("ENTER TIME HOUR");
                h11 = keypad.waitForKey();
                lcd.setCursor(3,1);
                lcd.print(h11);
                lcd.setCursor(6,1);
                lcd.print(":");
                lcd.setCursor(0,0);
                lcd.print("ENTER TIME MIN ");
                m11 = keypad.waitForKey();
                if(m11==100)
                   m11=0;
                
                 if(m11>=10)
                 {
                  y6=m11;
                  EEPROM.update(11,y6);
                  lcd.setCursor(8,1);
                  lcd.print(m11);
                  lcd.setCursor(0,0);
                  lcd.print("ENTER TIME AM/PM");
                  meridian = keypad.waitForKey();
                  if (meridian==50)
                    { z6=h11;
                      EEPROM.update(10,z6);
                      Serial.println("initialized value of z6 is ="  );
                      lcd.setCursor(11,1);
                      lcd.print("AM");
                      delay(300);
                    }
                  else if (meridian==40)
                    { if(h11==12)
                      z6=12;
                      else{
                      z6=h11+12;
                    EEPROM.update(10,z6);
                       Serial.println("initialized value of z6 is ="  );
                      lcd.setCursor(11,1);
                      lcd.print("PM");
                      delay(300);
                    }}
                  lcd.clear();
                  lcd.setCursor(0,0);
                  lcd.print("TIME 6 SUCCESS.");
                  lcd.setCursor(3,1);
                  lcd.print("RECORDED");
                  delay(5000);
                  lcd.clear();
                
                 }
                else
                { 
                lcd.setCursor(8,1);
                lcd.print(m11);
                m12 = keypad.waitForKey();
                if(m12==100)
                   m12=0;
                
                lcd.setCursor(9,1);
                lcd.print(m12);
                m1=(m11*10)+(m12*1);
                y6=m1;
                EEPROM.update(11,y6);
                 Serial.println("initialized value of y6 is ="  );
                lcd.setCursor(0,0);
                  lcd.print("ENTER TIME AM/PM");
                  meridian = keypad.waitForKey();
                  if (meridian==50)
                    { z6=h11;
                    EEPROM.update(10,z6);
                     Serial.println("initialized value of z6 is ="  );
                      lcd.setCursor(11,1);
                      lcd.print("AM");
                      delay(300);
                    }
                  else if (meridian==40)
                    { if(h11==12)
                      z6=12;
                      else{
                      z6=h11+12;
                    EEPROM.update(10,z6);
                     Serial.println("initialized value of z6 is ="  );
                      lcd.setCursor(11,1);
                      lcd.print("PM");
                      delay(300);
                    }}
                  lcd.clear();
                  lcd.setCursor(0,0);
                  lcd.print("TIME 6 SUCCESS.");
                  lcd.setCursor(3,1);
                  lcd.print("RECORDED");
                  delay(5000);
                  lcd.clear();
                   }
       }break;
       case 7:
       {
        lcd.setCursor(0,0);
                lcd.print("ENTER TIME HOUR");
                h11 = keypad.waitForKey();
                lcd.setCursor(3,1);
                lcd.print(h11);
                lcd.setCursor(6,1);
                lcd.print(":");
                lcd.setCursor(0,0);
                lcd.print("ENTER TIME MIN ");
                m11 = keypad.waitForKey();
                if(m11==100)
                   m11=0;
                
                 if(m11>=10)
                 {
                  y7=m11;
                  EEPROM.update(13,y7);
                  lcd.setCursor(8,1);
                  lcd.print(m11);
                  lcd.setCursor(0,0);
                  lcd.print("ENTER TIME AM/PM");
                  meridian = keypad.waitForKey();
                  if (meridian==50)
                    { z7=h11;
                      EEPROM.update(12,z7);
                      Serial.println("initialized value of z7 is ="  );
                      lcd.setCursor(11,1);
                      lcd.print("AM");
                      delay(300);
                    }
                  else if (meridian==40)
                    { if(h11==12)
                      z7=12;
                      else{
                      z7=h11+12;
                    EEPROM.update(12,z7);
                       Serial.println("initialized value of z7 is ="  );
                      lcd.setCursor(11,1);
                      lcd.print("PM");
                      delay(300);
                    }}
                  lcd.clear();
                  lcd.setCursor(0,0);
                  lcd.print("TIME 6 SUCCESS.");
                  lcd.setCursor(3,1);
                  lcd.print("RECORDED");
                  delay(5000);
                  lcd.clear();
                
                 }
                else
                { 
                lcd.setCursor(8,1);
                lcd.print(m11);
                m12 = keypad.waitForKey();
                if(m12==100)
                   m12=0;
                
                lcd.setCursor(9,1);
                lcd.print(m12);
                m1=(m11*10)+(m12*1);
                y7=m1;
                EEPROM.update(13,y7);
                 Serial.println("initialized value of y7 is ="  );
                lcd.setCursor(0,0);
                  lcd.print("ENTER TIME AM/PM");
                  meridian = keypad.waitForKey();
                  if (meridian==50)
                    { z7=h11;
                    EEPROM.update(12,z7);
                     Serial.println("initialized value of z7 is ="  );
                      lcd.setCursor(11,1);
                      lcd.print("AM");
                      delay(300);
                    }
                  else if (meridian==40)
                    { if(h11==12)
                      z7=12;
                      else{
                      z7=h11+12;
                    EEPROM.update(12,z7);
                     Serial.println("initialized value of z7 is ="  );
                      lcd.setCursor(11,1);
                      lcd.print("PM");
                      delay(300);
                    }}
                  lcd.clear();
                  lcd.setCursor(0,0);
                  lcd.print("TIME 7 SUCCESS.");
                  lcd.setCursor(3,1);
                  lcd.print("RECORDED");
                  delay(5000);
                  lcd.clear();
                   }
       }break;
       case 8:
       {
        lcd.setCursor(0,0);
                lcd.print("ENTER TIME HOUR");
                h11 = keypad.waitForKey();
                lcd.setCursor(3,1);
                lcd.print(h11);
                lcd.setCursor(6,1);
                lcd.print(":");
                lcd.setCursor(0,0);
                lcd.print("ENTER TIME MIN ");
                m11 = keypad.waitForKey();
                if(m11==100)
                   m11=0;
                
                 if(m11>=10)
                 {
                  y8=m11;
                  EEPROM.update(15,y8);
                  lcd.setCursor(8,1);
                  lcd.print(m11);
                  lcd.setCursor(0,0);
                  lcd.print("ENTER TIME AM/PM");
                  meridian = keypad.waitForKey();
                  if (meridian==50)
                    { z8=h11;
                      EEPROM.update(14,z8);
                      Serial.println("initialized value of z8 is ="  );
                      lcd.setCursor(11,1);
                      lcd.print("AM");
                      delay(300);
                    }
                  else if (meridian==40)
                    { if(h11==12)
                      z8=12;
                      else{
                      z8=h11+12;
                    EEPROM.update(14,z8);
                       Serial.println("initialized value of z8 is ="  );
                      lcd.setCursor(11,1);
                      lcd.print("PM");
                      delay(300);
                    }}
                  lcd.clear();
                  lcd.setCursor(0,0);
                  lcd.print("TIME 8 SUCCESS.");
                  lcd.setCursor(3,1);
                  lcd.print("RECORDED");
                  delay(5000);
                  lcd.clear();
                
                 }
                else
                { 
                lcd.setCursor(8,1);
                lcd.print(m11);
                m12 = keypad.waitForKey();
                if(m12==100)
                   m12=0;
                
                lcd.setCursor(9,1);
                lcd.print(m12);
                m1=(m11*10)+(m12*1);
                y8=m1;
                EEPROM.update(15,y8);
                 Serial.println("initialized value of y8 is =" );
                lcd.setCursor(0,0);
                  lcd.print("ENTER TIME AM/PM");
                  meridian = keypad.waitForKey();
                  if (meridian==50)
                    { z8=h11;
                    EEPROM.update(14,z8);
                     Serial.println("initialized value of z8 is ="  );
                      lcd.setCursor(11,1);
                      lcd.print("AM");
                      delay(300);
                    }
                  else if (meridian==40)
                    { if(h11==12)
                      z8=12;
                      else{
                      z8=h11+12;
                    EEPROM.update(14,z8);
                     Serial.println("initialized value of z8 is ="  );
                      lcd.setCursor(11,1);
                      lcd.print("PM");
                      delay(300);
                    }}
                  lcd.clear();
                  lcd.setCursor(0,0);
                  lcd.print("TIME 8 SUCCESS.");
                  lcd.setCursor(3,1);
                  lcd.print("RECORDED");
                  delay(5000);
                  lcd.clear();
                   }
       }break;
       case 9:
       {
        lcd.setCursor(0,0);
                lcd.print("ENTER TIME HOUR");
                h11 = keypad.waitForKey();
                lcd.setCursor(3,1);
                lcd.print(h11);
                lcd.setCursor(6,1);
                lcd.print(":");
                lcd.setCursor(0,0);
                lcd.print("ENTER TIME MIN ");
                m11 = keypad.waitForKey();
                if(m11==100)
                   m11=0;
                
                 if(m11>=10)
                 {
                  y9=m11;
                  EEPROM.update(17,y9);
                  lcd.setCursor(8,1);
                  lcd.print(m11);
                  lcd.setCursor(0,0);
                  lcd.print("ENTER TIME AM/PM");
                  meridian = keypad.waitForKey();
                  if (meridian==50)
                    { z9=h11;
                      EEPROM.update(16,z9);
                      Serial.println("initialized value of z9 is ="  );
                      lcd.setCursor(11,1);
                      lcd.print("AM");
                      delay(300);
                    }
                  else if (meridian==40)
                    { if(h11==12)
                      z9=12;
                      else{
                      z9=h11+12;
                    EEPROM.update(16,z9);
                       Serial.println("initialized value of z9 is ="  );
                      lcd.setCursor(11,1);
                      lcd.print("PM");
                      delay(300);
                    }}
                  lcd.clear();
                  lcd.setCursor(0,0);
                  lcd.print("TIME 9 SUCCESS.");
                  lcd.setCursor(3,1);
                  lcd.print("RECORDED");
                  delay(5000);
                  lcd.clear();
                
                 }
                else
                { 
                lcd.setCursor(8,1);
                lcd.print(m11);
                m12 = keypad.waitForKey();
                if(m12==100)
                   m12=0;
                
                lcd.setCursor(9,1);
                lcd.print(m12);
                m1=(m11*10)+(m12*1);
                y9=m1;
                EEPROM.update(17,y9);
                 Serial.println("initialized value of y9 is ="  );
                lcd.setCursor(0,0);
                  lcd.print("ENTER TIME AM/PM");
                  meridian = keypad.waitForKey();
                  if (meridian==50)
                    { z9=h11;
                    EEPROM.update(16,z9);
                     Serial.println("initialized value of z9 is ="  );
                      lcd.setCursor(11,1);
                      lcd.print("AM");
                      delay(300);
                    }
                  else if (meridian==40)
                    { if(h11==12)
                      z9=12;
                      else{
                      z9=h11+12;
                    EEPROM.update(16,z9);
                     Serial.println("initialized value of z9 is =" );
                      lcd.setCursor(11,1);
                      lcd.print("PM");
                      delay(300);
                    }}
                  lcd.clear();
                  lcd.setCursor(0,0);
                  lcd.print("TIME 9 SUCCESS.");
                  lcd.setCursor(3,1);
                  lcd.print("RECORDED");
                  delay(5000);
                  lcd.clear();
                   }
       }break;
       case 10:
       {
        lcd.setCursor(0,0);
                lcd.print("ENTER TIME HOUR");
                h11 = keypad.waitForKey();
                lcd.setCursor(3,1);
                lcd.print(h11);
                lcd.setCursor(6,1);
                lcd.print(":");
                lcd.setCursor(0,0);
                lcd.print("ENTER TIME MIN ");
                m11 = keypad.waitForKey();
                if(m11==100)
                   m11=0;
                
                 if(m11>=10)
                 {
                  y10=m11;
                  EEPROM.update(19,y10);
                  lcd.setCursor(8,1);
                  lcd.print(m11);
                  lcd.setCursor(0,0);
                  lcd.print("ENTER TIME AM/PM");
                  meridian = keypad.waitForKey();
                  if (meridian==50)
                    { z10=h11;
                      EEPROM.update(18,z10);
                      Serial.println("initialized value of z10 is ="  );
                      lcd.setCursor(11,1);
                      lcd.print("AM");
                      delay(300);
                    }
                  else if (meridian==40)
                    { if(h11==12)
                      z10=12;
                      else{
                      z10=h11+12;
                    EEPROM.update(18,z10);
                       Serial.println("initialized value of z10 is ="  );
                      lcd.setCursor(11,1);
                      lcd.print("PM");
                      delay(300);
                    }}
                  lcd.clear();
                  lcd.setCursor(0,0);
                  lcd.print("TIME 10 SUCCESS.");
                  lcd.setCursor(3,1);
                  lcd.print("RECORDED");
                  delay(5000);
                  lcd.clear();
                
                 }
                else
                { 
                lcd.setCursor(8,1);
                lcd.print(m11);
                m12 = keypad.waitForKey();
                if(m12==100)
                   m12=0;
                
                lcd.setCursor(9,1);
                lcd.print(m12);
                m1=(m11*10)+(m12*1);
                y10=m1;
                EEPROM.update(19,y10);
                 Serial.println("initialized value of y10 is ="  );
                lcd.setCursor(0,0);
                  lcd.print("ENTER TIME AM/PM");
                  meridian = keypad.waitForKey();
                  if (meridian==50)
                    { z10=h11;
                    EEPROM.update(18,z10);
                     Serial.println("initialized value of z10 is ="  );
                      lcd.setCursor(11,1);
                      lcd.print("AM");
                      delay(300);
                    }
                  else if (meridian==40)
                    { if(h11==12)
                      z10=12;
                      else{
                      z10=h11+12;
                    EEPROM.update(18,z10);
                     Serial.println("initialized value of z10 is ="  );
                      lcd.setCursor(18,1);
                      lcd.print("PM");
                      delay(300);
                    }}
                  lcd.clear();
                  lcd.setCursor(0,0);
                  lcd.print("TIME 10 SUCCESS.");
                  lcd.setCursor(3,1);
                  lcd.print("RECORDED");
                  delay(5000);
                  lcd.clear();
                   }
       }break;
       case 11:
       {
        lcd.setCursor(0,0);
                lcd.print("ENTER TIME HOUR");
                h11 = keypad.waitForKey();
                lcd.setCursor(3,1);
                lcd.print(h11);
                lcd.setCursor(6,1);
                lcd.print(":");
                lcd.setCursor(0,0);
                lcd.print("ENTER TIME MIN ");
                m11 = keypad.waitForKey();
                if(m11==100)
                   m11=0;
                
                 if(m11>=10)
                 {
                  y11=m11;
                  EEPROM.update(21,y10);
                  lcd.setCursor(8,1);
                  lcd.print(m11);
                  lcd.setCursor(0,0);
                  lcd.print("ENTER TIME AM/PM");
                  meridian = keypad.waitForKey();
                  if (meridian==50)
                    { z11=h11;
                      EEPROM.update(20,z11);
                      Serial.println("initialized value of z11 is =" );
                      lcd.setCursor(11,1);
                      lcd.print("AM");
                      delay(300);
                    }
                  else if (meridian==40)
                    { if(h11==12)
                      z11=12;
                      else{
                      z11=h11+12;
                    EEPROM.update(20,z11);
                       Serial.println("initialized value of z11 is ="  );
                      lcd.setCursor(11,1);
                      lcd.print("PM");
                      delay(300);
                    }}
                  lcd.clear();
                  lcd.setCursor(0,0);
                  lcd.print("TIME 11 SUCCESS.");
                  lcd.setCursor(3,1);
                  lcd.print("RECORDED");
                  delay(5000);
                  lcd.clear();
                
                 }
                else
                { 
                lcd.setCursor(8,1);
                lcd.print(m11);
                m12 = keypad.waitForKey();
                if(m12==100)
                   m12=0;
                
                lcd.setCursor(9,1);
                lcd.print(m12);
                m1=(m11*10)+(m12*1);
                y11=m1;
                EEPROM.update(21,y11);
                 Serial.println("initialized value of y10 is ="  );
                lcd.setCursor(0,0);
                  lcd.print("ENTER TIME AM/PM");
                  meridian = keypad.waitForKey();
                  if (meridian==50)
                    { z11=h11;
                    EEPROM.update(20,z11);
                     Serial.println("initialized value of z11 is ="  );
                      lcd.setCursor(11,1);
                      lcd.print("AM");
                      delay(300);
                    }
                  else if (meridian==40)
                    { if(h11==12)
                      z11=12;
                      else{
                      z11=h11+12;
                    EEPROM.update(20,z11);
                     Serial.println("initialized value of z11 is ="  );
                      lcd.setCursor(11,1);
                      lcd.print("PM");
                      delay(300);
                    }}
                  lcd.clear();
                  lcd.setCursor(0,0);
                  lcd.print("TIME 11 SUCCESS.");
                  lcd.setCursor(3,1);
                  lcd.print("RECORDED");
                  delay(5000);
                  lcd.clear();
                   }
       }break;
       case 12:
       {
        lcd.setCursor(0,0);
                lcd.print("ENTER TIME HOUR");
                h11 = keypad.waitForKey();
                lcd.setCursor(3,1);
                lcd.print(h11);
                lcd.setCursor(6,1);
                lcd.print(":");
                lcd.setCursor(0,0);
                lcd.print("ENTER TIME MIN ");
                m11 = keypad.waitForKey();
                if(m11==100)
                   m11=0;
                
                 if(m11>=10)
                 {
                  y12=m11;
                  EEPROM.update(23,y12);
                  lcd.setCursor(8,1);
                  lcd.print(m11);
                  lcd.setCursor(0,0);
                  lcd.print("ENTER TIME AM/PM");
                  meridian = keypad.waitForKey();
                  if (meridian==50)
                    { z12=h11;
                      EEPROM.update(22,z12);
                      Serial.println("initialized value of z11 is ="  );
                      lcd.setCursor(11,1);
                      lcd.print("AM");
                      delay(300);
                    }
                  else if (meridian==40)
                    { if(h11==12)
                      z12=12;
                      else{
                      z12=h11+12;
                    EEPROM.update(22,z12);
                       Serial.println("initialized value of z12 is ="  );
                      lcd.setCursor(11,1);
                      lcd.print("PM");
                      delay(300);
                    }}
                  lcd.clear();
                  lcd.setCursor(0,0);
                  lcd.print("TIME 12 SUCCESS.");
                  lcd.setCursor(3,1);
                  lcd.print("RECORDED");
                  delay(5000);
                  lcd.clear();
                
                 }
                else
                { 
                lcd.setCursor(8,1);
                lcd.print(m11);
                m12 = keypad.waitForKey();
                if(m12==100)
                   m12=0;
                
                lcd.setCursor(9,1);
                lcd.print(m12);
                m1=(m11*10)+(m12*1);
                y12=m1;
                EEPROM.update(23,y12);
                 Serial.println("initialized value of y12 is ="  );
                 Serial.println(y12);
                lcd.setCursor(0,0);
                  lcd.print("ENTER TIME AM/PM");
                  meridian = keypad.waitForKey();
                  if (meridian==50)
                    { z12=h11;
                    EEPROM.update(22,z12);
                     Serial.println("initialized value of z12 is ="  );
                       Serial.println(z12);
                      lcd.setCursor(11,1);
                      lcd.print("AM");
                      delay(300);
                    }
                  else if (meridian==40)
                    { if(h11==12)
                      z12=12;
                      else{
                     z12=h11+12;
                     EEPROM.update(22,z12);
                     Serial.println("initialized value of z12 is ="  );
                     Serial.println(z12);
                      lcd.setCursor(11,1);
                      lcd.print("PM");
                      delay(300);
                    }}
                  lcd.clear();
                  lcd.setCursor(0,0);
                  lcd.print("TIME 12 SUCCESS.");
                  lcd.setCursor(3,1);
                  lcd.print("RECORDED");
                  delay(5000);
                  lcd.clear();
                  }
       }
       

       default:
       {
         lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("ENTER VALID OPTN");
         goto main;
       }
       
}

}
}
