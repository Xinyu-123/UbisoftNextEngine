#include "stdafx.h"
#include "PlayerProjectile.h"
#include "GameObjectManager.h"

IMPLEMENT_DYNAMIC_CLASS(PlayerProjectile)

void PlayerProjectile::Update(float _dt)
{
	Projectile::Update(_dt);
}

void PlayerProjectile::Cleanup()
{
}

void PlayerProjectile::OnCollision(Collider* _other)
{
	GameObjectManager::Get().RemoveGameObject(go);
}
