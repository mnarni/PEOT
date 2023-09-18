#include "Matrix.h"



Matrix Matrix::add(const Matrix & other) const{
	//Rework with more efficient solution later.
	
	Matrix retVal = Matrix();
	
	retVal.x0 = this->x0 + other.x0;
	retVal.x1 = this->x1 + other.x1;
	retVal.x2 = this->x2 + other.x2;
	retVal.x3 = this->x3 + other.x3;
	retVal.x4 = this->x4 + other.x4;
	retVal.x5 = this->x5 + other.x5;
	retVal.x6 = this->x6 + other.x6;
	retVal.x7 = this->x7 + other.x7;
	retVal.x8 = this->x8 + other.x8;
	retVal.x9 = this->x9 + other.x9;
	retVal.x10 = this->x10 + other.x10;
	retVal.x11 = this->x11 + other.x11;
	retVal.x12 = this->x12 + other.x12;
	retVal.x13 = this->x13 + other.x13;
	retVal.x14 = this->x14 + other.x14;
	retVal.x15 = this->x15 + other.x15;
	
	return retVal;
	
}

Matrix Matrix::subtract(const Matrix & other) const{
	
	Matrix retVal = Matrix();
	
	retVal.x0 = this->x0 - other.x0;
	retVal.x1 = this->x1 - other.x1;
	retVal.x2 = this->x2 - other.x2;
	retVal.x3 = this->x3 - other.x3;
	retVal.x4 = this->x4 - other.x4;
	retVal.x5 = this->x5 - other.x5;
	retVal.x6 = this->x6 - other.x6;
	retVal.x7 = this->x7 - other.x7;
	retVal.x8 = this->x8 - other.x8;
	retVal.x9 = this->x9 - other.x9;
	retVal.x10 = this->x10 - other.x10;
	retVal.x11 = this->x11 - other.x11;
	retVal.x12 = this->x12 - other.x12;
	retVal.x13 = this->x13 - other.x13;
	retVal.x14 = this->x14 - other.x14;
	retVal.x15 = this->x15 - other.x15;
	
	return retVal;
	
}

Matrix Matrix::multMatrix(const Matrix & other) const{
	
	Matrix retVal = Matrix();

	//Can be lots of dot products
	
	retVal.x0 = this->x0 * other.x0 + this->x1 * other.x4 + this->x2 * other.x8 + this->x3 * other.x12;
	retVal.x1 = this->x0 * other.x1 + this->x1 * other.x5 + this->x2 * other.x9 + this->x3 * other.x13;
	retVal.x2 = this->x0 * other.x2 + this->x1 * other.x6 + this->x2 * other.x10 + this->x3 * other.x14;
	retVal.x3 = this->x0 * other.x3 + this->x1 * other.x7 + this->x2 * other.x11 + this->x3 * other.x15;
	
	retVal.x4 = this->x4 * other.x0 + this->x5 * other.x4 + this->x6 * other.x8 + this->x3 * other.x12;
	retVal.x5 = this->x4 * other.x1 + this->x5 * other.x5 + this->x6 * other.x9 + this->x3 * other.x13;
	retVal.x6 = this->x4 * other.x2 + this->x5 * other.x6 + this->x6 * other.x10 + this->x3 * other.x14;
	retVal.x7 = this->x4 * other.x3 + this->x5 * other.x7 + this->x6 * other.x11 + this->x3 * other.x15;
	
	retVal.x8 = this->x8 * other.x0 + this->x9 * other.x4 + this->x10 * other.x8 + this->x11 * other.x12;
	retVal.x9 = this->x8 * other.x1 + this->x9 * other.x5 + this->x10 * other.x9 + this->x11 * other.x13;
	retVal.x10 = this->x8 * other.x2 + this->x9 * other.x6 + this->x10 * other.x10 + this->x11 * other.x14;
	retVal.x11 = this->x8 * other.x3 + this->x9 * other.x7 + this->x10 * other.x11 + this->x11 * other.x15;
	
	
	retVal.x12 = this->x12 * other.x0 + this->x13 * other.x4 + this->x14 * other.x8 + this->x15 * other.x12;
	retVal.x13 = this->x12 * other.x1 + this->x13 * other.x5 + this->x14 * other.x9 + this->x15 * other.x13;
	retVal.x14 = this->x12 * other.x2 + this->x13 * other.x6 + this->x14 * other.x10 + this->x15 * other.x14;
	retVal.x15 = this->x12 * other.x3 + this->x13 * other.x7 + this->x14 * other.x11 + this->x15 * other.x15;
	
	return retVal;
}

