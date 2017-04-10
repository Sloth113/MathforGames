#include "MatrixGame.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <time.h>



MatrixGame::MatrixGame() {

}

MatrixGame::~MatrixGame() {

}

bool MatrixGame::startup() {
	srand(time(NULL));
	m_2dRenderer = new aie::Renderer2D();


	m_font = new aie::Font("./font/consolas.ttf", 32);


	m_shipTexture = new aie::Texture("./textures/ship.png");
	m_tankBodyTexture = new aie::Texture("./textures/tankRed.png");
	m_tankBrlTexture = new aie::Texture("./textures/barrelRed.png");

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	m_point = Vector2(getWindowWidth() / 2.0f, getWindowHeight() / 2.0f);
	m_pointSpd = 250;
	m_shapeAmount = 1000;
	m_shapes = new Vector2[m_shapeAmount];
	for (int i = 0; i < m_shapeAmount; i++) {
		m_shapes[i] = Vector2(rand() % getWindowWidth(), rand() % getWindowHeight());
	}
	m_point2 = Vector2(0, getWindowHeight());


	testVectors = new Vector2[2];
	testVectors[0] = Vector2(0.6f, 0.8f);
	testVectors[1] = Vector2(1.0f, 0.0f);

	m_betweenV = m_point;
	m_shapeSafe = 100;
	m_shapeScare = 20;
	m_shapeSpd = 100;

	//shipMat = Matrix3(getWindowWidth() / 2, 0, 0, 0, getWindowHeight() / 2, 0, 0,0,1);
	shipMat = Matrix3(1, 0, 0,	0, 1, 0, getWindowWidth()/2, getWindowHeight()/2, 1);
	
	shipMat.stdPrintMat();


	m_spriteRoot = new SceneObject();
	//m_spriteRoot->addChild(new SpriteObject(m_shipTexture));


	enemyTank = new EnemyTank(m_tankBodyTexture);
	SceneObject * tankBarrlePoint = new SceneObject();
	Matrix3 barrelMat = tankBarrlePoint->getLocal();
	barrelMat.setRotateZ(180);
	tankBarrlePoint->setLocal(barrelMat);
	enemyTank->addChild(tankBarrlePoint);
	SpriteObject * tankBarrel = new SpriteObject(m_tankBrlTexture);
	
	tankBarrel->setLocal(Matrix3(1, 0, 0, 0, 1, 0, 0, 24, 1));
	tankBarrlePoint->addChild(tankBarrel);


	
	//m_spriteRoot->addChild(new PlayerShip(m_shipTexture));
	m_spriteRoot->addChild(enemyTank);

	


	return true;
}

void MatrixGame::shutdown() {


	delete m_shipTexture;
	delete m_2dRenderer;
}

void MatrixGame::update(float deltaTime) {



	m_timer += deltaTime;
	// input example
	aie::Input* input = aie::Input::getInstance();

	Vector2 toMouse = Vector2(input->getMouseX()*1.0f, input->getMouseY()*1.0f) - m_point;

	if (toMouse.getMagSquar() > 9) {
		Vector2 pointMoveV = toMouse.getNormalise() * m_pointSpd * deltaTime;
		m_point.Translate(pointMoveV);
	}

	m_spriteRoot->update(deltaTime);

	//for (int i = 0; i < m_shapeAmount; i++) {
	//	//Shape logic
	//	m_betweenV = m_point - m_shapes[i];

	//	if (m_betweenV.getMagSquar() > m_shapeSafe*m_shapeSafe && !input->isKeyDown(aie::INPUT_KEY_SPACE)) {
	//		//Move towards
	//		//tmp move towards
	//		Vector2 distMoveV = m_betweenV.getNormalise() * m_shapeSpd * deltaTime;
	//		m_shapes[i].Translate(distMoveV);
	//	}
	//	else if (m_betweenV.getMagSquar() < m_shapeScare * m_shapeScare || input->isKeyDown(aie::INPUT_KEY_SPACE)) {
	//		//Move away
	//		if (input->isKeyDown(aie::INPUT_KEY_SPACE)) {
	//			Vector2 randDirectionMod = Vector2(rand() % 100 - 50, rand() % 100 - 50);
	//			m_betweenV -= randDirectionMod;
	//		}
	//		Vector2 runTowards = m_shapes[i] - m_point2;
	//		Vector2 distMoveV = runTowards.getNormalise() * m_shapeSpd *(rand() % 10)*   deltaTime;

	//		//(rand() % 10)
	//		m_shapes[i].Translate(distMoveV*-1.0f);
	//	}
	//}

	//Keyboard control
	// use arrow keys to move ship


	
	//shipMat.stdPrintMat();
	
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

void MatrixGame::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();


	/*
	// draw player
	m_2dRenderer->setRenderColour(0, 1, 1, 1);
	m_2dRenderer->drawCircle(m_point.getX(), m_point.getY(), 10, 5);



	// draw player
	m_2dRenderer->setRenderColour(0, 0, 1, 1);
	m_2dRenderer->drawCircle(m_point2.getX(), m_point2.getY(), 10, 5);

	// draw the shape thing thats watching
	m_2dRenderer->setRenderColour(1, 0, 0, 1);
	for (int i = 0; i < m_shapeAmount; i++) {
		m_2dRenderer->drawBox(m_shapes[i].getX(), m_shapes[i].getY(), 3, 3, 0);
	}
	*/
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	//m_2dRenderer->drawSpriteTransformed3x3(m_shipTexture, (float *)shipMat);
	m_spriteRoot->draw(m_2dRenderer);
	/*
	char text[32];
	sprintf_s(text, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, text, 0, 720 - 32);

	sprintf_s(text, 32, "A: %f", testVectors[0].angleBetween(testVectors[1]));
	m_2dRenderer->drawText(m_font, text, 0, 720 - 62);

	sprintf_s(text, 32, "Dot: %f", testVectors[0].dot(testVectors[1]));
	m_2dRenderer->drawText(m_font, text, 0, 720 - 98);

	*/

	// draw a thin line

	//m_2dRenderer->setRenderColour(1, 0, 1, 1);
	//m_2dRenderer->drawLine(m_point.getX(), m_point.getY(), m_shape.getX(), m_shape.getY() , 2, 1);


	// done drawing sprites
	m_2dRenderer->end();
}