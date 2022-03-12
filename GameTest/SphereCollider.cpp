#include "stdafx.h"
#include "SphereCollider.h"

IMPLEMENT_DYNAMIC_CLASS(SphereCollider)

SphereCollider::SphereCollider()
{

}

void SphereCollider::SetRadius(float _radius)
{
	assert(_radius >= 0.0f);

	SetVertices(std::vector<Vector3<float>>{ Vector3<float>{_radius, 0, 0} });
	radius = _radius;
	CalculateAABB();
}

void SphereCollider::CalculateAABB()
{
	if (PeekVertices().size() == 0)
		throw "No Radius Set on Sphere Collider";

	aabb.box.pos = Vector3<float>(-radius, -radius, -radius);
	aabb.box.width = radius * 2;
	aabb.box.height = radius * 2;
	aabb.box.depth = radius * 2;
}

void SphereCollider::Update(float _dt)
{
	
}

void SphereCollider::Initialize()
{
	Component::Initialize();

}

void SphereCollider::Cleanup()
{
}

