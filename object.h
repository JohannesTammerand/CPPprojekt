#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <vector>
using namespace std;

class Object{
public:
    Object () : x{0}, y{0}, g{0}, velocity{{0,0}} {};
    Object (float nx, float ny, float ng) : y{ny}, x{nx}, g{ng} {};
    Object (float nx, float ny, float ng, float nm) : y{ny}, x{nx}, g{ng}, m{nm} {};

    void applyVelocity(vector<float> nV);
    void calculateNewPos();
    void pushSide(float f);
    void pushUp(float f);
    
    float getX();
    float getY();
    float getM();
    float* getPos();
    friend ostream& operator<<(ostream& os, const Object o);
private:
    vector<float> velocity;
    float y;
    float x;
    float m;
    float g;
};

ostream& operator<<(ostream& os, Object o){
    os << "(" << o.x << ", " << o.y << ")" << endl;
    return os; 
}

#endif