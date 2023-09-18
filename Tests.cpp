#include <iostream>
#include "Particle.h"
#include "VectorClass.h"

//need to build these out and on on collission elements and particle elements next
//call mingw32-make 
    //then call ./runTests
int test_VectorAdd()
{
    return 1;
}

int test_VectorCrossProd()
{
    return 1;
}

int test_VectorDotProd()
{
    return 1;
}

int test_VectorSub()
{
    return 1;
}

int test_VectorScaled()
{
    return 1;
}

int test_MatrixAdd()
{
    return 1;
}

int test_MatrixCrossProd()
{
    return 1;
}

int test_MatrixDotProd()
{
    return 1;
}

int test_MatrixSub()
{
    return 1;
}

int test_MatrixScaled()
{
    return 1;
}


int main(int argc, char *argv[])
{

    VectorClass p = VectorClass(10, 20, 30, 1);
    VectorClass v = VectorClass(10, 20, 30, 1);
    VectorClass a = VectorClass(10, 20, 30, 1);
    Particle test_p = Particle(p, v, a);
    test_p.resetCompMass(200);
    test_p.setCurrForce(2, 3, 2);
    float force_1 = 1.0f;
    float force_2 = 2.0f;

    if (
    test_VectorAdd() &&
    test_VectorCrossProd() &&
    test_VectorDotProd() &&
    test_VectorScaled() &&
    test_VectorSub() &&
    test_MatrixAdd() &&
    test_MatrixCrossProd() &&
    test_MatrixDotProd() &&
    test_MatrixScaled() &&
    test_MatrixSub()
    )

    {return EXIT_SUCCESS; }

    else {EXIT_FAILURE;}
}