#include "object.h"
#include <cmath>

using namespace std;

void Object::applyVelocity(){
    if (y != 0){
        velocityUp -= g;
    }

    y = fmax(y + velocityUp, 0.0);
    x = x + velocitySide;

    if (y == 0) {
        velocityUp = 0;
    }

    if (velocitySide > 0){
        velocitySide = fmin(velocitySide - 0.2, 0.0);
    } else {
        velocitySide = fmax(velocitySide + 0.2, 0.0);
    }
}

void Object::pushSide(float f){
    velocitySide += f;
}

void Object::pushUp(float f){
    velocityUp += f;
}

int* Object::getPos(){
    static int p[2] = {x, y};
    return p;
}