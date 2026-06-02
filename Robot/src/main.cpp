#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11);

#define Fw 3
#define Bc 4
#define Lf 5
#define Rg 2


char c = 'S';
unsigned long t = 0;
unsigned long t_last = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BT.begin(38400);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:
  t = millis();
  
  if(t>500+t_last){
    Serial.print(c);
    //BT.print(c);
    t_last = t;
  }

  while(BT.available()){
    char new_c = BT.read();
    if(new_c != '\n' && new_c !=  '\r'){
      c = new_c;
    }
  }

  switch (c)
  {
  case 'Q':
    digitalWrite(Bc, LOW);
    digitalWrite(Rg, LOW);
    digitalWrite(Fw, HIGH);
    digitalWrite(Lf, HIGH);
    break;

  case 'W':
    digitalWrite(Bc, LOW);
    digitalWrite(Rg, LOW);
    digitalWrite(Lf, LOW);
    digitalWrite(Fw, HIGH);
    break;

  case 'E':
    digitalWrite(Bc, LOW);
    digitalWrite(Lf, LOW);
    digitalWrite(Fw, HIGH);
    digitalWrite(Rg, HIGH);
    break;

  case 'A':
    digitalWrite(Bc, LOW);
    digitalWrite(Rg, LOW);
    digitalWrite(Fw, LOW);
    digitalWrite(Lf, HIGH);
    break;

  case 'D':
    digitalWrite(Bc, LOW);
    digitalWrite(Lf, LOW);
    digitalWrite(Fw, LOW);
    digitalWrite(Rg, HIGH);
    break;

  case 'Y':
    digitalWrite(Fw, LOW);
    digitalWrite(Rg, LOW);
    digitalWrite(Bc, HIGH);
    digitalWrite(Lf, HIGH);
    break;

  case 'X':
    digitalWrite(Fw, LOW);
    digitalWrite(Rg, LOW);
    digitalWrite(Lf, LOW);
    digitalWrite(Bc, HIGH);
    break;

  case 'C':
    digitalWrite(Fw, LOW);
    digitalWrite(Lf, LOW);
    digitalWrite(Bc, HIGH);
    digitalWrite(Rg, HIGH);
    break;

  default:
    digitalWrite(Fw, LOW);
    digitalWrite(Bc, LOW);
    digitalWrite(Lf, LOW);
    digitalWrite(Rg, LOW);
    break;
  }
}