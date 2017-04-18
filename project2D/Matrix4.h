#pragma once
#include "Matrix3.h"
#include "Vector3.h"
#include "Vector4.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
//4x4 
class Matrix4 {
public:
	//union {
	//	struct {
	//		float * xAxis;
	//		float * yAxis;
	//		float * zAxis;
	//	};
	//};
	float matrix[4][4];
	int m, n;
	Matrix4();
	Matrix4(float, float, float, float, float, float, float, float, float, float, float, float,	float, float, float, float);

	Matrix4(float[4][4]);

	Matrix4(Matrix3);


	Matrix4(Vector4, Vector4, Vector4, Vector4);
	Matrix4(Vector3, Vector3, Vector3, Vector3);



	Matrix4 operator * (Matrix4);
	Matrix4 operator*(Matrix3 m3);
	Vector4 operator * (Vector4);


	Matrix4 getTranspose();
	void transpose();

	Vector4 & operator [] (const int axis);

	operator float*();


	void stdPrintMat();

	void setRotateX(float angle);
	void setRotateY(float angle);
	void setRotateZ(float angle);

	void setRotate(float x, float y, float z);

	void translate(Vector4 v);
	void translate(Vector3 v);


};