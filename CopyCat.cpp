#include "CopyCat.h"
#include "Arduino.h"

#define RED 9
#define GREEN 10
#define BLUE 11

//<<constructor>>
CopyCat::CopyCat(){}

void CopyCat::newGame(){
     //create pattern
    randomSeed(analogRead(0));
    Serial.begin(9600);
    Serial.println(analogRead(0));

    for(int i = 0; i < 10; i++){
        
        //random number bounds determine LED Pins
        gamePattern[i] = (int)random(9,12);
    }
   
}

//play the pattern to the player
void CopyCat::playPattern(int i){
    for(int n = 0; n <= i; n++){
        digitalWrite(gamePattern[n], LOW);
        delay(500);
        digitalWrite(gamePattern[n], HIGH);
        delay(250);
    }
    delay(10);
}

//recieve player input
void CopyCat::recievePattern(int r, int g, int b, int i){
    for(int buttonPresses = 0; buttonPresses <= i; buttonPresses++){
        
        //controls when to leave loop
        bool buttonPressed = false;

        // get button press from user
        do{
            if(digitalRead(r) == LOW){
                playerPattern[buttonPresses] = RED;
                buttonPressed = true;
				digitalWrite(RED, LOW);

            }else if(digitalRead(g) == LOW){
                playerPattern[buttonPresses] = GREEN;
                buttonPressed = true;
				digitalWrite(GREEN, LOW);
            
            }else if(digitalRead(b) == LOW){
                playerPattern[buttonPresses] = BLUE;
                buttonPressed = true;
				digitalWrite(BLUE, LOW);
            }
        }while(!buttonPressed);

        //delay for bounce back of button
        delay(250);
		digitalWrite(RED, HIGH);
		digitalWrite(GREEN, HIGH);
		digitalWrite(BLUE, HIGH);
    }
}

//compare userInput to gamePattern
bool CopyCat::compare(int i){
    
    //compare patterns to the current index
    for(int n = 0; n <= i; n++){
        if(gamePattern[n] != playerPattern[n]){
            return false;
        }
    }
    
    //if the loop finishes without exiting, patterns match
    return true;
}
