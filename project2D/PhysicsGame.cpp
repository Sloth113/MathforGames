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

	//Collision box checks
	collider = AxisABBox();

	collider2 = AxisABBox();

	ballCol = RoundThings();

	ray = Rays();




	//Parachute stuuff
	falling = false;
	chute = false;
	click = false;
	state = 0;
	sped = 0;
	playerVel = Vector3(0, 0, 1);

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


	//Collider stuff
	if (!click  && input->isMouseButtonDown(0)) {
		click = true;
		collider.expand(input->getMouseX()+ m_cameraX, input->getMouseY()+ m_cameraY);
	}else	if (!click  && input->isMouseButtonDown(1)) {
		click = true;
		if (ray.origin.x == 0)
			ray.origin = Vector3(input->getMouseX() + m_cameraX, input->getMouseY() + m_cameraY, 0);
		else
			ray.direction = Vector3(input->getMouseX() + m_cameraX, input->getMouseY() + m_cameraY, 0) - ray.origin;
		//ballCol.expand(input->getMouseX()+ m_cameraX, input->getMouseY()+m_cameraY);
	}
	else {
		click = false;
	}
	closePos = ray.closestPoint(Vector3(input->getMouseX() + m_cameraX, input->getMouseY() + m_cameraY, 0));
	//std::cout << ray.distFrom(Vector3(input->getMouseX() + m_cameraX, input->getMouseY() + m_cameraY, 0)) << "\n";


	

	//Player control
	if (input->isKeyDown(aie::INPUT_KEY_D)) {
		Matrix3 newPos = m_person->getLocal();
		newPos.translate(Vector3(30*deltaTime,0,1));
		m_person->setLocal(newPos);
	}

	if (input->isKeyDown(aie::INPUT_KEY_SPACE) && falling && !chute) {
		m_person->addChild(m_chute);
		m_chute->setLocal(Matrix3(Vector3(1, 0, 0), Vector3(0, 1, 0), Vector3(0, 3, 1)));
		chute = true;
		//Make timer
	}

	if (m_person->getLocal().matrix[0][2] > 90) {
		falling = true;
	}
	if (m_person->getLocal().matrix[1][2] <= 0) {
		falling = false;
		chute = false;
		if(sped ==0)
		sped = playerVel.y;
		if (playerVel.y < -20/2) {
			//dead
			state = 3;
			
		}
		else if (playerVel.y > -10/ 2) {
			//Safe
			state = 1;
		}
		else {
			//Hurt
			state = 2;
		}

		playerVel = Vector3(0, 0, 0);

	}
	if (falling) {
		playerVel += Vector3(0, -9.8 * deltaTime*deltaTime /2, 0);
	}
	if (chute && playerVel.y < -7/2) {
		playerVel -= Vector3(0, -30 * deltaTime*deltaTime /2, 0);
	}else if(chute && playerVel.y <= -7/2){
		playerVel = Vector3(0, -7.0 /2 , 0);
	}else if(chute){
		playerVel += Vector3(0, -7.0 * deltaTime * deltaTime / 2, 0);
	}
	

	Matrix3 newPos = m_person->getLocal();
	newPos.translate(playerVel);
	m_person->setLocal(newPos);
	 

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


	
	if (ballCol.collides2D(collider)) {
		m_2dRenderer->setRenderColour(1, 0, 0, 1);
	}
	else {
		m_2dRenderer->setRenderColour(0, 0, 1, 1);
	}



	m_2dRenderer->drawLine(collider.xMin, collider.yMin, collider.xMin, collider.yMax, 1.0f, 0.0f);//left side
	m_2dRenderer->drawLine(collider.xMin, collider.yMin, collider.xMax, collider.yMin, 1.0f, 0.0f);//Bottom
	m_2dRenderer->drawLine(collider.xMin, collider.yMax, collider.xMax, collider.yMax, 1.0f, 0.0f);//top
	m_2dRenderer->drawLine(collider.xMax, collider.yMin, collider.xMax, collider.yMax, 1.0f, 0.0f);//right
	

	//Line
	m_2dRenderer->drawLine(ray.origin.x, ray.origin.y, ray.direction.x+ray.origin.x, ray.direction.y+ray.origin.y, 1.0f, 0.0f);

	//closest point to input
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawCircle(closePos.x, closePos.y, 3, 0);
	//Ball 
	//m_2dRenderer->drawCircle(ballCol.x, ballCol.y, ballCol.radi, 0);
	/* //box
	m_2dRenderer->drawLine(collider2.xMin, collider2.yMin, collider2.xMin, collider2.yMax, 1.0f, 0.0f);//left side
	m_2dRenderer->drawLine(collider2.xMin, collider2.yMin, collider2.xMax, collider2.yMin, 1.0f, 0.0f);//Bottom
	m_2dRenderer->drawLine(collider2.xMin, collider2.yMax, collider2.xMax, collider2.yMax, 1.0f, 0.0f);//top
	m_2dRenderer->drawLine(collider2.xMax, collider2.yMin, collider2.xMax, collider2.yMax, 1.0f, 0.0f);//right
	*/
	char * text = new char[32];
	/*
	sprintf_s(text, 32, "Falling: %i", state);
	m_2dRenderer->drawText(m_font, text, 0, 720 - 32);

	sprintf_s(text, 32, "Speed: %f", sped);
	m_2dRenderer->drawText(m_font, text, 0, 720 - 64);
		*/



	// done drawing sprites
	m_2dRenderer->end();
}