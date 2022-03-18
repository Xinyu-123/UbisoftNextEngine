#include "stdafx.h"
#include "EnemyController.h"
#include "GameManager.h"
#include "GameObject.h"
#include "GameObjectManager.h"
#include "Collider.h"
#include "PlayerProjectile.h"
IMPLEMENT_ABSTRACT_CLASS(EnemyController)

void EnemyController::Update(float _dt)
{
	curr_att = std::max(curr_att - _dt, 0.0f);

	if (curr_att <= 0.0f)
	{
		Attack(_dt);
		curr_att = att_cd(rng);
	}
}

void EnemyController::Initialize()
{
	ComponentScript::Initialize();

	playerGO = GameManager::Get().GetPlayer();
	playerTransform = playerGO->PeekTransform();

	att_cd = std::uniform_real_distribution<float>(0.7f, 2.0f);
	rng = std::mt19937(std::random_device()());
}

void EnemyController::OnCollision(Collider* _other)
{
	if (_other->GetGameObject()->GetTag() == "Player Projectile")
	{
		PlayerProjectile* projectile = static_cast<PlayerProjectile*>(_other->GetGameObject()->FindComponentOfType(PlayerProjectile::getClassHashCode()));
		TakeDamage(projectile->GetDamage());
	}
}

void EnemyController::TakeDamage(float _damage)
{
	health -= _damage;

	if (health <= 0.0f)
		Die();
}

void EnemyController::Die()
{
	GameObjectManager::Get().RemoveGameObject(go);

	GameManager::Get().IncreaseScore(points);
}
