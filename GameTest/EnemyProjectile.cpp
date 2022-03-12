#include "stdafx.h"
#include "EnemyProjectile.h"
#include "GameObjectManager.h"

IMPLEMENT_DYNAMIC_CLASS(EnemyProjectile)

void EnemyProjectile::Update(float _dt)
{
	Projectile::Update(_dt);
}

void EnemyProjectile::Cleanup()
{
}

void EnemyProjectile::OnCollision(Collider* _other)
{
	GameObjectManager::Get().RemoveGameObject(go);
}
