//need to decide on the mass and other starting elements
#pragma once
#include "VectorClass.h"

class Car 
{
    public:
    Car();
    void setMass(float m);
    void setForce(VectorClass f);
    void setVelocity(VectorClass v);
    void setPosition_FD(VectorClass p);
    void setPosition_FP(VectorClass p);
    void setPosition_RD(VectorClass p);
    void setPosition_RP(VectorClass p);
    void setAccel(VectorClass a);
    float getMass();
    VectorClass getForce();
    VectorClass getVelocity();
    VectorClass getPos_FD();
    VectorClass getPos_FP();
    VectorClass getPos_RD();
    VectorClass getPos_RP();
    VectorClass getAccel();
    void Update(float d, float m, VectorClass a);
    void MoveForward(float s);

    private:
    float car_mass;
    VectorClass car_pos_front_driver;
    VectorClass car_pos_front_passenger;
    VectorClass car_pos_rear_driver;
    VectorClass car_pos_rear_passenger;
    VectorClass car_velocity;
    VectorClass car_accel;
    VectorClass car_force;
};