Matrix Matrix::getIdentity(){
	Matrix identity = Matrix();
	
	identity.x0 = 1;
	identity.x5 = 1;
	identity.x10 = 1;
	identity.x15 = 1;
	
	return identity;
}

Matrix::Matrix()
:x0(0),x1(0), x2(0), x3(0), x4(0), x5(0), x6(0), x7(0), x8(0), x9(0), x10(0), x11(0), x12(0), x13(0), x14(0), x15(0)
{}

VectorClass Matrix::multVect(VectorClass& vect) const{
	//Dot product refactor
	float x = this->x0 * vect.getX() + this->x1 * vect.getY() + this->x2 * vect.getZ() + this->x3 * vect.getW();
	float y = this->x4 * vect.getX() + this->x5 * vect.getY() + this->x6 * vect.getZ() + this->x7 * vect.getW();
	float z = this->x8 * vect.getX() + this->x9 * vect.getY() + this->x10 * vect.getZ() + this->x11 * vect.getW();
	float w = this->x12 * vect.getX() + this->x13 * vect.getY() + this->x14 * vect.getZ() + this->x15 * vect.getW();

	return VectorClass(x, y, z, w);
}

ThreeByThreeMatrix Matrix::getSubMatrix(int row, int column){
	
	ThreeByThreeMatrix retVal;
	int retValItr = 0;
	
    for(int i=0;i<16;i++){
		if((i>=(row*4) && i<((row+1)*4)) || i%4 == column){
			continue;
		}else{
			retVal.arrayView[retValItr] = this->arrayView[i];
			retValItr+=1;
		}
	}
	
}

ThreeByThreeMatrix::ThreeByThreeMatrix()
:x0(0),x1(0), x2(0), x3(0), x4(0), x5(0), x6(0), x7(0), x8(0)
{}

float ThreeByThreeMatrix::getDeterminant(){
	return ((this->x0)*(this->x4)*(this->x8))+
	((this->x2)*(this->x3)*(this->x7)) +
	((this->x1)*(this->x5)*(this->x6)) - 
	((this->x2)*(this->x4)*(this->x6)) -
	((this->x0)*(this->x5)*(this->x7)) -
	((this->x8)*(this->x1)*(this->x3));
}

float Matrix::getDeterminant(){
	
	ThreeByThreeMatrix sub1 = this->getSubMatrix(0,0);
	ThreeByThreeMatrix sub2 = this->getSubMatrix(1,0);
	ThreeByThreeMatrix sub3 = this->getSubMatrix(2,0);
	ThreeByThreeMatrix sub4 = this->getSubMatrix(3,0);
	
	return (((this->x0)*sub1.getDeterminant()) - ((this->x4)*(sub2.getDeterminant()))+ ((this->x8)*(sub3.getDeterminant())) -((this->x12)*(sub4.getDeterminant())));
	
	
}

MatrixInverseErrorCode Matrix::inverse(const Matrix & input, const Matrix & output){
	float divisor = input->getDeterminant();
	if(0 == divisor){
		return MatrixInverseErrorCode::NON_INVERTIBLE_MATRIX;
	}
	
	for(int i=0;i<16;i++){
		int row = i/4;
		int column = i%4;
		
		ThreeByThreeMatrix tmp = input->getSubMatrix(column, row);
		output->arrayView[i] = (tmp.getDeterminant())/divisor;
		if(1==(row+column)%2){
			output->arrayView[i] = output->arrayView[i]*-1;
		}
	}
	return MatrixInverseErrorCode::NONE;
}