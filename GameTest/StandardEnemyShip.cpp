#include "stdafx.h"
#include "StandardEnemyShip.h"
#include "Transform.h"
#include "GameObject.h"
#include "PhysicsPoint.h"
#include "Algo.h"

#include "ProjectileFactory.h"
#include "GameObjectManager.h"
IMPLEMENT_DYNAMIC_CLASS(StandardEnemyShip)


void StandardEnemyShip::Attack(float _dt)
{
	GameObject* projectile = ProjectileFactory::Get().GetEnemyProjectile();

	projectile->GetTransform()->GetPosition() = transform->PeekPosition() + transform->GetForward() * 1.0f;
	PhysicsPoint* physics = static_cast<PhysicsPoint*>(projectile->FindComponentOfType(PhysicsPoint::getClassHashCode()));
	physics->GetForce() = transform->GetForward() * 200.0f;

	GameObjectManager::Get().AddGameObjectRunTime(projectile);

	
}

void StandardEnemyShip::Update(float _dt)
{
	Vector3<float> turret_to_player = playerTransform->PeekPosition() - transform->PeekPosition();

	EnemyController::Update(_dt);

	Move(_dt);
}

void StandardEnemyShip::Cleanup()
{
}

void StandardEnemyShip::Initialize()
{
	EnemyController::Initialize();

	physics = GETCOMPONENT(PhysicsPoint);
}

void StandardEnemyShip::Move(float _dt)
{
	// Look towards player and apply a small force towards them on an interval
	transform->GetRotation() = Algo::Slerp(transform->GetRotation(), Quaternion<float>::LookAt(transform->PeekPosition(), playerTransform->PeekPosition(), { 0, 0, 1 }, { 0, 1, 0 }), 1.3f * _dt);
	
	
	curMoveCD = std::max(curMoveCD - _dt, 0.0f);

	if (curMoveCD <= 0.0f)
	{
		physics->GetForce() = transform->GetForward() * moveForce;
		curMoveCD = moveCD;
	}
}
