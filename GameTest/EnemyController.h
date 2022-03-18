#pragma once

#include "ComponentScript.h"

class GameObject;
class Transform;

class EnemyController : public ComponentScript
{
	DECLARE_ABSTRACT_DERIVED_CLASS(EnemyController, ComponentScript)
public:
	float GetHealth() const { return health; }
	void SetHealth(float _health) { health = _health; }

	int GetPoints() const { return points; }
	void SetPoints(int _points) { points = _points; }
protected:
	virtual void Update(float _dt) override;
	virtual void Attack(float _dt) = 0;
	virtual void Initialize() override;


	virtual void OnCollision(Collider* _other) override;

	virtual void TakeDamage(float _damage);
	virtual void Die();
protected:
	float curr_att = 0.0f;

	std::uniform_real_distribution<float> att_cd;
	std::mt19937 rng;
	GameObject* playerGO;
	const Transform* playerTransform;


private:
	float health = 0.0f;
	int points = 0;
};

