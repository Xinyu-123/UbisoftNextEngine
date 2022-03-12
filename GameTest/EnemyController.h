#pragma once

#include "ComponentScript.h"

class GameObject;
class Transform;

class EnemyController : public ComponentScript
{
	DECLARE_ABSTRACT_DERIVED_CLASS(EnemyController, ComponentScript)
public:
	
protected:
	virtual void Update(float _dt) override;
	virtual void Attack() = 0;
	virtual void Initialize() override;


	virtual void OnCollision(Collider* _other) override;
protected:
	float curr_att = 0.0f;

	std::uniform_real_distribution<float> att_cd;
	std::mt19937 rng;
	GameObject* playerGO;
	const Transform* playerTransform;
};

