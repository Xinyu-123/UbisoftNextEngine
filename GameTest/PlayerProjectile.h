#pragma once

#include "Projectile.h"
class PlayerProjectile : public Projectile
{
	DECLARE_DYNAMIC_DERIVED_CLASS(PlayerProjectile, Projectile)

public:

private:
	void Update(float _dt) override;
	void Cleanup() override;

	void OnCollision(Collider* _other) override;
};

