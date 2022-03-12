#include "stdafx.h"
#include "EnemyController.h"
#include "GameManager.h"
#include "GameObject.h"
#include "GameObjectManager.h"
#include "Collider.h"
IMPLEMENT_ABSTRACT_CLASS(EnemyController)

void EnemyController::Update(float _dt)
{
	curr_att = std::max(curr_att - _dt, 0.0f);

	if (curr_att <= 0.0f)
		Attack();
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
		GameObjectManager::Get().RemoveGameObject(go);
	}
}
