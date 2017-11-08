#include <vector>
#include <vecmath.h>
#include "finger.h"

Finger::Finger (int x, int y){
    position[0] = x;
    position[1] = y;
};

void Finger::updatePosition(int x, int y){
    position[0] = x;
    position[1] = y;
};

void Finger::updateDiameter(int d){
    diameter = d;
};

void Finger::updateID(int i){
    id = i;
};

Vector2f Finger::getPosition(){
    return position;
}

int Finger::getDiameter(){
    return diameter;
}
