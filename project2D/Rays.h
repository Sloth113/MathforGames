#pragma once
#include "Vector3.h"
#include "RoundThings.h"
#include "AxisABBox.h"
class Rays {
public:
	Vector3 origin;
	Vector3 direction;
	float length;
	bool bool3D;

	Rays();

	Rays(Vector3 ori, Vector3 dir, float len);
	Rays(Vector3 ori, Vector3 end);
	Rays(Vector3 dir);
	
	Rays(Vector2 ori, Vector2 dir, float len);
	Rays(Vector2 ori, Vector2 end);
	Rays(Vector2 dir);
	
	bool collides(RoundThings thing);
	bool collides2D(AxisABBox thing);
	bool collides(Vector3 point, float tol);

	Vector3 closestPoint(Vector3 p);
	float distFrom(Vector3 p);



};