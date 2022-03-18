#include "stdafx.h"
#include "PredictionEnemyTurret.h"
#include "Vector3.h"
#include "Transform.h"
#include "ProjectileFactory.h"
#include "PhysicsPoint.h"
#include "GameObject.h"
#include "GameObjectManager.h"

IMPLEMENT_DYNAMIC_CLASS(PredictionEnemyTurret)

void PredictionEnemyTurret::Attack(float _dt)
{
	// only attack if the player is within line of sight
	Vector3<float> turret_to_player = playerTransform->PeekPosition() - transform->PeekPosition();
	Vector3<float> turret_to_player_norm = turret_to_player.GetNormalized();
	if (turret_to_player_norm.Dot(transform->GetForward()) < 0.15f || turret_to_player.MagnitudeSq() > 15.0f * 15.0f)
		return;

	// fire enemy projectile
	LaunchProjectile(_dt);
}

void PredictionEnemyTurret::Update(float _dt)
{
	EnemyController::Update(_dt);

}

void PredictionEnemyTurret::Cleanup()
{
}

void PredictionEnemyTurret::LaunchProjectile(float _dt) const
{
	GameObject* projectile = ProjectileFactory::Get().GetEnemyProjectile();

	projectile->GetTransform()->GetPosition() = transform->PeekPosition() + transform->GetForward() * 1.0f;
	PhysicsPoint* physics = static_cast<PhysicsPoint*>(projectile->FindComponentOfType(PhysicsPoint::getClassHashCode()));

	// get the player's current velocity
	const Vector3<float>& playerVel = static_cast<PhysicsPoint*>(playerGO->FindComponentOfType(PhysicsPoint::getClassHashCode()))->PeekVelocity();

	// calculate the time it would take for the projectile to reach the player
	float dist = (playerTransform->PeekPosition() - projectile->PeekTransform()->PeekPosition()).Magnitude();
	float projectileMass = physics->GetMass();

	float speed = (projectileForce / projectileMass) * _dt;
	float time = dist / speed;

	Vector3<float> newPlayerPos = playerTransform->PeekPosition() + (playerVel*time);

	physics->GetForce() = (newPlayerPos - projectile->PeekTransform()->PeekPosition()).GetNormalized() * projectileForce;

	GameObjectManager::Get().AddGameObjectRunTime(projectile);
}
