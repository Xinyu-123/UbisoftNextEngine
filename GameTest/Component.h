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
private:
	virtual inline void Initialize() override { Object::Initialize(); }
	virtual void Update(float _dt) = 0;
	virtual void Cleanup() = 0;
protected:
	GameObject* gm = nullptr;
	bool CanAttachMultiple = false;


	friend class GameObject;

};

