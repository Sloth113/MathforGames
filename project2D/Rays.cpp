#include "Rays.h"

Rays::Rays()
{
	bool3D = false;
	origin = Vector3();
	direction = Vector3();
	

}

Rays::Rays(Vector3 ori, Vector3 dir)
{
	bool3D = true;
	origin = ori;
	direction = dir;
	
}

Rays::Rays(Vector3 dir)
{
	bool3D = true;
	origin = Vector3();
	direction = dir;
	
}


Rays::Rays(Vector2 ori, Vector2 dir)
{

	bool3D = false;
	origin = ori;
	direction = dir;

}

Rays::Rays(Vector2 dir)
{
	bool3D = false;
	origin = Vector2();
	direction = dir;

}


bool Rays::collides(RoundThings thing)
{
	if (distFrom(Vector3(thing.x, thing.y, thing.z)) <= thing.radi) {
		return true;
	}else{
		return false;
	}
}

bool Rays::collides(AxisABBox thing)
{
	return false;
}

bool Rays::collides(Vector3 point)
{
	return false;
}

bool Rays::collides(Vector2 point)
{
	return false;
}

Vector3 Rays::closestPoint(Vector3 p)
{
	Vector3 dist = p - origin;
	float fromOrig = dist.dot(direction.getNormalise());
	//Clamp
	if (fromOrig <= 0) fromOrig = 0;
	if (fromOrig >= direction.getMagnitued()) fromOrig = direction.getMagnitued();

	dist = direction.getNormalise();
	return origin + dist * fromOrig;
}

float Rays::distFrom(Vector3 p)
{
	Vector3 cp = closestPoint(p);
	cp = cp - p;
	return cp.getMagnitued();
}
