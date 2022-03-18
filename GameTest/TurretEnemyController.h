#pragma once

#include "EnemyController.h"
class TurretEnemyController : public EnemyController
{
	DECLARE_DYNAMIC_DERIVED_CLASS(TurretEnemyController, EnemyController)
public:

private:
	void Attack(float _dt) override;
	void Update(float _dt) override;
	void Cleanup() override;

	void LaunchProjectile() const;

private:
	float projectileForce = 140.0f;
};

