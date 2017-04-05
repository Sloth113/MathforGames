#pragma once
#include <vector>
#include "Matrix3.h"
#include "Renderer2D.h"
class SceneObject {

	//2D game object
public:
	SceneObject();
	virtual ~SceneObject() {
		for (SceneObject* child : m_children) {
			delete child;
		}
	};

	void addChild(SceneObject * child) {
		if (child->m_parent == nullptr) {
			child->m_parent = this;
			m_children.push_back(child);
		}

	}

	virtual void update(float deltaTime) {
		for (SceneObject* child : m_children) {
			child->update(deltaTime);
		}
	}

	virtual void draw(aie::Renderer2D* renderer) {
		for (SceneObject* child : m_children) {
			child->draw(renderer);
		}
	}


protected:
	Matrix3 m_globalTransform;
	Matrix3 m_localTransform;

	SceneObject * m_parent;
	std::vector<SceneObject*> m_children;
};