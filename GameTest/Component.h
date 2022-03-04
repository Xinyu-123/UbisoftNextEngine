#pragma once
#include "Object.h"

class GameObject;

class Component : public Object
{
	DECLARE_ABSTRACT_DERIVED_CLASS(Component, Object);

public:

protected:
	Component();
	virtual ~Component();

	Component(const Component& other) = delete;
	Component& operator=(const Component& other) = delete;

protected:
	virtual void Initialize() override { Object::Initialize(); }

private:
	virtual void Update(float _dt) = 0;
	virtual void Cleanup() = 0;

protected:
	GameObject* go = nullptr;
	bool CanAttachMultiple = false;
	bool renderable = false;
	bool collider = false;

	friend class GameObject;
	friend class CollisionSystem;
};

