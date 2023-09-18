
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "VectorClass.h"
#include "Particle.h"
#include "Line.h"

using namespace std;

#pragma once

class Circle
{
public:
    Circle(float);
    ~Circle();
    float getRadius();
    VectorClass getCenter();
    bool hasCollide(VectorClass v);
    bool pointOnLine(Line l);


public:
    VectorClass center;
    float radius;
    Particle body;
};

static bool dist(Circle a, Circle b)
{
        VectorClass centerVector = a.getCenter()-b.getCenter();
        float radiusSum = a.getRadius() + a.getRadius();
        return centerVector.lengthSquared() <= radiusSum * radiusSum;
}
