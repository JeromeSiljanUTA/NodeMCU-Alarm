#include "Arduino.h"
#include "Display.h"

    Display::Display(int pin0, int pin1, int pin2, int pin3){
        pins[0] = pin0;
        pins[1] = pin1;
        pins[2] = pin2;
        pins[3] = pin3;
    }

void Display::writeNum(int num){
    switch(num){
        case 0:
            digitalWrite(pins[0], LOW);
            digitalWrite(pins[1], LOW);
            digitalWrite(pins[2], LOW);
            digitalWrite(pins[3], LOW);
            break;
        case 1:
            digitalWrite(pins[0], HIGH);
            digitalWrite(pins[1], LOW);
            digitalWrite(pins[2], LOW);
            digitalWrite(pins[3], LOW);
            break;
        case 2:
            digitalWrite(pins[0], LOW);
            digitalWrite(pins[1], HIGH);
            digitalWrite(pins[2], LOW);
            digitalWrite(pins[3], LOW);
            break;
        case 3:
            digitalWrite(pins[0], HIGH);
            digitalWrite(pins[1], HIGH);
            digitalWrite(pins[2], LOW);
            digitalWrite(pins[3], LOW);
            break;
        case 4:
            digitalWrite(pins[0], LOW);
            digitalWrite(pins[1], LOW);
            digitalWrite(pins[2], HIGH);
            digitalWrite(pins[3], LOW);
            break;
        case 5:
            digitalWrite(pins[0], HIGH);
            digitalWrite(pins[1], LOW);
            digitalWrite(pins[2], HIGH);
            digitalWrite(pins[3], LOW);
            break;
        case 6:
            digitalWrite(pins[0], LOW);
            digitalWrite(pins[1], HIGH);
            digitalWrite(pins[2], HIGH);
            digitalWrite(pins[3], LOW);
            break;
        case 7:
            digitalWrite(pins[0], HIGH);
            digitalWrite(pins[1], HIGH);
            digitalWrite(pins[2], HIGH);
            digitalWrite(pins[3], LOW);
            break;
        case 8:
            digitalWrite(pins[0], LOW);
            digitalWrite(pins[1], LOW);
            digitalWrite(pins[2], LOW);
            digitalWrite(pins[3], HIGH);
            break;
        case 9:
            digitalWrite(pins[0], HIGH);
            digitalWrite(pins[1], LOW);
            digitalWrite(pins[2], LOW);
            digitalWrite(pins[3], HIGH);
            break;
    }
}
