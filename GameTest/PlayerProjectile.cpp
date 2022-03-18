#include "stdafx.h"
#include "PlayerProjectile.h"
#include "GameObjectManager.h"
#include "Collider.h"
#include "GameObject.h"
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
	if(_other->GetGameObject()->GetTag() == "Enemy" || _other->GetGameObject()->GetTag() == "Enemy Projectile")
		GameObjectManager::Get().RemoveGameObject(go);
}
