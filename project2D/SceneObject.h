#pragma once
#include <vector>
#include "Matrix3.h"
#include "Renderer2D.h"
#include "Input.h"
class SceneObject {

	//2D game object, static sprite
public:
	SceneObject();
	virtual ~SceneObject();

	void addChild(SceneObject * child);
	void removeChild(int i);
	void removeChild(SceneObject * child);
	void removeChildren();


	virtual void update(float deltaTime);

	virtual void draw(aie::Renderer2D* renderer);


	void updateGlobalTransform();

	void setLocal(Matrix3);

	Matrix3 getLocal();

	///////MAKE MOVE THINGS N STUFF 
	//CHANGE UP THE LOCAL THEN CALL UPDATE GLOBAL

protected:
	Matrix3 m_globalTransform;
	Matrix3 m_localTransform;

	SceneObject * m_parent;
	std::vector<SceneObject*> m_children;
};