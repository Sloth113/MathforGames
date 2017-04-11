#include "PhysicsGame.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <time.h>


//ALSO COLLISIONS
PhysicsGame::PhysicsGame() {

}

PhysicsGame::~PhysicsGame() {

}

bool PhysicsGame::startup() {
	srand(time(NULL));
	m_2dRenderer = new aie::Renderer2D();


	m_font = new aie::Font("./font/consolas.ttf", 32);


	m_buildingT = new aie::Texture("./textures/building1.png");
	m_personT = new aie::Texture("./textures/person1.png");
	m_chuteT = new aie::Texture("./textures/chute.png");
	m_bloodT = new aie::Texture("./textures/bloodsplat.png");


	m_person = new SpriteObject(m_personT);
	m_chute = new SpriteObject(m_chuteT);
	m_fail = new SpriteObject(m_bloodT);

	


	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	
	

	m_spriteRoot = new SceneObject();
	
	SpriteObject * building = new SpriteObject(m_buildingT, Vector3(87/2,600/2,0));
	m_spriteRoot->addChild(building);

	m_spriteRoot->addChild(m_person);
	
	//
	


	m_person->setLocal(Matrix3(Vector3(1, 0, 0), Vector3(0, 1, 0), Vector3(50, 602, 1)));


	collider = AxisABBox();

	collider2 = AxisABBox();

	ballCol = RoundThings();

	click = false;

	return true;
}

void PhysicsGame::shutdown() {


	delete m_2dRenderer;
}

void PhysicsGame::update(float deltaTime) {



	m_timer += deltaTime;
	// input example
	aie::Input* input = aie::Input::getInstance();


	m_spriteRoot->update(deltaTime);



	if (!click  && input->isMouseButtonDown(0)) {
		click = true;
		collider.expand(input->getMouseX(), input->getMouseY());
	}else	if (!click  && input->isMouseButtonDown(1)) {
		click = true;
		ballCol.expand(input->getMouseX(), input->getMouseY());
	}
	else {
		click = false;
	}

	if (input->isKeyDown(aie::INPUT_KEY_SPACE)) {
		collider.expand(collider2);
		collider2 = AxisABBox();
	}


	 

	//Keyboard control
	// use arrow keys to move camera
	if (input->isKeyDown(aie::INPUT_KEY_UP))
		m_cameraY += 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		m_cameraY -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		m_cameraX -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		m_cameraX += 500.0f * deltaTime;






	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void PhysicsGame::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	m_2dRenderer->begin();


	m_2dRenderer->setRenderColour(1, 1, 1, 1);

	//m_2dRenderer->drawSprite(m_buildingT, 0, 0, 100, 100, 0, 0, 0, 0);
	m_spriteRoot->draw(m_2dRenderer);


	
/*	if (collider.collides(ballCol)) {
		m_2dRenderer->setRenderColour(1, 0, 0, 1);
	}
	else {
		m_2dRenderer->setRenderColour(0, 0, 1, 1);
	}
	*/


	m_2dRenderer->drawLine(collider.xMin, collider.yMin, collider.xMin, collider.yMax, 1.0f, 0.0f);//left side
	m_2dRenderer->drawLine(collider.xMin, collider.yMin, collider.xMax, collider.yMin, 1.0f, 0.0f);//Bottom
	m_2dRenderer->drawLine(collider.xMin, collider.yMax, collider.xMax, collider.yMax, 1.0f, 0.0f);//top
	m_2dRenderer->drawLine(collider.xMax, collider.yMin, collider.xMax, collider.yMax, 1.0f, 0.0f);//right

	m_2dRenderer->drawCircle(ballCol.x, ballCol.y, ballCol.radi, 0);
	/*
	m_2dRenderer->drawLine(collider2.xMin, collider2.yMin, collider2.xMin, collider2.yMax, 1.0f, 0.0f);//left side
	m_2dRenderer->drawLine(collider2.xMin, collider2.yMin, collider2.xMax, collider2.yMin, 1.0f, 0.0f);//Bottom
	m_2dRenderer->drawLine(collider2.xMin, collider2.yMax, collider2.xMax, collider2.yMax, 1.0f, 0.0f);//top
	m_2dRenderer->drawLine(collider2.xMax, collider2.yMin, collider2.xMax, collider2.yMax, 1.0f, 0.0f);//right
	*/


																				   
	// done drawing sprites
	m_2dRenderer->end();
}