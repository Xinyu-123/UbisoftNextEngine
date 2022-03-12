#pragma once
#include "Projectile.h"


class EnemyProjectile : public Projectile
{
	DECLARE_DYNAMIC_DERIVED_CLASS(EnemyProjectile, Projectile)

public:

private:
	void Update(float _dt) override;
	void Cleanup() override;

	void OnCollision(Collider* _other) override;
};

