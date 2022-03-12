#pragma once
#include "Component.h"
#include "Vector3.h"

class Transform;
class PhysicsPoint : public Component
{
	DECLARE_DYNAMIC_DERIVED_CLASS(PhysicsPoint, Component)

public:
	PhysicsPoint();

	Vector3<float>& GetVelocity() { return velocity; }
	const Vector3<float>& PeekVelocity() const { return velocity; }

	Vector3<float>& GetForce() { return force; }
	const Vector3<float>& PeekForce() const { return force; }

	float GetMass() const { return mass; }
	void SetMass(float _mass)
	{
		mass = _mass;
		massInverse = 1 / mass;
	}

	void SetGravity(bool _gravity) { gravity = _gravity; }

private:
	void Initialize() override;
	void Update(float _dt) override;
	void Cleanup() override;

private:
	Vector3<float>* position = nullptr;
	Vector3<float> velocity = { 0.0f, 0.0f, 0.0f };
	Vector3<float> force = {0.0f, 0.0f, 0.0f};
	float mass = 1.0f;
	float massInverse = 0.1f;

	bool gravity = false;
};

