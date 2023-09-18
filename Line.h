
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "VectorClass.h"
#include "Particle.h"

using namespace std;

#pragma once

class Line
{
public:
    Line(VectorClass, VectorClass);
    ~Line();
    
    VectorClass getStart();
    VectorClass getEnd();

    bool hasCollide(VectorClass v);


public:
    VectorClass from;
    VectorClass to;

  
};
