#pragma once
#include "Vector3.h"
#include "RoundThings.h"
#include "AxisABBox.h"
class Rays {
public:
	Vector3 origin;
	Vector3 direction;
	bool bool3D;

	Rays();

	Rays(Vector3 ori, Vector3 dir);
	Rays(Vector3 dir);
	

	Rays(Vector2 ori, Vector2 dir);
	Rays(Vector2 dir);
	
	bool collides(RoundThings thing);
	bool collides(AxisABBox thing);
	bool collides(Vector3 point);
	bool collides(Vector2 point);

	Vector3 closestPoint(Vector3 p);
	float distFrom(Vector3 p);



};