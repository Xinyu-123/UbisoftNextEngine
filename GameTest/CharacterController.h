#pragma once
#include "ComponentScript.h"
#include "PhysicsPoint.h"

class Transform;
class Mesh;
class CharacterController final : public ComponentScript
{
	DECLARE_DYNAMIC_DERIVED_CLASS(CharacterController, ComponentScript)
public:

private:
	void Update(float _dt) override;
	void Cleanup() override;
	void Initialize() override;
	void OnCollision(Collider* _other) override;

	void LaunchProjectile() const;
	void TakeDamage(float _damage);
	void Die();
private:
	Transform* transform;
	Mesh* mesh;
	PhysicsPoint* physicsPoint;
	float lastMouseX = 0;
	float lastMouseY = 0;

	float moveForce = 500.0f;

	float xRot = 0.0f;

	const float fireCD = 0.3f;
	float currFireCD = 0.0f;

	int lives = 3;

	std::vector<GameObject*> lifeSprites;
};

