#include "object.h"
#include <cmath>

using namespace std;

void Object::applyVelocity(vector<float> nV)
{
    //TEHTUD MADISE POOLT!!!!
    velocity[0] += nV[0];
    velocity[1] += nV[1];
}

void Object::calculateNewPos()
{
    x += velocity[0];
    y += velocity[1];
}

void Object::pushSide(float f){
    velocity[1] += f;
}

void Object::pushUp(float f){
    velocity[0] += f;
}

float Object::getX()
{
    return x;
}
float Object::getY()
{
    return y;
}
float Object::getM()
{
    return m;
}

float* Object::getPos(){
    static float p[2] = {x, y};
    return p;
}