#include "stdafx.h"
#include "CameraController.h"
#include "GameObject.h"
#include "Camera.h"
#include "Transform.h"
#include "App/app.h"
#include "Ray.h"
#include "CollisionSystem.h"
#include "PlayerProjectileFactory.h"

IMPLEMENT_DYNAMIC_CLASS(CameraController)

void CameraController::Update(float _dt)
{
	if (App::IsKeyPressed('W'))
	{
		Vector3<float> forward = transform->GetForward();
		forward.y = 0;
		forward.Normalize();
		transform->GetPosition() += forward * moveSpeed * _dt;
	}
	if (App::IsKeyPressed('A'))
	{
		transform->GetPosition() += transform->GetRight() * -moveSpeed * _dt;
	}
	if (App::IsKeyPressed('S'))
	{
		Vector3<float> forward = transform->GetForward();
		forward.y = 0;
		forward.Normalize();
		transform->GetPosition() += forward * -moveSpeed * _dt;
	}
	if (App::IsKeyPressed('D'))
	{
		transform->GetPosition() += transform->GetRight() * moveSpeed * _dt;
	}

	/*if (App::IsKeyPressed(VK_DOWN))
	{
		auto& rotation = transform->GetRotation();
		rotation *= Quaternion<float>::RotationQuaternion(-1.0f * _dt, transform->GetRight());
	}
	if (App::IsKeyPressed(VK_UP))
	{
		auto& rotation = transform->GetRotation();
		rotation *= Quaternion<float>::RotationQuaternion(1.0f * _dt, transform->GetRight());
	}
	
	if (App::IsKeyPressed(VK_LEFT))
	{
		auto& rotation = transform->GetRotation();
		rotation *= Quaternion<float>::RotationQuaternion(-1.0f * _dt, { 0, 1, 0 });
	}
	if (App::IsKeyPressed(VK_RIGHT))
	{
		auto& rotation = transform->GetRotation();
		rotation *= Quaternion<float>::RotationQuaternion(1.0f * _dt, { 0, 1, 0 });
	}*/

	velocity = std::max(velocity - 0.1f * _dt, -0.1f);
	isGrounded = false;
	transform->GetPosition().y += velocity;
	if (transform->GetPosition().y < 0.0f)
	{
		isGrounded = true;
		transform->GetPosition().y = 0;
	}


	if (App::IsKeyPressed(VK_SPACE) && isGrounded == true)
	{
		velocity = 0.1f;
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

		rotation *= Quaternion<float>::RotationQuaternion(0.2f * yDelta * _dt, transform->GetRight());
		rotation *= Quaternion<float>::RotationQuaternion(-0.2f * xDelta * _dt, { 0, 1, 0 });
		Vector3<float> right = transform->GetRight();

	}


}

void CameraController::Initialize()
{
	ComponentScript::Initialize();

	camera = GETCOMPONENT(Camera);
	transform = GETCOMPONENT(Transform);

	App::GetMousePos(lastMouseX, lastMouseY);
}

void CameraController::Cleanup()
{
}