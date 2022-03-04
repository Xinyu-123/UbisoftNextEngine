#pragma once
#include "Component.h"
#include "Collider.h"

class ComponentScript : public Component
{
	DECLARE_ABSTRACT_DERIVED_CLASS(ComponentScript, Component)
public:
	ComponentScript();

	// maybe some collision functions

protected:
	virtual void Initialize() override;
	void virtual OnCollision(Collider* _other) {}

private:
	virtual void Update(float _dt) = 0;
	virtual void Cleanup() = 0;

	friend class CollisionSystem;
};

