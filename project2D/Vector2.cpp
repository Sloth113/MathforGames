#include "Vector2.h"

Vector2::Vector2() :Vector2(0.0f, 0.0f)
{
	this->x = 0.0f;
	this->y = 0.0f;
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2 Vector2::Translate(const Vector2 & other)
{
	this->x += other.x;
	this->y += other.y;
	Vector2 res = Vector2(this->x, this->y);
	return res;
}

Vector2 Vector2::Add(const Vector2 & other)
{
	this->x += other.x;
	this->y += other.y;
	Vector2 res = Vector2(x, y);
	return res;
}

Vector2 Vector2::Subtract(const Vector2 & other)
{
	this->x -= other.x;
	this->y -= other.y;
	Vector2 res = Vector2(this->x, this->y);
	return res;
}

Vector2 Vector2::Scale(float scalar)
{
	this->x *= scalar;
	this->y *= scalar;
	Vector2 res = Vector2(this->x, this->y);
	return res;
}

Vector2 Vector2::Multiply(float scalar)
{
	this->x *= scalar;
	this->y *= scalar;
	Vector2 res = Vector2(this->x, this->y);
	return res;
}

Vector2 Vector2::Divide(float scalar)
{
	this->x /= scalar;
	this->y /= scalar;
	Vector2 res = Vector2(this->x, this->y);
	return res;
}

Vector2 Vector2::operator+(const Vector2 & other)
{
	Vector2 res = Vector2(this->x + other.x, this->y + other.y);
	return res;
}
Vector2 Vector2::operator-(const Vector2 & other)
{
	Vector2 res = Vector2(this->x - other.x, this->y - other.y);
	return res;
}
Vector2 Vector2::operator*(float scalar)
{
	Vector2 res = Vector2(this->x * scalar, this->y * scalar);
	return res;
}
Vector2 Vector2::operator/(float scalar)
{
	Vector2 res = Vector2(this->x / scalar, this->y / scalar);
	return *this;
}

Vector2 & Vector2::operator+=(const Vector2 & other)
{
	*this = *this + other;
	return *this;
}

Vector2 & Vector2::operator-=(const Vector2 & other)
{
	*this = *this - other;
	return *this;
}

Vector2 & Vector2::operator*=(float scalar)
{
	*this = *this * scalar;
	return *this;
}

Vector2 & Vector2::operator/=(float scalar)
{
	*this = *this / scalar;
	return *this;
}

float Vector2::getX()
{
	return x;
}

float Vector2::getY()
{
	return y;
}

float Vector2::getMagnitued()
{
	return (float)sqrt(pow(x,2.0)+pow(y,2.0));
}
float Vector2::getMagSquar()
{
	return x * x + y *y;
}
Vector2 Vector2::getNormalise()
{
	Vector2 normVec = Vector2(x / getMagnitued(), y / getMagnitued());
	return normVec;
}

void Vector2::normalise()
{
	*this = *this / getMagnitued();
}

float Vector2::dot(const Vector2 & other)
{
	return this->x * other.x + this->y * other.y;
}

float Vector2::angleBetween(Vector2 & other)
{
	float result;
	Vector2 normal1 = this->getNormalise();
	Vector2 normalOther = other.getNormalise();
	result = acos(normal1.dot(normalOther));
	return result;

}

void Vector2::stdPrintVec()
{
	std::cout << "Vector2 (" << x << "," << y << ")" << std::endl;
}



