#ifndef MATRIX_H
#define MATRIX_H
#include "VectorClass.h"

enum MatrixInverseErrorCode{
	NONE,
	NON_INVERTIBLE_MATRIX
};

class ThreeByThreeMatrix{
	public:
	
	ThreeByThreeMatrix();
	float getDeterminant();
	
	union {
		
	float arrayView [9];
	
	struct{
      	float x0;
		float x1;
		float x2;
		float x3;
		float x4;
		float x5;
		float x6;
		float x7;
		float x8;
    }
	}
	
};


class Matrix{
	
	public:
	Matrix();
	Matrix add(const Matrix & other) const;
	Matrix subtract(const Matrix & other) const;
	VectorClass multVect(VectorClass & vect) const;
	static Matrix getIdentity();
	Matrix multMatrix(const Matrix & other) const;
	
	static MatrixInverseErrorCode inverse(const Matrix & input, const Matrix & output);
	
	private:
	
	float getDeterminant();
	//Return 3x3 sub matrix when a given row and column are discarded from current 4x4 matrix.
	ThreeByThreeMatrix getSubMatrix(int row, int column);
	
	
	
	public:
	union {
		
	float arrayView [16];
	
	struct{
      	float x0;
		float x1;
		float x2;
		float x3;
		float x4;
		float x5;
		float x6;
		float x7;
		float x8;
		float x9;
		float x10;
		float x11;
		float x12;
		float x13;
		float x14;
		float x15;
    }
	}
};





#endif