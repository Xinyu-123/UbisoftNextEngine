#include "stdafx.h"
#include "EnemyProjectile.h"
#include "GameObjectManager.h"
#include "GameObject.h"
#include "Collider.h"

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
	if(_other->GetGameObject()->GetName() == "Player" || _other->GetGameObject()->GetTag() == "Player Projectile")
		GameObjectManager::Get().RemoveGameObject(go);
}
