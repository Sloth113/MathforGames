#include "Vector3.h"

Vector3::Vector3() :Vector3(0.0f,0.0f,0.0f)
{

}

Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::Vector3(Vector2 & vec2)
{
	this->x = vec2.getX();
	this->y = vec2.getX();
	this->z = 0.0f;
}

Vector3 Vector3::Translate(const Vector3 & other)
{
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
	Vector3 res = Vector3(this->x, this->y, this->z);
	return res;
}

Vector3 Vector3::Add(const Vector3 & other)
{
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
	Vector3 res = Vector3(this->x, this->y, this->z);
	return res;
}

Vector3 Vector3::Subtract(const Vector3 & other)
{
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
	Vector3 res = Vector3(this->x, this->y, this->z);
	return res;
}

Vector3 Vector3::Scale(float scalar)
{
	this->x *= scalar;
	this->y *= scalar;
	this->z *= scalar;
	Vector3 res = Vector3(this->x, this->y, this->z);
	return res;
}

Vector3 Vector3::Multiply(float scalar)
{
	this->x *= scalar;
	this->y *= scalar;
	this->z *= scalar;
	Vector3 res = Vector3(this->x, this->y, this->z);
	return res;
}

Vector3 Vector3::Divide(float scalar)
{
	this->x /= scalar;
	this->y /= scalar;
	this->z /= scalar;
	Vector3 res = Vector3(this->x, this->y, this->z);
	return res;
}

Vector3 Vector3::operator+(const Vector3 & other)
{

	Vector3 res = Vector3(this->x + other.x, this->y + other.y,	this->z + other.z);
	return res;
}
Vector3 Vector3::operator-(const Vector3 & other)
{
	Vector3 res = Vector3(this->x - other.x, this->y - other.y, this->z - other.z);
	return res;
}
Vector3 Vector3::operator*(float scalar)
{
	Vector3 res = Vector3(this->x * scalar, this->y * scalar, this->z * scalar);
	return res;
}
Vector3 Vector3::operator/(float scalar)
{
	Vector3 res = Vector3(this->x / scalar, this->y / scalar, this->z / scalar);
	return res;
}

Vector3 & Vector3::operator+=(const Vector3 & other)
{
	*this = *this + other;
	return *this;
}

Vector3 & Vector3::operator-=(const Vector3 & other)
{
	*this = *this - other;
	return *this;
}

Vector3 & Vector3::operator*=(float scalar)
{
	*this = *this * scalar;
	return *this;
}

Vector3 & Vector3::operator/=(float scalar)
{
	*this = *this / scalar;
	return *this;
}

//Vector3  Vector3::operator+(const Vector3 & other)
//{
//
//	Vector3 res = Vector3();
//	res.m_x = m_x + other.m_x;
//	res.m_y = m_y + other.m_y;
//	res.m_z = m_z + other.m_z;
//	return res;
//}
//
//Vector3  Vector3::operator-(const Vector3 & other)
//{
//
//	Vector3 res = Vector3();
//	res.m_x = m_x - other.m_x;
//	res.m_y = m_y - other.m_y;
//	res.m_z = m_z - other.m_z;
//	return res;
//}
//
//Vector3  Vector3::operator*(float scalar)
//{
//
//	Vector3 res = Vector3();
//	res.m_x = m_x * scalar;
//	res.m_y = m_y * scalar;
//	res.m_z = m_z * scalar;
//	return res;
//}
//
//Vector3  Vector3::operator/(float scalar)
//{
//
//	Vector3 res = Vector3();
//	res.m_x = m_x / scalar;
//	res.m_y = m_y / scalar;
//	res.m_z = m_z / scalar;
//	return res;
//}








float Vector3::getX()
{
	return x;
}

float Vector3::getY()
{
	return y;
}

float Vector3::getZ()
{
	return z;
}

float Vector3::getMagnitued()
{
	return  (float)sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

float Vector3::getMagSquar()
{
	return x*x + y*y + z*z;
}

Vector3 Vector3::getNormalise()
{
	Vector3 normVec = Vector3(x / getMagnitued(), y / getMagnitued(), z / getMagnitued());
	return normVec;
}

void Vector3::normalise()
{
	*this = *this / getMagnitued();
}

float Vector3::dot(const Vector3 & other)
{
	return this->x * other.x + this->y * other.y + this->z * other.z;
}

Vector3 Vector3::cross(const Vector3 & other)
{
	Vector3 cross = Vector3();
	cross.x = this->y*other.z - this->z*other.y;
	cross.y = this->z*other.x - this->x*other.z;
	cross.z = this->x*other.y - this->y*other.x;
	return cross;
}

void Vector3::stdPrintVec()
{
	std::cout << "Vector3 (" << x << "," << y << "," << z << ")" << std::endl;
}
