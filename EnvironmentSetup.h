#ifndef ENVIRONMENT_SETUP_H
#define ENVIRONMENT_SETUP_H

#include "StaticFriction.h"

struct EnvironmentSetup{
	
	
		static EnvironmentSetup & getInstance(){
			static EnvironmentSetup & es;
			return es;
		}
		EnvironmentSetup(const EnvironmentSetup &) = delete;
		EnvironmentSetup & operator = (const EnvironmentSetup &) = delete;
		static StaticFriction getStaticFriction(){
			return getInstance().stat_friction;
		} 
		
	
	
	private:
	   StaticFriction stat_friction;
	   EnvironmentSetup()
	   :stat_friction(StaticFriction(0.5))
	   {
		   
	   }
	   ~EnvironmentSetup(){}
}





















#endif