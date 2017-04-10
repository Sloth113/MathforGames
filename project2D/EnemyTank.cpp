#include "EnemyTank.h"

EnemyTank::EnemyTank()
{
}

EnemyTank::EnemyTank(aie::Texture * texture) :m_texture(texture)
{

	tankRotateSpeed = 50; //Angle
	tankChange = Vector3(0, 4, 0);
	tankVel = Vector3(0, 0, 0);
	shotTimer = 0;
	reloadTime = 3;

	
}

void EnemyTank::setBullet(aie::Texture * t) {
	bulletText = t;
}

void EnemyTank::update(float deltaTime)
{

	tankVel = Vector3(0, 0, 0);
	aie::Input* input = aie::Input::getInstance();

	//Barrel 'object

	Matrix3 barrelTrans = m_children[0]->getLocal();
	
	//MAKE AI
	if (input->isKeyDown(aie::INPUT_KEY_KP_2))
		tankVel = tankVel + tankChange;

	if (input->isKeyDown(aie::INPUT_KEY_KP_8))
		tankVel = tankVel - tankChange;

	if (input->isKeyDown(aie::INPUT_KEY_KP_4))
		m_localTransform.setRotateZ(tankRotateSpeed * deltaTime);

	if (input->isKeyDown(aie::INPUT_KEY_KP_6))
		m_localTransform.setRotateZ(-tankRotateSpeed * deltaTime);

	//bad but works
	if (input->isKeyDown(aie::INPUT_KEY_KP_7))
		barrelTrans.setRotateZ(50 * deltaTime);
	if (input->isKeyDown(aie::INPUT_KEY_KP_9))
		barrelTrans.setRotateZ(-50 * deltaTime);

	//weapon fire
	if (input->isKeyDown(aie::INPUT_KEY_KP_5) && shotTimer >= reloadTime) {
		//reload time 
		shotTimer = 0;
		//place in world (not child)
		
		

		TankBullet * b;

		b = new TankBullet(bulletText);
		Matrix3 bPos = m_children[0]->getLocal();
		bPos.translate(Vector3(0, 50, 0));
		b->setLocal(bPos);

		addChild(b);

		//m_parent->addChild(b);
	}
	else if (shotTimer < reloadTime) {
		shotTimer += deltaTime;
	}



	m_children[0]->setLocal(barrelTrans);

	m_localTransform.translate(tankVel);
	updateGlobalTransform();

	SpriteObject::update(deltaTime);

}

void EnemyTank::draw(aie::Renderer2D * renderer)
{

	renderer->drawSpriteTransformed3x3(m_texture, (float*)m_globalTransform);
	SpriteObject::draw(renderer);
}
