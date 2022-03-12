#pragma once
#include "Collider.h"


class SphereCollider : public Collider
{
	DECLARE_DYNAMIC_DERIVED_CLASS(SphereCollider, Collider)

public:
	SphereCollider();

	void SetRadius(float _radius);
	float PeekRadius() const { return radius; }

private:
	void Update(float _dt) override;
	void Initialize() override;
	void Cleanup() override;
	void CalculateAABB() override;

private:
	float radius;

	friend class CollisionSystem;
};

