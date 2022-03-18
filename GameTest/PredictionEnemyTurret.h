#pragma once
#include "EnemyController.h"
class PredictionEnemyTurret : public EnemyController
{
	DECLARE_DYNAMIC_DERIVED_CLASS(PredictionEnemyTurret, EnemyController)
public:

private:
	void Update(float _dt) override;
	void Cleanup() override;
	void Attack(float _dt) override;

	void LaunchProjectile(float _dt) const;

private:
	float projectileForce = 80.0f;
};

