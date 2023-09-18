
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "VectorClass.h"
#include "Particle.h"
#include "Line.h"
#include "Circle.h"

using namespace std;

#pragma once

class BoundaryBox
{
public:
    BoundaryBox();
    BoundaryBox(VectorClass, VectorClass);

    ~BoundaryBox();

    VectorClass getMin();
    VectorClass getMax();

    bool isPointIn(VectorClass v);
    bool isLineCollide(Line line);
    bool isCircleCollide(Circle circle);    


public:
    VectorClass center;
    VectorClass size;
    VectorClass halfSize;
    Particle body;
};


