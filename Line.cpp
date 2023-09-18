#include <iostream>
#include <cmath>
#include "Line.h"

Line::Line(VectorClass a, VectorClass b)
{
    this->from = a;
    this->to = b;
}

Line::~Line()
{
}

VectorClass Line::getStart()
{
    return this->from;
}

VectorClass Line::getEnd()
{
    return this->to;
}


bool Line::hasCollide(VectorClass vec)
{
   float dy = getEnd().getY() - getStart().getY();
   float dx = getEnd().getX() - getStart().getX();

   float m = dy/dx;
   float b = getEnd().getY() - (m * getEnd().getX());

   return vec.getY() == (m* vec.getX()) + b;

}