#pragma once

#include "Projectile.h"
class PlayerProjectile : public Projectile
{
	DECLARE_DYNAMIC_DERIVED_CLASS(PlayerProjectile, Projectile)

public:
	float GetDamage() const { return damage; }
	void SetDamage(float _damage) { damage = _damage; }
private:
	void Update(float _dt) override;
	void Cleanup() override;

	void OnCollision(Collider* _other) override;

	float damage = 0.0f;
};

