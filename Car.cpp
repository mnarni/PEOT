//from car header
#include "Car.h"
#include "EnvironmentSetup.h"

//assumption of all cars having mass of 100kg for right now
Car::Car(): car_mass(100), car_pos_front_driver(0,0,0,1), car_pos_front_passenger(0,0,0,1), 
car_pos_rear_driver(0,0,0,1), car_pos_rear_passenger(0,0,0,1), car_velocity(0,0,0,1), 
car_accel(0,0,0,1), car_force(0,0,0,1)
{}

void Car::setMass(float m)
{
    this->car_mass = m;
}

void Car::setForce(VectorClass f)
{
    this->car_force = f;
}

void Car::setVelocity(VectorClass v)
{
    this->car_velocity = v;
}

void Car::setPosition_FD(VectorClass p)
{
    this->car_pos_front_driver = p;
}

void Car::setPosition_FP(VectorClass p)
{
    this->car_pos_front_passenger = p;
}

void Car::setPosition_RD(VectorClass p)
{
    this->car_pos_rear_driver = p;
}

void Car::setPosition_RP(VectorClass p)
{
    this->car_pos_rear_passenger = p;
}

void Car::setAccel(VectorClass a)
{
    this->car_accel = a;
}

float Car::getMass()
{
    return this->car_mass;
}

VectorClass Car::getForce()
{
    return this->car_force;
}

VectorClass Car::getVelocity()
{
    return this->car_velocity;
}

VectorClass Car::getPos_FD()
{
    return this->car_pos_front_driver;
}

VectorClass Car::getPos_FP()
{
    return this->car_pos_front_passenger;
}

VectorClass Car::getPos_RD()
{
    return this->car_pos_rear_driver;
}

VectorClass Car::getPos_RP()
{
    return this->car_pos_rear_passenger;
}

VectorClass Car::getAccel()
{
    return this->car_accel;
}

void Car::Update(float d, float m, VectorClass a)   //temp update solution until complete calculations figured out
{
	// Update linear position
    VectorClass addPos(1,0,0,0);
    this->car_pos_front_driver = this->car_pos_front_driver + addPos;
    this->car_pos_front_passenger = this->car_pos_front_passenger + addPos;
    this->car_pos_rear_driver = this->car_pos_rear_driver + addPos;
    this->car_pos_rear_passenger = this->car_pos_rear_passenger + addPos;

    VectorClass imposed_force = a.scaledVector(a, m);
    // acceleration from force
    VectorClass resultingAcc = car_accel + car_accel.scaledVector(imposed_force, car_mass); // This looks like a bug.  Shouldn't we be using inverse car mass here?

	
	//apply static friction from environment if car is not moving.  Make it more robust later.
	if(0.0f == this->car_velocity){
		StaticFriction sf = EnvironmentSetup.getStaticFriction();
		float stat_friction_force = sf.getStaticFrictionForce(*this);
		if(stat_friction_force >= (car_mass*(resultingAcc.length()))){
			resultingAcc = VectorClass(0,0,0,0); //Force is zeroed out by static friction.
		}
	}

    // Update linear velocity from acceleration
	this->car_velocity = this->car_velocity + car_velocity.scaledVector(resultingAcc, d);

    // Impose drag.
    float v_multiplier = pow(0.99, d);
	this->car_velocity = this->car_velocity.scaledVector(this->car_velocity, v_multiplier);
}

void Car::MoveForward(float s)
{
    VectorClass delta_x = VectorClass(s, 0.0f, 0.0f, 0.0f);
    this->car_pos_front_driver = this->car_pos_front_driver + delta_x;
    this->car_pos_front_passenger = this->car_pos_front_passenger + delta_x;
    this->car_pos_rear_driver = this->car_pos_rear_driver + delta_x;
    this->car_pos_rear_passenger = this->car_pos_rear_passenger + delta_x;
}