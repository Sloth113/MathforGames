#include "PlayerShip.h"

PlayerShip::PlayerShip()
{
}

PlayerShip::PlayerShip(aie::Texture * texture) :m_texture(texture)
{

	//SpriteObject::SpriteObject(texture);
	shipRotateSpeed = 50; //Angle
	

	shipVel = Vector3(0, 3, 0);
	shipChange = Vector3(0, 2, 0);

}

void PlayerShip::update(float deltaTime)
{
	//Player logic

	shipVel = Vector3(0, 3, 0);
	aie::Input* input = aie::Input::getInstance();

	//MAKE AI
	if (input->isKeyDown(aie::INPUT_KEY_W))
		shipVel = shipVel + shipChange;

	if (input->isKeyDown(aie::INPUT_KEY_S))
		shipVel = shipVel - shipChange;

	if (input->isKeyDown(aie::INPUT_KEY_A))
		m_localTransform.setRotateZ(shipRotateSpeed * deltaTime);

	if (input->isKeyDown(aie::INPUT_KEY_D))
		m_localTransform.setRotateZ(-shipRotateSpeed * deltaTime);



	m_localTransform.translate(shipVel);
	updateGlobalTransform();

	SpriteObject::update(deltaTime);
}

void PlayerShip::draw(aie::Renderer2D * renderer)
{

	renderer->drawSpriteTransformed3x3(m_texture, (float*)m_globalTransform);
	SpriteObject::draw(renderer);
}
