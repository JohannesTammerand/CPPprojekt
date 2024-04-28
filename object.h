#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
using namespace std;

class Object{
public:
    Object () : y{0}, x{0}, g{0} {};
    Object (float ny, float nx, float ng) : y{ny}, x{nx}, g{ng} {};

    void applyGravity();
    void push(int f);
    
    int* getPos();
    friend ostream& operator<<(ostream& os, Object o);
private:
    float y;
    float x;
    float g;
};

#endif