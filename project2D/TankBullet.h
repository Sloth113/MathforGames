#pragma once
#include "SpriteObject.h"
class TankBullet :public SpriteObject {
public:
	TankBullet();
	TankBullet(aie::Texture* texture);
	virtual ~TankBullet() {};
	virtual void update(float deltaTime);
	virtual void draw(aie::Renderer2D* renderer);



protected:
	aie::Texture* m_texture;
private:
	float 	travTime;
	float timer;
	Vector3 vel;

};