#include "StaticFriction.h"


float StaticFriction::getStaticFrictionForce(const Car & c){
		return c.getMass*GRAVITY_ACCEL*(this->stat_coeff_friction);
}

StaticFriction::StaticFriction(float coeff)
:stat_coeff_friction(coeff)
{}
