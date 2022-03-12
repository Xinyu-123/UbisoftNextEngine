#pragma once

#include "ComponentScript.h"
#include "Vector3.h"
class Projectile : public ComponentScript
{
	DECLARE_ABSTRACT_DERIVED_CLASS(Projectile, ComponentScript)
public:

protected:
	virtual void Update(float _dt) override;
	virtual void Initialize() override;
protected:
	float destroyTime = 5.0f;
	std::mt19937 rng;
	std::uniform_real_distribution<float> rotRange;

	Vector3<float> rot_axis;
	const float rot_speed = 0.05f;
};

