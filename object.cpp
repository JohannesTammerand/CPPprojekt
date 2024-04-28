#include "object.h"
#include <cmath>

using namespace std;

void Object::applyGravity(){
    y = fmax(y - g, 0.0);
}

void Object::push(int f){
    x += f;
}

int* Object::getPos(){
    static int p[2] = {x, y};
    return p;
}

ostream&& operator<<(ostream& os, Object o){
    os << 
}