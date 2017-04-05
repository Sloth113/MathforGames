#pragma once
#include <math.h>
#include <iostream>
class Vector2 {
protected:

public:
	float x;
	float y;

	Vector2();
	Vector2(float x, float y);
	Vector2 Translate(const Vector2 & other);
	Vector2 Add(const Vector2 & other);
	Vector2 Subtract(const Vector2 & other);
	Vector2 Scale(float scalar);
	Vector2 Multiply(float scalar);
	Vector2 Divide(float scalar);



	Vector2  operator +(const Vector2 & other);
	Vector2  operator -(const Vector2 & other);
	Vector2  operator *(float scalar);
	Vector2  operator /(float scalar);
	Vector2 & operator +=(const Vector2 & other);
	Vector2 & operator -=(const Vector2 & other);
	Vector2 & operator *=(float scalar);
	Vector2 & operator /=(float scalar);



	float getX();
	float getY();


	float getMagnitued();
	float getMagSquar();
	Vector2 getNormalise();
	void normalise();

	float dot(const Vector2 & other);

	float angleBetween(Vector2 & other);

	void stdPrintVec();

};
