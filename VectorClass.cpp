#include "VectorClass.h"
#include <iostream>
#include <cmath>

VectorClass::VectorClass()
{
    X = 0.0;
    Y = 0.0;
    Z = 0.0;
    W = 0.0;
}

VectorClass::VectorClass(float inx, float iny, float inz, float inw)
{
    X = inx;
    Y = iny;
    Z = inz;
    W = inw;
}

VectorClass::~VectorClass()
{
}

float VectorClass::getX()
{
    return X;
}

float VectorClass::getY()
{
    return Y;
}
float VectorClass::getZ()
{
    return Z;
}
float VectorClass::getW()
{
    return W;
}

float VectorClass::sum()
{
    return X + Y + Z + W;
}

VectorClass VectorClass::operator+(const VectorClass &b)
{
    VectorClass c;
    c.X = this->X + b.X;
    c.Y = this->Y + b.Y;
    c.Z = this->Z + b.Z;
    c.W = this->W + b.W;
    return c;
}

VectorClass VectorClass::operator-(const VectorClass &b)
{
    VectorClass c;
    c.X = this->X - b.X;
    c.Y = this->Y - b.Y;
    c.Z = this->Z - b.Z;
    c.W = this->W - b.W;
    return c;
}

VectorClass VectorClass::operator*(const VectorClass &b)
{
    VectorClass c;
    c.X = this->X * b.X;
    c.Y = this->Y * b.Y;
    c.Z = this->Z * b.Z;
    c.W = this->W * b.W;
    return c;
}

VectorClass VectorClass::operator/(const VectorClass &b)
{
    VectorClass c;
    c.X = this->X / b.X;
    c.Y = this->Y / b.Y;
    c.Z = this->Z / b.Z;
    c.W = this->W / b.W;
    return c;
}

float VectorClass::length()
{
    float a = this->X;
    float b = this->Y;
    float c = this->Z;
    float d = this->W;
    return sqrt(a * a + b * b + c * c + d * d);
}

float VectorClass::lengthSquared()
{
    float len = length();
    return len * len;
}

VectorClass VectorClass::normalize()
{
    VectorClass c;
    float len = length();
    c.X = this->X / len;
    c.Y = this->Y / len;
    c.Z = this->Z / len;
    c.W = this->W / len;
    return c;
}

VectorClass VectorClass::crossProduct(const VectorClass &b)
{
    VectorClass c;
    c.X = this->Y * b.Z - this->Z * b.Y;
    c.Y = this->Z * b.X - this->X * b.Z;
    c.Z = this->X * b.Y - this->Y * b.X;
    c.W = 1;
    return c;
}

VectorClass VectorClass::scaledVector(const VectorClass &v, float scalar)
{
    this->X = v.X * scalar;
    this->Y = v.Y * scalar;
    this->Z = v.Z * scalar;
    return *this;
}

VectorClass VectorClass::divideVector(const VectorClass &v, float scalar)
{
    this->X = v.X / scalar;
    this->Y = v.Y / scalar;
    this->Z = v.Z / scalar;
    return *this;
}

void VectorClass::setX(float x)
{
    this->X = x;
}

void VectorClass::setY(float y)
{
    this->Y = y;
}

void VectorClass::setZ(float z)
{
    this->Z = z;
}