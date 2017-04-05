#include "ShapeObject.h"

ShapeObject::ShapeObject()
{

	m_shape = 1;
	m_width = 1;
	m_height = 1;
}

ShapeObject::ShapeObject(int shape)
{
	m_shape = shape;
	m_width = 1;
	m_height = 1;
}

void ShapeObject::update(float deltaTime)
{
	SceneObject::update(deltaTime);
}

void ShapeObject::draw(aie::Renderer2D * renderer)
{
	//renderer->drawCircle(m_localTransform.)
	SceneObject::draw(renderer);
}
