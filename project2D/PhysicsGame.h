#pragma once
#include "Vector2.h"
#include "Vector3.h"
#include "Matrix2.h"
#include "Matrix3.h"
#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include "SpriteObject.h"
#include "AxisABBox.h"
#include "RoundThings.h"

class PhysicsGame : public aie::Application {
public:

	PhysicsGame();
	virtual ~PhysicsGame();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font * m_font;



	aie::Texture*		m_buildingT;
	aie::Texture*		m_personT;
	aie::Texture*		m_chuteT;
	aie::Texture*		m_bloodT;


	

	float m_cameraX, m_cameraY;
	float m_timer;


	

	//Scene heirarchie stuff
	SceneObject* m_spriteRoot;

	SpriteObject* m_person;
	SpriteObject* m_chute;
	SpriteObject* m_fail;




	//Physics checks 
	AxisABBox collider;

	AxisABBox collider2;

	RoundThings ballCol;

	bool click;



};