#include "stdafx.h"
#include "Projectile.h"
#include "GameObjectManager.h"
#include "Transform.h"
IMPLEMENT_ABSTRACT_CLASS(Projectile)


void Projectile::Update(float _dt)
{
	destroyTime -= _dt;
	if (destroyTime <= 0.0f)
		GameObjectManager::Get().RemoveGameObject(go);

	transform->GetRotation() *= Quaternion<float>::RotationQuaternion(rot_speed, rot_axis);
}

void Projectile::Initialize()
{
	ComponentScript::Initialize();
	rng = std::mt19937(std::random_device()());
	rotRange = std::uniform_real_distribution<float>(-1, 1);

	rot_axis = { rotRange(rng), rotRange(rng) , rotRange(rng) };
}
