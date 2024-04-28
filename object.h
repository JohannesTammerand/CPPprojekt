#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <vector>
using namespace std;

class Object{
public:
    Object () : y{0}, x{0}, g{0}, velocity{0, 0};
    Object (float ny, float nx, float ng) : y{ny}, x{nx}, g{ng} {};

    void applyVelocity();
    void pushSide(float f);
    void pushUp(float f);
    
    int* getPos();
    friend ostream& operator<<(ostream& os, const Object o);
private:
    vector<float> velocity;
    float y;
    float x;
    float g;
};

ostream& operator<<(ostream& os, Object o){
    os << "(" << o.x << ", " << o.y << ")" << endl;
    return os; 
}

#endif