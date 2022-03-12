#pragma once

#include "EnemyController.h"
class TurretEnemyController : public EnemyController
{
	DECLARE_DYNAMIC_DERIVED_CLASS(TurretEnemyController, EnemyController)
public:

private:
	void Attack() override;
	void Update(float _dt) override;
	void Cleanup() override;

	void LaunchProjectile() const;
};

