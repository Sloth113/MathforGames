#pragma once
#include "Vector3.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
//Currently only supports 2x2 or 3x3
class Matrix3 {
public:
	//union {
	//	struct {
	//		float * xAxis;
	//		float * yAxis;
	//		float * zAxis;
	//	};
	//};
	float matrix[3][3];
	int m, n;
	Matrix3();
	Matrix3(float, float, float, float, float, float, float, float, float);
	
	Matrix3(float[3][3]);
	
	
	
	Matrix3(Vector3, Vector3, Vector3);

	

	Matrix3 operator * (Matrix3);
	Vector3 operator * (Vector3);


	Matrix3 getTranspose();
	void transpose();

	Vector3& operator [] (const int axis);

	operator float*();


	void stdPrintMat();

	void setRotateX(float angle);
	void setRotateY(float angle);
	void setRotateZ(float angle);

	void setRotate(float x, float y, float z);

	void translate(Vector3 v);


};