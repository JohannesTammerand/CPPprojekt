#include <list>
#include "object.h"
#include "helper.h"

using namespace physHelper;

list<Object> Obj;
list<Object> Grav;

int tick;

void calculate_physics()
{
    for(auto grav_point : Grav)
    {
        for(auto object : Obj)
        {
            object.applyVelocity(veloctiy_add_from_pull(grav_point, object));
        }
    }
}

void post_tick()
{
    for(auto object : Obj)
    {
        object.calculateNewPos();
    }
}

void display()
{
    for(auto object : Obj)
    {
        cout << object << " - on tick : " << tick << endl;
    }
}


int main()
{
    tick = 0;
    Object a1 = Object(1, 2, 0, 1);
    //Object a2 = Object(-100,-200, 0, 1);

    Obj.push_back(a1);
    //Obj.push_back(a2);

    Object gra = Object(0, 0, 0, 1);
    Grav.push_back(gra);

    while(tick <= 100000000000000)
    {
        calculate_physics();
        post_tick();
        display();
    }
    return 1;
}