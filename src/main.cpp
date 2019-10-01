#include <Arduino.h>
#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  digitalWrite(ENA, HIGH);  
  digitalWrite(ENB, HIGH); 
}

void loop() {
 digitalWrite(IN1, HIGH);      
  digitalWrite(IN2, LOW); 
  digitalWrite(IN3, LOW);      
  digitalWrite(IN4, HIGH);  //go forward
  delay(500);
  digitalWrite(IN1, LOW);      
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);      
  digitalWrite(IN4, LOW);   //stop
  delay(500);
  digitalWrite(IN1, LOW);      
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);      
  digitalWrite(IN4, LOW);   //go back
  delay(500);
  digitalWrite(IN1, LOW);      
  digitalWrite(IN2, LOW); 
  digitalWrite(IN3, HIGH);      
  digitalWrite(IN4, HIGH);  //stop
  delay(500);
}