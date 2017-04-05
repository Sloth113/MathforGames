#pragma once
#include "Vector2.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
//Supports 2x2 
class Matrix2 {
public:
	float matrix[2][2];
	int m, n;
	Matrix2();
	Matrix2(float, float, float, float);
	//Matrix(float[2][2]);
	
	Matrix2(Vector2, Vector2);
	
	

	Matrix2 operator * (Matrix2);
	Vector2 operator * (Vector2);
	
	Matrix2 getTranspose();
	void transpose();

	float* operator [] (const int axis);

	operator float*();

	void stdPrintMat();

	void setRotate(float angle);


};