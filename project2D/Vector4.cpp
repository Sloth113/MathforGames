#include "Vector4.h"

Vector4::Vector4() :Vector4(0.0f, 0.0f, 0.0f)
{

}

Vector4::Vector4(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector4::Vector4(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

Vector4::Vector4(Vector3 & vec3)
{
	this->x = vec3.getX();
	this->y = vec3.getX();
	this->z = vec3.getZ();
}

Vector4::Vector4(Vector2 & vec2)
{
	this->x = vec2.getX();
	this->y = vec2.getX();
	this->z = 0.0f;
}

Vector4 Vector4::Translate(const Vector4 & other)
{
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
	Vector4 res = Vector4(this->x, this->y, this->z);
	return res;
}

Vector4 Vector4::Add(const Vector4 & other)
{
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
	Vector4 res = Vector4(this->x, this->y, this->z);
	return res;
}

Vector4 Vector4::Subtract(const Vector4 & other)
{
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
	Vector4 res = Vector4(this->x, this->y, this->z);
	return res;
}

Vector4 Vector4::Scale(float scalar)
{
	this->x *= scalar;
	this->y *= scalar;
	this->z *= scalar;
	Vector4 res = Vector4(this->x, this->y, this->z);
	return res;
}

Vector4 Vector4::Multiply(float scalar)
{
	this->x *= scalar;
	this->y *= scalar;
	this->z *= scalar;
	Vector4 res = Vector4(this->x, this->y, this->z);
	return res;
}

Vector4 Vector4::Divide(float scalar)
{
	this->x /= scalar;
	this->y /= scalar;
	this->z /= scalar;
	Vector4 res = Vector4(this->x, this->y, this->z);
	return res;
}

Vector4 Vector4::operator+(const Vector4 & other)
{

	Vector4 res = Vector4(this->x + other.x, this->y + other.y, this->z + other.z);
	return res;
}
Vector4 Vector4::operator-(const Vector4 & other)
{
	Vector4 res = Vector4(this->x - other.x, this->y - other.y, this->z - other.z);
	return res;
}
Vector4 Vector4::operator*(float scalar)
{
	Vector4 res = Vector4(this->x * scalar, this->y * scalar, this->z * scalar);
	return res;
}
Vector4 Vector4::operator/(float scalar)
{
	Vector4 res = Vector4(this->x / scalar, this->y / scalar, this->z / scalar);
	return res;
}

Vector4 & Vector4::operator+=(const Vector4 & other)
{
	*this = *this + other;
	return *this;
}

Vector4 & Vector4::operator-=(const Vector4 & other)
{
	*this = *this - other;
	return *this;
}

Vector4 & Vector4::operator*=(float scalar)
{
	*this = *this * scalar;
	return *this;
}

Vector4 & Vector4::operator/=(float scalar)
{
	*this = *this / scalar;
	return *this;
}

float & Vector4::operator[](const int index)
{
	if (index <= 0) return x;
	if (index == 1) return y;
	if (index == 2) return z;
	if (index >= 3) return w;
}

Vector4::operator float*()
{
	float * ar = new float[4];
	ar[0] = x;
	ar[1] = y;
	ar[2] = z;
	ar[3] = w;
	return ar;
}

float Vector4::getX()
{
	return x;
}

float Vector4::getY()
{
	return y;
}

float Vector4::getZ()
{
	return z;
}

float Vector4::getW()
{
	return w;
}

float Vector4::getMagnitued()
{
	return  (float)sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

Vector4 Vector4::getNormalise()
{
	Vector4 normVec = Vector4(x / getMagnitued(), y / getMagnitued(), z / getMagnitued());
	return normVec;
}

void Vector4::normalise()
{
	*this = *this / getMagnitued();
}

float Vector4::dot(const Vector4 & other)
{
	return this->x * other.x + this->y * other.y + this->z * other.z;
}

Vector4 Vector4::cross(const Vector4 & other)
{
	Vector4 cross = Vector4();
	cross.x = this->y*other.z - this->z*other.y;
	cross.y = this->z*other.x - this->x*other.z;
	cross.z = this->x*other.y - this->y*other.x;
	return cross;
}

void Vector4::stdPrintVec()
{
	std::cout << "Vector4 (" << x << "," << y << "," << z  << "," << w << ")" << std::endl;
}
