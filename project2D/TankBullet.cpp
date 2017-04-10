#include "TankBullet.h"

TankBullet::TankBullet()
{
	travTime = 2;
}

TankBullet::TankBullet(aie::Texture * texture):m_texture(texture)
{
	timer = 0;
	travTime = 2;
	vel = Vector3(0, 6, 0);
}

void TankBullet::update(float deltaTime)
{
	timer += deltaTime;
	if (travTime > timer) {
		m_localTransform.translate(vel);
	}else{
		//destroy?
	}
	SceneObject::update(deltaTime);
}

void TankBullet::draw(aie::Renderer2D * renderer)
{

	renderer->drawSpriteTransformed3x3(m_texture, (float*)m_globalTransform);
	SpriteObject::draw(renderer);

}
