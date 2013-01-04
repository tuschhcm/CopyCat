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

//Create New Game
CopyCat simon;

// keep track of the current level
int level = 11;

void loop(){
  if (level >= 10) {
    cycle(3);
    level = 0;
    delay(1000);
    
    simon.newGame();
  }

  simon.playPattern(level);
  delay(10);
  simon.recievePattern(BUTTON1, BUTTON2, BUTTON3, level);
  delay(10);
  
  if(simon.compare(level)){
    level++;
    delay(1000);
  }else{
    blink(5);
    delay(500);
  }
}

void blink(int n) {
  for(int i = 0; i < n; i++){
    digitalWrite(LEDR, LOW);
    delay(100);
    digitalWrite(LEDR, HIGH);
    delay(100);
  }
}

void cycle(int n){
  for(int i = 0; i < n; i++){
  digitalWrite(LEDR, LOW);
  delay(100);
  digitalWrite(LEDR, HIGH);
  delay(100);
  digitalWrite(LEDG, LOW);
  delay(100);
  digitalWrite(LEDG, HIGH);
  delay(100);
  digitalWrite(LEDB, LOW);
  delay(100);
  digitalWrite(LEDB, HIGH);
  delay(100);
  }
}
