#include "stdafx.h"
#include "CharacterController.h"
#include "App/app.h"
#include "Gameobject.h"
#include "Transform.h"
#include "GameObjectManager.h"
#include "Mesh.h"
#include "Algo.h"
#include "PhysicsPoint.h"
#include "Ray.h"
#include "CollisionSystem.h"
#include "GameManager.h"

#include "ProjectileFactory.h"
#include "UIFactory.h"

IMPLEMENT_DYNAMIC_CLASS(CharacterController)

void CharacterController::Update(float _dt)
{
	if (App::IsKeyPressed('W'))
	{
		physicsPoint->GetForce() += transform->GetForward() * moveForce * _dt;
	}
	if (App::IsKeyPressed('A'))
	{
		physicsPoint->GetForce() -= transform->GetRight() * moveForce * _dt;
	}
	if (App::IsKeyPressed('S'))
	{
		physicsPoint->GetForce() -= transform->GetForward() * moveForce * _dt;
	}
	if (App::IsKeyPressed('D'))
	{
		physicsPoint->GetForce() += transform->GetRight() * moveForce * _dt;
	}
	if (App::IsKeyPressed(VK_SPACE))
	{
		physicsPoint->GetForce() += transform->GetUp() * moveForce* _dt;
	}
	if (App::IsKeyPressed('C'))
	{
		physicsPoint->GetForce() -= transform->GetUp() * moveForce* _dt;
	}

	float mouseX;
	float mouseY;
	App::GetMousePos(mouseX, mouseY);

	float xDelta = lastMouseX - mouseX;
	float yDelta = lastMouseY - mouseY;
	lastMouseX = mouseX;
	lastMouseY = mouseY;

	if (App::IsKeyPressed(VK_LBUTTON))
	{
		auto& rotation = transform->GetRotation();
		rotation *= Quaternion<float>::RotationQuaternion(-0.2f * xDelta * _dt, { 0, 1, 0 });

		xRot += 0.2f * yDelta * _dt;
		if (xRot >= PI / 2 || xRot <= -PI / 2)
		{
			xRot -= 0.2f * yDelta * _dt;
		}
		else
		{
			rotation *= Quaternion<float>::RotationQuaternion(0.2f * yDelta * _dt, transform->GetRight());
		}

	}

	currFireCD = std::max(currFireCD - _dt, 0.0f);

	// fire a bullet
	if (App::IsKeyPressed(VK_RBUTTON) && currFireCD <= 0.0f)
	{
		LaunchProjectile();
		currFireCD = fireCD;
	}
}

void CharacterController::Cleanup()
{
}

void CharacterController::Initialize()
{
	ComponentScript::Initialize();

	mesh = GETCOMPONENT(Mesh);
	transform = GETCOMPONENT(Transform);
	physicsPoint = GETCOMPONENT(PhysicsPoint);

	App::GetMousePos(lastMouseX, lastMouseY);

	// setup the ui with lives
	for (int i = 0; i < GameManager::Get().lives; ++i)
	{
		lifeSprites.push_back(UIFactory::Get().GetPlayerLifeSprite());
		lifeSprites[i]->GetTransform()->GetPosition().x += 50 + 50 * i;
		lifeSprites[i]->GetTransform()->GetPosition().y += APP_VIRTUAL_HEIGHT - 50;
		GameObjectManager::Get().AddGameObjectRunTime(lifeSprites[i]);
	}


}

void CharacterController::OnCollision(Collider* _other)
{
	if (_other->GetGameObject()->GetTag() == "Enemy Projectile" || _other->GetGameObject()->GetTag() == "Enemy")
	{
		TakeDamage(0.0f);
	}
}

void CharacterController::LaunchProjectile() const
{
	GameObject* projectile = ProjectileFactory::Get().GetPlayerProjectile();

	projectile->GetTransform()->GetPosition() = transform->PeekPosition() + transform->GetForward() * 1.0f;
	PhysicsPoint* physics = static_cast<PhysicsPoint*>(projectile->FindComponentOfType(PhysicsPoint::getClassHashCode()));
	physics->GetForce() = transform->GetForward() * 200.0f;

	GameObjectManager::Get().AddGameObjectRunTime(projectile);


}

void CharacterController::TakeDamage(float _damage)
{
	GameManager::Get().lives--;
	// Update UI
	GameObjectManager::Get().RemoveGameObject(lifeSprites[GameManager::Get().lives]);
	lifeSprites.erase(lifeSprites.end()-1);

	if (GameManager::Get().lives <= 0)
		Die();
}

void CharacterController::Die()
{
	// setup the gameover ui
	GameObjectManager::Get().AddGameObjectRunTime(UIFactory::Get().GetGameOverText());

	GameObjectManager::Get().RemoveComponent(GETCOMPONENT(Collider));
	GameObjectManager::Get().RemoveComponent(this);

}
