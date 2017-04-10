#pragma once
#include "SpriteObject.h"
class EnemyTank :public SpriteObject {
public:
	EnemyTank();
	EnemyTank(aie::Texture* texture);
	virtual ~EnemyTank() {};
	virtual void update(float deltaTime);
	virtual void draw(aie::Renderer2D* renderer);



protected:
	aie::Texture* m_texture;
private:
	float tankSpeed;
	float tankRotateSpeed;
	Vector3 tankVel;
	Vector3 tankChange;

};