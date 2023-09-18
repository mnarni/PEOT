#include "Particle.h"
#include "VectorClass.h"
#include <cmath>

//Particle::Particle(): id(0), position(0,0,0,1), velocity(0,0,0,1), acceleration(0,0,0,1), compMass(0)
//{}
//
//Particle::Particle(VectorClass p, VectorClass v, VectorClass a): id(0), position(p), velocity(v),
//acceleration(a), compMass(0)
//{}

Particle::Particle(VectorClass p, VectorClass v, VectorClass a, Boundary& boundary)
        : id(0), position(p), velocity(v), acceleration(a), compMass(0), boundary(boundary) {}


//Particle::Particle(const Particle& p)
//{
//	this->acceleration = p.acceleration; //clean up later to breakdown by vector attributes for a deep copy
//	this->compMass = p.compMass;
//	this->id = p.id;
//	this->position = p.position;
//	this->velocity = p.velocity;
//	//*this = p;
//}

Particle& Particle::operator=(const Particle& p)
{
	//this->acceleration = p.acceleration; //clean up later to breakdown by vector attributes for a deep copy
	//this->compMass = p.compMass;
	//this->id = p.id;
	//this->position = p.position;
	//this->velocity = p.velocity;
	*this = p;
	return *this;
}

//Particle::~Particle() {/*call vector destructors for p, v, and a here */ }

VectorClass Particle::getPosition()
{
	return position;
}

VectorClass Particle::getVelocity()
{
	return velocity;
}

VectorClass Particle::getAcceleration()
{
	return acceleration;
}

int Particle::getId()
{
	return id;
}

float Particle::getCompMass()
{
	return compMass;
}

void Particle::resetCompMass(float m)
{
	compMass = m;
}

void Particle::resetId(int new_id)
{
	id = new_id;
}

void Particle::setPosition(float x, float y, float z)
{
	this->position.setX(x);
	this->position.setY(y);
	this->position.setZ(z);

}

void Particle::setAcceleration(float x, float y, float z)
{
	this->acceleration.setX(x);
	this->acceleration.setY(y);
	this->acceleration.setZ(z);
}

void Particle::setVelocity(float x, float y, float z)
{
	this->velocity.setX(x);
	this->velocity.setY(y);
	this->velocity.setZ(z);
}

void Particle::Update(VectorClass p, VectorClass v, VectorClass a, float time)
{
	float cm = compMass;
	if (cm <= 0.0f) { return ;}	//break early because something went wrong

	UpdatePosition(v, a, time);
	UpdateAcceleration(a);
	UpdateVelocity(a, time);
	//this.velocity *= float_pow(this.drag, time);	//custom power method that works with and returns floats needs to be implemented in math library first

	//set up clearing of forces here later
}

void Particle::UpdatePosition(VectorClass v, VectorClass a, float time)
{
	VectorClass ret1;
	ret1.scaledVector(v, time);
	VectorClass ret2;
	ret1.scaledVector(a, time * time * 0.5);
	this->position = ret1 + ret2;
	
	
	//this.position.addScaledVector(v, t);
	//thisposition.addscaledVector(a, time * time * 0.05);
}

void Particle::UpdateVelocity(VectorClass new_a, float time)
{
	//velocity is just the 1st derivative of the position
	this->velocity = new_a.scaledVector(new_a, time);
}

void Particle::UpdateAcceleration_Manual(VectorClass a)
{
	//acceleration is just the 2nd derivative of the position (1st derivative of velocity)
	this->acceleration = a;
	//gets new a for velocity update, this will get expanded upon later
}

void Particle::UpdateAcceleration(VectorClass a)
{
	//FIX THIS
	this->acceleration = a;
}

void Particle::Update(float d)	//d is for amount of time (duration)
{
	if (this->compMass == 0) {return;}	//break early because it needs some sort of mass

    // Update linear position
    VectorClass newPos = this->position + (this->position.scaledVector(velocity, d));

    boundary.setWidth((this->position.scaledVector(velocity, d)).getX());
    boundary.setHeight((this->position.scaledVector(velocity, d)).getY());


    // TODO: Need to figure out size of the particle

    // TODO: Need to convert particle position to pixels on the screen

    // Check for boundary collision
    if(newPos.getX() < 0.0 || newPos.getX() > boundary.getWidth()) {
        printf("X position: %f boundary: %f", newPos.getX(),boundary.getWidth());
        std::cout << "Particle has collided with the horizontal boundary!\n";
    }
    if(newPos.getY() < 0.0 || newPos.getY() > boundary.getHeight()) {
        printf("Y position: %f boundary: %f", newPos.getY(),boundary.getHeight());
        std::cout << "Particle has collided with the vertical boundary!\n";
    }

    this->position = this->position + (this->position.scaledVector(velocity, d));

    // acceleration from force
    VectorClass resultingAcc = acceleration + acceleration.scaledVector(currForce, compMass);

    // Update linear velocity from acceleration
	this->velocity = this->velocity + velocity.scaledVector(resultingAcc, d);

    // Impose drag.
    float v_multiplier = pow(drag, d);
	this->velocity = this->velocity.scaledVector(this->velocity, v_multiplier);

	//reset amount of forcethat has built up for this particle
    //this->currForce.setX(1);
	//this->currForce.setY(1);
	//this->currForce.setZ(1);
}

void Particle::print()
{
	printf("\n===PARTICLE DATA===\n");
	printf("Position [%f, %f, %f]\n", this->position.X, this->position.Y, this->position.Z);
	printf("Velocity [%f, %f, %f]\n", this->velocity.getX(), this->velocity.getY(), this->velocity.getZ());
	printf("Aceleration [%f, %f, %f]\n", this->acceleration.getX(), this->acceleration.getY(), this->acceleration.getZ());
	printf("Current Force [%f, %f, %f]\n", this->currForce.getX(), this->currForce.getY(), this->currForce.getZ());
	printf("Mass: %f	| Drag from Friction: %f\n", this->compMass, this->drag);
	printf("===================\n");
}

void Particle::setCurrForce(float f_a, float f_b, float f_c)
{
	this->currForce.setX(f_a);
	this->currForce.setY(f_b);
	this->currForce.setZ(f_c); 
}