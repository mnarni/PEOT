#include <iostream>
#include <cmath>
#include "BoundaryBox.h"
#include <stdlib.h>

BoundaryBox::BoundaryBox() : center(0, 0, 0, 1), size(0, 0, 0, 1)
{
}

BoundaryBox::BoundaryBox(VectorClass min, VectorClass max)
{

    this->size = max - min;

    this->halfSize.divideVector(this->size, 2.0);

    this->center = min + this->halfSize;
}

BoundaryBox::~BoundaryBox()
{
}

VectorClass BoundaryBox::getMin()
{
    return body.getPosition() - this->halfSize;
}
VectorClass BoundaryBox::getMax()
{
    return body.getPosition() + this->halfSize;
}

bool BoundaryBox::isPointIn(VectorClass vec)
{
    VectorClass min = getMin();
    VectorClass max = getMax();

    return vec.getX() <= max.getX() && min.getX() <= vec.getX() && vec.getY() <= max.getY() && min.getY() <= vec.getY();
}

bool BoundaryBox::isLineCollide(Line line)
{
    if (isPointIn(line.getStart()) || isPointIn(line.getEnd()))
    {
        return true;
    }

    VectorClass unit = line.getEnd() - line.getStart();
    unit.normalize();
    unit.setX((unit.getX() != 0) ? 1.0 / unit.getX() : 0);
    unit.setX((unit.getX() != 0) ? 1.0 / unit.getX() : 0);

    VectorClass minvec = getMin();
    VectorClass minX = (minvec - line.getStart()) * unit;

    VectorClass maxvec = getMax();
    VectorClass maxX = (maxvec - line.getStart()) * unit;

    float minValue = max(min(minX.getX(), maxX.getX()), min(minX.getY(), maxX.getY()));
    float maxValue = min(max(minX.getX(), maxX.getX()), max(minX.getY(), maxX.getY()));

    if (minValue < 0.0 || minValue > maxValue)
    {
        return false;
    }

    float temp = (minValue < 0) ? maxValue : minValue;

    return temp > 0.0 && temp * temp < (line.getEnd() - line.getStart()).lengthSquared();
}


bool BoundaryBox::isCircleCollide(Circle circle) {
        VectorClass minValue = getMin();
        VectorClass maxValue = getMax();

        VectorClass closestPointToCircle = circle.getCenter();
        if (closestPointToCircle.getX() < minValue.getX()) {
            closestPointToCircle.setX(minValue.getX());
        } else if (closestPointToCircle.getX() > maxValue.getX()) {
            closestPointToCircle.setX(maxValue.getX());
        }

        if (closestPointToCircle.getY() < minValue.getY()) {
            closestPointToCircle.setY(minValue.getY());
        } else if (closestPointToCircle.getY() > maxValue.getY()) {
            closestPointToCircle.setY(maxValue.getY());
        }

        VectorClass circleToBox = circle.getCenter() - closestPointToCircle;
        return circleToBox.lengthSquared() <= circle.getRadius() * circle.getRadius();
    }
