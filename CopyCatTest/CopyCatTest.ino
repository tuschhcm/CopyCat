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
  digitalWrite(BUTTON1, HIGH);
  digitalWrite(BUTTON2, HIGH);
  digitalWrite(BUTTON3, HIGH);
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

// keep track of the current level
int level = 0;

void loop(){
  if (level >= 10) {
    digitalWrite(LEDR, LOW);
    delay(3000);
    digitalWrite(LEDR, HIGH);
    level = 0;
  }

  simon.playPattern(level);
  delay(10);
  simon.recievePattern(BUTTON1, BUTTON2, BUTTON3, level);
  delay(10);
  
  if(simon.compare(level)){
    level++;
  }else{
    digitalWrite(LEDR, LOW);
    delay(3000);
    digitalWrite(LEDR, HIGH);
    delay(250);
  }
}
