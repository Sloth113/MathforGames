#pragma once
#include "Vector2.h"
#include "Vector3.h"
#include <iostream>
//Currently only supports 2x2 or 3x3
class Matrix {
public:
	//union {
	//	struct {
	//		float * xAxis;
	//		float * yAxis;
	//		float * zAxis;
	//	};
	//};
	float ** matrix;
	int m, n;
	Matrix();
	Matrix(float,float,float,float);
	Matrix(float, float, float, float, float, float, float, float, float);


	Matrix(int, int);

	//Matrix(float[2], float[2]);
	//Matrix(float[3], float[3], float[3]);

	//Matrix(float[2][2]);
	//Matrix(float[3][3]);
	Matrix(Vector2);
	Matrix(Vector3);
	Matrix(Vector2, Vector2);
	Matrix(Vector3, Vector3, Vector3);

	Matrix(const Matrix &mat);


	//~Matrix();


	Matrix operator * (Matrix);
	Matrix operator * (Vector2);
	Matrix operator * (Vector3);


	Matrix getTranspose();
	void transpose();

	float* operator [] (const int axis);

	//float*

	void stdPrintMat();

	


};