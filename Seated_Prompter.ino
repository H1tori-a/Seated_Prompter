/*
Language C build by DianFenMian in 2023/5/16
mixly真的不爱用...
*/
#include <Wire.h>
#include <TM1650.h>

TM1650 tm_4display;

float checkdistance_7_8() {
  digitalWrite(7, LOW);
  delayMicroseconds(2);
  digitalWrite(7, HIGH);
  delayMicroseconds(10);
  digitalWrite(7, LOW);
  float distance = pulseIn(8, HIGH) / 58.00;
  delay(10);
  return distance;
}

void voice(int x) {
  digitalWrite(11,LOW);
  delayMicroseconds(2);
  digitalWrite(11,HIGH);
  delayMicroseconds(100);
  digitalWrite(11,LOW);
  delayMicroseconds(100);
  for (int i = (1); i <= (x); i = i + (1)) {
    digitalWrite(12,HIGH);
    delayMicroseconds(100);
    digitalWrite(12,LOW);
    delayMicroseconds(100);
  }
  while (digitalRead(13)) {
  }
}

void setup(){
  pinMode(7, OUTPUT);
  pinMode(8, INPUT);
  pinMode(3, OUTPUT);
  pinMode(9, OUTPUT);
  Wire.begin();
  tm_4display.init();
  pinMode(6, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, INPUT);
}

void loop(){
  delay(500);
  voice(24);
  voice(28);
  voice(20);
  while (true) {
    if (20 > checkdistance_7_8()) {
      digitalWrite(3,HIGH);
      tone(9,3951);
      tm_4display.displayString(String(round(checkdistance_7_8())));
      delay(50);
      digitalWrite(3,LOW);
      tm_4display.displayString(String(round(checkdistance_7_8())));
      noTone(9);
      delay(50);

    }
    if (20 < checkdistance_7_8() && 30 > checkdistance_7_8()) {
      digitalWrite(6,HIGH);
      tm_4display.displayString(String(round(checkdistance_7_8())));
      delay(50);
      digitalWrite(6,LOW);
      tm_4display.displayString(String(round(checkdistance_7_8())));
      delay(50);

    }
    tm_4display.displayString(String(round(checkdistance_7_8())));
  }

}