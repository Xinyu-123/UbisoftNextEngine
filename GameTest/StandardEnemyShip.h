#pragma once
#include "EnemyController.h"

class PhysicsPoint;

class StandardEnemyShip : public EnemyController
{
	DECLARE_DYNAMIC_DERIVED_CLASS(StandardEnemyShip, EnemyController)

public:

private:
	void Attack(float _dt) override;
	void Update(float _dt) override;
	void Cleanup() override;
	void Initialize() override;

	void Move(float _dt);

private:
	float moveCD = 2.0f;
	float curMoveCD = 0.0f;

	float moveForce = 200.0f;

	PhysicsPoint* physics;
};

