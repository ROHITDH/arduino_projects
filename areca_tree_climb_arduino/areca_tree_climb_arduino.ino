//programmed by ROHIT D H
//CEC CANARA MANGALORE

void setup() {
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  pinMode(A4,OUTPUT);
  }

// the loop function runs over and over again forever
void loop() {
int i;
  for(i=0;i<1;i++)
  {

  digitalWrite(13,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(1,HIGH);
  digitalWrite(0,HIGH);
  delay(2000);


//U L OPEN 
//L L CLOSE
digitalWrite(4,LOW);
digitalWrite(3,LOW);
digitalWrite(2,LOW);
delay(2000);

digitalWrite(4,HIGH);
digitalWrite(3,HIGH);
digitalWrite(2,HIGH);
  
//UC outside
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  delay(60);

//A up
  digitalWrite(13,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(11,HIGH);
  delay(1200);
  digitalWrite(5,LOW);
  delay(27000);

//UC inside
digitalWrite(5,HIGH);
delay(1200);
digitalWrite(13,HIGH);
digitalWrite(12,HIGH);
digitalWrite(11,LOW);
delay(500);


//U L CLOSE
digitalWrite(11,HIGH);
digitalWrite(1,LOW);
digitalWrite(3,HIGH);
digitalWrite(2,HIGH);
digitalWrite(4,LOW);
delay(2000);
digitalWrite(4,HIGH);

//L L OPEN
delay(2000);
digitalWrite(0,LOW);
digitalWrite(1,HIGH);
digitalWrite(3,HIGH);
digitalWrite(2,HIGH);
digitalWrite(4,LOW);
delay(2000);

digitalWrite(4,HIGH);
digitalWrite(0,HIGH);
//LC OPEN
digitalWrite(8,LOW);
delay(200);



//A DOWN
  digitalWrite(8,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(5,LOW);
  delay(27000);

//LC CLOSE
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(5,HIGH);
delay(600);
digitalWrite(9,LOW);
digitalWrite(10,LOW);
digitalWrite(8,LOW);
delay(60);

//L L CLOSE
digitalWrite(0,LOW);
digitalWrite(9,HIGH);
digitalWrite(10,HIGH);
digitalWrite(8,HIGH);


digitalWrite(3,LOW);
digitalWrite(2,LOW);
digitalWrite(4,LOW);
delay(2000);

  }
///////////////////////////////////////////////////////////////////down set
digitalWrite(13,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(1,HIGH);
  digitalWrite(0,HIGH);
analogWrite(A4,HIGH);
delay(20000);
analogWrite(A4,LOW);

for(i=0;i<1;i++)
{
digitalWrite(13,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(1,HIGH);
  digitalWrite(0,HIGH);
  delay(2000);

//L L OPEN
digitalWrite(4,LOW);
delay(2000);

digitalWrite(4,HIGH);


//LC OPEN
digitalWrite(8,LOW);
delay(200);


//A up
  digitalWrite(8,HIGH);
  delay(1200);
  digitalWrite(5,LOW);
  delay(27000);

  
//LC CLOSE
  digitalWrite(5,HIGH);
delay(600);
digitalWrite(9,LOW);
digitalWrite(10,LOW);
digitalWrite(8,LOW);
delay(60);

//L L CLOSE
digitalWrite(0,LOW);
digitalWrite(9,HIGH);
digitalWrite(10,HIGH);
digitalWrite(8,HIGH);


digitalWrite(3,LOW);
digitalWrite(2,LOW);
digitalWrite(4,LOW);
delay(2000);


digitalWrite(0,HIGH);
digitalWrite(3,HIGH);
digitalWrite(2,HIGH);
digitalWrite(4,HIGH);
delay(2000);



//U L OPEN 
//L L CLOSE
digitalWrite(4,LOW);
digitalWrite(3,LOW);
digitalWrite(2,LOW);
delay(2000);

digitalWrite(4,HIGH);
digitalWrite(3,HIGH);
digitalWrite(2,HIGH);


//UC outside
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  delay(60);

digitalWrite(13,HIGH);
digitalWrite(12,HIGH);
digitalWrite(11,HIGH);
//A DOWN
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(5,LOW);
  delay(27000);


//UC inside
digitalWrite(6,HIGH);
digitalWrite(7,HIGH);
digitalWrite(5,HIGH);

delay(1200);
digitalWrite(13,HIGH);
digitalWrite(12,HIGH);
digitalWrite(11,LOW);
delay(500);


//U L CLOSE
digitalWrite(11,HIGH);
digitalWrite(4,LOW);
digitalWrite(3,HIGH);
digitalWrite(2,HIGH);
digitalWrite(1,LOW);
delay(2000);
}
digitalWrite(13,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(1,HIGH);
  digitalWrite(0,HIGH);
delay(10000000000);
}

//SIRSI UTTARA KANNADA
