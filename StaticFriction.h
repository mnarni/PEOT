#ifndef STATIC_FRICTION_H
#define STATIC_FRICTION_H

class StaticFriction{
	
	public:
		StaticFriction(float coeff);
	
	
	private:
		static float GRAVITY_ACCEL = 9.8;
		float stat_coeff_friction;
	
	public:
		float getStaticFrictionForce(const Car & c);
	
}





















#endif
