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
	auto& rotation = go->GetTransform()->GetRotation();
	rotation *= Quaternion<float>::RotationQuaternion(0.3f * _dt, { 0, 1, 0 });



}

void ConstantRotation::Cleanup()
{
}

void ConstantRotation::Initialize()
{
	ComponentScript::Initialize();
}
