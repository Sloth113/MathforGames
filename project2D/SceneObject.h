#pragma once
#include <vector>
#include "Matrix3.h"
#include "Renderer2D.h"
class SceneObject {

	//2D game object
public:
	SceneObject();
	virtual ~SceneObject();;

	void addChild(SceneObject * child);

	virtual void update(float deltaTime);

	virtual void draw(aie::Renderer2D* renderer);


	void updateGlobalTransform();


	///////MAKE MOVE THINGS N STUFF 
	//CHANGE UP THE LOCAL THEN CALL UPDATE GLOBAL

protected:
	Matrix3 m_globalTransform;
	Matrix3 m_localTransform;

	SceneObject * m_parent;
	std::vector<SceneObject*> m_children;
};