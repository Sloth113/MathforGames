#include "SpriteObject.h"

SpriteObject::SpriteObject()
{
	m_texture = nullptr;
}

SpriteObject::SpriteObject(aie::Texture * texture) :m_texture(texture)
{

}

void SpriteObject::update(float deltaTime)
{

	//Logic
	SceneObject::update(deltaTime);

}

void SpriteObject::draw(aie::Renderer2D * renderer)
{
	renderer->drawSpriteTransformed3x3(m_texture, (float*)m_globalTransform);
	SceneObject::draw(renderer);
}


