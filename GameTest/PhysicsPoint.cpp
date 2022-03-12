#include "stdafx.h"
#include "PhysicsPoint.h"
#include "Transform.h"

IMPLEMENT_DYNAMIC_CLASS(PhysicsPoint)

PhysicsPoint::PhysicsPoint()
	:
	position(nullptr)
{
}

void PhysicsPoint::Initialize()
{
	position = &(transform->GetPosition());
}

void PhysicsPoint::Update(float _dt)
{
	Vector3<float> acceleration = force / mass;

	velocity += acceleration * _dt;
	*position += velocity * _dt;

	force = { 0, 0, 0 };
}

void PhysicsPoint::Cleanup()
{
}
