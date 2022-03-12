#include "stdafx.h"
#include "TurretEnemyController.h"
#include "Vector3.h"
#include "Transform.h"
#include"ProjectileFactory.h"
#include "PhysicsPoint.h"
#include "GameObject.h"
#include "GameObjectManager.h"
IMPLEMENT_DYNAMIC_CLASS(TurretEnemyController)

void TurretEnemyController::Attack()
{
	// only attack if the player is within line of sight
	Vector3<float> turret_to_player = playerTransform->PeekPosition() - transform->PeekPosition();
	Vector3<float> turret_to_player_norm = turret_to_player.GetNormalized();
	if (turret_to_player_norm.Dot(transform->GetForward()) < 0.15f || turret_to_player.MagnitudeSq() > 8.0f * 8.0f)
		return;

	// fire enemy projectile
	LaunchProjectile();

	curr_att = att_cd(rng);
}

void TurretEnemyController::Update(float _dt)
{
	EnemyController::Update(_dt);
}

void TurretEnemyController::Cleanup()
{
}

void TurretEnemyController::LaunchProjectile() const
{
	GameObject* projectile = ProjectileFactory::Get().GetEnemyProjectile();

	projectile->GetTransform()->GetPosition() = transform->PeekPosition() + transform->GetForward() * 1.0f;
	PhysicsPoint* physics = static_cast<PhysicsPoint*>(projectile->FindComponentOfType(PhysicsPoint::getClassHashCode()));
	physics->GetForce() = (playerTransform->PeekPosition() - projectile->PeekTransform()->PeekPosition()).GetNormalized() * 80.0f;

	GameObjectManager::Get().AddGameObjectRunTime(projectile);
}
