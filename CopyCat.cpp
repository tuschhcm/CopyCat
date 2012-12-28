#include "CopyCat.h"
#include "Arduino.h"

#define RED 9
#define GREEN 10
#define BLUE 11

//<<constructor>>
CopyCat::CopyCat(){
    //create pattern
    randomSeed(analogRead(5));
    
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

            }else if(digitalRead(g) == LOW){
                playerPattern[buttonPresses] = GREEN;
                buttonPressed = true;
            
            }else if(digitalRead(b) == LOW){
                playerPattern[buttonPresses] = BLUE;
                buttonPressed = true;
            }
        }while(!buttonPressed);

        //delay for bounce back of button
        delay(500);
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
