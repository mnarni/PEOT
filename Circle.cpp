#include <iostream>
#include <cmath>
#include "Circle.h"

Circle::Circle(float r)
{
    radius = r;
}

Circle::~Circle()
{
}

float Circle::getRadius()
{
    return radius;
}

VectorClass Circle::getCenter()
{
    return body.getPosition();
}

bool Circle::hasCollide(VectorClass vec)
{
    VectorClass center = getCenter();
    VectorClass centerToPoint = vec - center;

    float rad = getRadius();
    return centerToPoint.lengthSquared() < rad * rad;
}

bool Circle::pointOnLine(Line line)
{
    if (hasCollide(line.getStart()) || hasCollide(line.getEnd()))
    {
        return true;
    }

    VectorClass a = line.getEnd() - line.getStart();
    VectorClass b = getCenter();
    VectorClass c = b - line.getStart();

    float t = dotProduct(c, a) / dotProduct(a, a);

    if (t < 0.0 || t > 1.0)
    {
        return false;
    }

    VectorClass d;
    d.scaledVector(a, t);
    VectorClass e = line.getStart() + d;

    return hasCollide(e);
}