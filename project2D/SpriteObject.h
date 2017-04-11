#pragma once
#include "SceneObject.h"
class SpriteObject :public SceneObject {
public:
	SpriteObject();
	SpriteObject(aie::Texture* texture);
	SpriteObject(aie::Texture * texture, Vector3 dis);
	virtual ~SpriteObject() {};
	virtual void update(float deltaTime);
	virtual void draw(aie::Renderer2D* renderer);



protected:
	aie::Texture* m_texture;
};