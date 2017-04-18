#pragma once
#include "Vector2.h"
#include <math.h>
#include <iostream>
class Vector3 {
public:
	float x;
	float y;
	float z;

	Vector3();
	Vector3(float x, float y, float z);
	Vector3(Vector2 & vec2);


	
	Vector3 Translate(const Vector3 & other);
	Vector3 Add(const Vector3 & other);
	Vector3 Subtract(const Vector3 & other);
	Vector3 Scale(float scalar);
	Vector3 Multiply(float scalar);
	Vector3 Divide(float scalar);
	
	Vector3  operator +(const Vector3 & other);
	Vector3  operator -(const Vector3 & other);
	Vector3  operator *(float scalar);
	Vector3  operator /(float scalar);
	Vector3 & operator +=(const Vector3 & other);
	Vector3 & operator -=(const Vector3 & other);
	Vector3 & operator *=(float scalar);
	Vector3 & operator /=(float scalar);



	//Vector3 operator +(const Vector3 & other);
	//Vector3 operator -(const Vector3 & other);
	//Vector3 operator *(float scalar);
	//Vector3 operator /(float scalar);


	float& operator[](const int index);
	operator float*();

	float getX();
	float getY();
	float getZ();
   

	float getMagnitued();
	float getMagSquar();
	Vector3 getNormalise();
	void normalise();

	float dot(const Vector3 & other);
	Vector3 cross(const Vector3 & other);


	void stdPrintVec();
};