#include "stdafx.h"
#include "ConstantRotation.h"
#include "Quaternion.h"
#include "Transform.h"
#include "GameObject.h"
#include "Mesh.h"

#include "GameObjectManager.h"
#include "App/app.h"
#include "Collider.h"
IMPLEMENT_DYNAMIC_CLASS(ConstantRotation)

void ConstantRotation::Update(float _dt)
{
	mesh->SetColor({ 1.0f, 0.0f, 0.3f });
	auto& rotation = go->GetTransform()->GetRotation();


	rotation *= Quaternion<float>::RotationQuaternion(0.3f * _dt, { 0, 1, 0 });
	rotation *= Quaternion<float>::RotationQuaternion(0.5f * _dt, { 0, 0, 1 });
	rotation *= Quaternion<float>::RotationQuaternion(-1.1f * _dt, { 1, 0, 1 });


}

void ConstantRotation::Cleanup()
{
}

void ConstantRotation::Initialize()
{
	ComponentScript::Initialize();
	mesh = static_cast<Mesh*>(go->FindComponentOfType(Mesh::getClassHashCode()));
}

void ConstantRotation::OnCollision(Collider* _other)
{
	mesh->SetColor({ 1.0f, 0.0f, 1.0f });

	if (_other->GetGameObject()->GetTag() == "Player Projectile")
	{
		GameObjectManager::Get().RemoveGameObject(go);
	}
}
