#include "SceneObject.h"

SceneObject::SceneObject()
{
	m_parent = nullptr;
}

SceneObject::~SceneObject()
{
	for (SceneObject* child : m_children) {
		delete child;
	}
}

void SceneObject::addChild(SceneObject * child)
{
	if (child->m_parent == nullptr) {
		child->m_parent = this;
		m_children.push_back(child);
	}
}

void SceneObject::update(float deltaTime)
{
	for (SceneObject* child : m_children) {
		child->update(deltaTime);
	}
}

void SceneObject::draw(aie::Renderer2D * renderer)
{
	for (SceneObject* child : m_children) {
		child->draw(renderer);
	}
}

void SceneObject::updateGlobalTransform()
{
	if (m_parent != nullptr) {
		m_globalTransform = m_parent->m_globalTransform * m_localTransform;
	}
	else {
		m_globalTransform = m_localTransform;
	}
	for (SceneObject* child : m_children) {
		child->updateGlobalTransform();
	}
}