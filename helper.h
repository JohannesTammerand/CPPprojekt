#include "object.h"
#include <cmath>

namespace physHelper
{
    float distance_from_point(Object obj1, Object obj2)
    {
        return std::sqrt(std::pow(obj2.getX() - obj1.getX(),2) +  std::pow(obj2.getY() - obj1.getY(),2));
    }

    vector<float> direction_from_point(Object obj1, Object obj2)
    {
        float dx = obj2.getX() - obj1.getX();
        float dy = obj2.getY() - obj1.getY();
        vector<float> dir = vector<float>{dx/distance_from_point(obj1,obj2), dy/distance_from_point(obj1,obj2)};
        std::cout  << dir[0]<< " - " << dir[1] << " - " << dx << " - " << dy << endl;
        return dir;
    }

    float gravitational_pull(Object obj1, Object obj2)
    {
        //taken from internetus
        //const float G = 6.674 * std::pow(10, -11);

        float G = 10;
        return G * (obj1.getM() * obj2.getM()) / std::pow(distance_from_point(obj1, obj2),2);
    }

    vector<float> veloctiy_add_from_pull(Object obj1, Object obj2)
    {
        vector<float> dir = direction_from_point(obj1, obj2);
        float g = gravitational_pull(obj1, obj2);
        dir[0] = dir[0] * g;
        dir[1] = dir[1] * g;

        return dir;
    }
}

