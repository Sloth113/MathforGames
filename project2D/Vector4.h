#pragma once
#pragma once
#include "Vector3.h"
#include <math.h>
#include <iostream>
class Vector4 {
public:
	float x;
	float y;
	float z;
	float w;

	Vector4();
	Vector4(float x, float y, float z);
	Vector4(Vector3 & vec3);

	Vector4(Vector2 & vec2);



	Vector4 Translate(const Vector4 & other);
	Vector4 Add(const Vector4 & other);
	Vector4 Subtract(const Vector4 & other);
	Vector4 Scale(float scalar);
	Vector4 Multiply(float scalar);
	Vector4 Divide(float scalar);
		  
	Vector4  operator +(const Vector4 & other);
	Vector4  operator -(const Vector4 & other);
	Vector4  operator *(float scalar);
	Vector4  operator /(float scalar);
	Vector4 & operator +=(const Vector4 & other);
	Vector4 & operator -=(const Vector4 & other);
	Vector4 & operator *=(float scalar);
	Vector4 & operator /=(float scalar);



	//Vector3 operator +(const Vector3 & other);
	//Vector3 operator -(const Vector3 & other);
	//Vector3 operator *(float scalar);
	//Vector3 operator /(float scalar);

	float getX();
	float getY();
	float getZ();


	float getMagnitued();
	Vector4 getNormalise();
	void normalise();

	float dot(const Vector4 & other);
	Vector4 cross(const Vector4 & other);


	void stdPrintVec();
};