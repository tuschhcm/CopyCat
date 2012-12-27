#include <CopyCat.h>

#define BUTTON1 2
#define BUTTON2 3
#define BUTTON3 4
#define LEDR 9
#define LEDG 10
#define LEDB 11

void setup(){
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3, INPUT);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  
  //initialize all LED's to off
  digitalWrite(LEDR, HIGH);
  digitalWrite(LEDG, HIGH);
  digitalWrite(LEDB, HIGH);
}

//create a new game
CopyCat simon;

void loop(){
  simon.playPattern(0);
  delay(10);
  simon.recievePattern(BUTTON1, BUTTON2, BUTTON3, 0);
  delay(10);
  
  if(simon.compare(1)){
    digitalWrite(LEDG, LOW);
    delay(3000);
    digitalWrite(LEDG, HIGH);
    delay(250);
  }else{
    digitalWrite(LEDR, LOW);
    delay(3000);
    digitalWrite(LEDR, HIGH);
    delay(250);
  }
}
