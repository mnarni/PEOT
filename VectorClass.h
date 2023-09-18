#ifndef VectorClass_H
#define VectorClass_H
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

#pragma once

class VectorClass
{
public:
    VectorClass();
    VectorClass(float, float, float, float);
    ~VectorClass();

    float getX();
    float getY();
    float getZ();
    float getW();
    float sum();
    void  setX(float x);
    void  setY(float y);
    void  setZ(float z);

    VectorClass operator+(const VectorClass &v);
    VectorClass operator-(const VectorClass &v);
    VectorClass operator*(const VectorClass &v);
    VectorClass operator/(const VectorClass &v);

    float length();
    float lengthSquared();
    VectorClass normalize();
    VectorClass crossProduct(const VectorClass &v);
    VectorClass scaledVector(const VectorClass &v, float scalar);
    VectorClass divideVector(const VectorClass &v, float scalar);

public:
    float X;
    float Y;
    float Z;
    float W;
};
static float dist(VectorClass a, VectorClass b)
{
    float dx = a.getX() - b.getX();
    float dy = a.getY() - b.getY();
    float dz = a.getZ() - b.getZ();
    float dw = a.getW() - b.getW();
    return sqrt(dx * dx + dy * dy + dz * dz + dw * dw);
}

static float dotProduct(VectorClass a, VectorClass b)
{
    return a.getX() * b.getX() + a.getY() * b.getY() + a.getZ() * b.getZ() + a.getW() * b.getW();
}


/*
int main()
{

    float a = 4.0;
    float b = 6.0;
    float c = 8.0;
    float d = 3.0;

    VectorClass obj1(a, b, c, d);

    cout << obj1.sum() << endl;

    a = 2.0;
    b = 3.0;
    c = 5.0;
    d = 7.0;

    VectorClass obj2(a, b, c, d);

    VectorClass obj3;
    obj3 = obj1 + obj2;
    cout << obj3.sum() << endl;

    obj3 = obj1 - obj2;
    cout << obj3.sum() << endl;

    obj3 = obj1 * obj2;
    cout << obj3.sum() << endl;

    obj3 = obj1 / obj2;
    cout << obj3.sum() << endl;

    cout << obj1.length() << endl;

    cout << dist(obj1, obj2) << endl;

    obj3 = obj1.normalize();
    cout << obj3.sum() << endl;

    cout << dotProduct(obj1, obj2) << endl;

    obj3 = obj1.crossProduct(obj2);

    cout<< "Cross Product"<< endl;

    cout << obj3.getX() << endl;
    cout << obj3.getY() << endl;
    cout << obj3.getZ() << endl;
    cout << obj3.getW() << endl;
}
*/

#endif