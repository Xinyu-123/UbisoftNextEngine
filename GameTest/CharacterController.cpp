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

#include "ProjectileFactory.h"

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
}

void CharacterController::OnCollision(Collider* _other)
{
	mesh->SetColor(Color{ (unsigned char)0u, 0u, 255u });
}

void CharacterController::LaunchProjectile() const
{
	GameObject* projectile = ProjectileFactory::Get().GetPlayerProjectile();

	projectile->GetTransform()->GetPosition() = transform->PeekPosition() + transform->GetForward() * 1.0f;
	PhysicsPoint* physics = static_cast<PhysicsPoint*>(projectile->FindComponentOfType(PhysicsPoint::getClassHashCode()));
	physics->GetForce() = transform->GetForward() * 200.0f;

	GameObjectManager::Get().AddGameObjectRunTime(projectile);


}
