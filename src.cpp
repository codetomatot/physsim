#include <iostream>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <vector>
#include <cstdint>
#include "libphys.h"

gravitational_field::gravitational_field(float g_a) : g(g_a) {
    std::cout << "this is the gravitational acceleration selected: " << g_a << std::endl;
}
float gravitational_field::field_const() {
    return g;
    // std::cout << "called the filed diusplay" << std::endl;
}

kinematics::kinematics(int &x_c, int &y_c, float a[2], float d_t, float v[2]) : x(x_c), y(y_c), delta_time(d_t)  {
    memcpy(acceleration, a, sizeof(acceleration));
    memcpy(velocity, v, sizeof(velocity));
}
void kinematics::linear_move() {
    velocity[0] += acceleration[0] * delta_time;
    velocity[1] += acceleration[1] * delta_time;
    x += velocity[0] * delta_time;
    y += velocity[1] * delta_time;

    // return x;
}
void kinematics::terminate_move() {
    for(int i =0 ; i< sizeof(acceleration)/sizeof(acceleration[0]); i++) {
        acceleration[i] = 0; velocity[i] =0;
    }
}