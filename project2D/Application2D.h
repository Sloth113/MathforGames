#pragma once
#include "Vector2.h"
#include "Vector3.h"
#include "Matrix2.h"
#include "Matrix3.h"
#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font * m_font;


	float m_cameraX, m_cameraY;
	float m_timer;
	

	Vector2 m_point2;

	Vector2 m_point;
	float m_pointSpd;
	bool m_pointKeys;

	Vector2 * m_shapes;
	int m_shapeAmount;
	float m_shapeSpd;
	int m_shapeSafe;
	int m_shapeScare;

	Vector2 * testVectors;

	Vector2 m_betweenV;

	Matrix3 matTest;



};