#pragma once
#include "SceneObject.h"
class ShapeObject :public SceneObject {
public:
	ShapeObject();
	ShapeObject(int shape);
	virtual ~ShapeObject() {};
	virtual void update(float deltaTime);
	virtual void draw(aie::Renderer2D* renderer);



protected:
	int m_shape; //1 circle, 2 square
	int m_width, m_height; //width is radius
};