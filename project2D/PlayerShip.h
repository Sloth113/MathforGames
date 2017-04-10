#pragma once
#include "SpriteObject.h"
class PlayerShip :public SpriteObject {
public:
	PlayerShip();
	PlayerShip(aie::Texture* texture);
	virtual ~PlayerShip() {};
	virtual void update(float deltaTime);
	virtual void draw(aie::Renderer2D* renderer);



protected:
	aie::Texture* m_texture;
private:
	float shipSpeed; 
	float shipRotateSpeed;
	Vector3 shipVel;
	Vector3 shipChange;
	
};