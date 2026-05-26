#include <Arduino.h>
// #include <SoftwareSerial.h>

// SoftwareSerial BT(10, 11);

#define H_z 950
#define L_z 150

#define pot_x 0 // A7
#define pot_y 1 // A6

char c = 'S';
uint16_t x = 500;
uint16_t y = 500;
unsigned long t = 0;
unsigned long t_last = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // BT.begin(9600);
  pinMode(A6, INPUT);
  pinMode(A7, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  x = analogRead(pot_x);
  y = analogRead(pot_y);
  t = millis();
  
  if(t>50+t_last){
    Serial.print(c);
    t_last = t;
  }

  if(x>H_z && y>H_z)
    c = 'Y';
  else if(x>H_z && y<L_z)
    c = 'C';
  else if(x<L_z && y>H_z)
    c = 'Q';
  else if(x<L_z && y<L_z)
    c = 'E';
  else{
    if(x>H_z)
      c = 'X';
    else if(x<L_z)
      c = 'W';
    else if(y>H_z)
      c = 'A';
    else if(y<L_z)
      c = 'D';
    else
      c = 'S';
  }

}
