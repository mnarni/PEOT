#pragma once
//include math library here
#include "VectorClass.h"
#include "Boundary.h"
//#include "Matrix.h"
#include<iostream>

class Particle
{

public:
	//NOTE: position, velocity, and acceleration are actually vectors
		//they are written as floats while the vector class is getting made
		//once vector class isimplemented, these data types will change to vectors
		//id data member will remain an int

	int id;	//may be helpful in tracking particles and mem management later...

	const float drag = 0.999;	//prevents precision errors from floats that could lead to a false sense of increased energy over time with no stimulant

	float compMass; //compliment of mass (its inverse)
	
	VectorClass position;

	VectorClass velocity;

	VectorClass acceleration;

	VectorClass currForce;	//needs to be track for changes to ensure energy remains consistent



	Particle();	//default ctr

	Particle(VectorClass p, VectorClass v, VectorClass a);	//specialized ctr

	Particle(const Particle &p);	//copy ctr

    Particle(VectorClass p, VectorClass v, VectorClass a, Boundary& boundary); // Particle ctr with Boundary parmeter

    Particle& operator=(const Particle& p);	//assignment operator

	//~Particle();	//destructor

	VectorClass getPosition();

	VectorClass getVelocity();

	VectorClass getAcceleration();

	float getCompMass();

	void resetCompMass(float m);

	void setPosition(float x, float y, float z);

	void setAcceleration(float x, float y, float z);

	void setVelocity(float x, float y, float z);

	int getId();

	void resetId(int new_id);

	void Update(float d);

	void Update(VectorClass p, VectorClass v, VectorClass a, float time);	//update all at once (broken down below for unit testing)

	void UpdatePosition(VectorClass v, VectorClass a, float time);	//update position in isolation

	void UpdateVelocity(VectorClass new_a, float time);	//update velocity in isolation

	void UpdateAcceleration_Manual(VectorClass a);	//update acceleration in isolation manually

	void UpdateAcceleration(VectorClass a); 

	void print();

	void setCurrForce(float f_a, float f_b, float f_c);

    void checkCollision(int screen_width, int screen_height);

private:
    Boundary& boundary;
};