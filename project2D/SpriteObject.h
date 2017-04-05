#pragma once
#include "SceneObject.h"
class SpriteObject :public SceneObject {
public:
	SpriteObject();
	SpriteObject(aie::Texture* texture);
	virtual ~SpriteObject() {};
	virtual void update(float deltaTime);
	virtual void draw(aie::Renderer2D* renderer);



protected:
	aie::Texture* m_texture;
};