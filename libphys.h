#include <iostream>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <vector>

#ifndef LIBPHYS_H
#define LIBPHYS_H

class gravitational_field {
    private:
        const float g;

    public:
        gravitational_field(float g);
        float field_const();

};
class kinematics {
    private:
        float acceleration[2];
        float delta_time;
        int &x;
        int &y;
        float velocity[2];
    public:
        kinematics(int &x, int &y, float a[2], float d_t, float velocity[2]); //default is rest lol
        void linear_move();
        void terminate_move();
};

#endif