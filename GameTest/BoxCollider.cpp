#include "stdafx.h"
#include "BoxCollider.h"
#include "Cube.h"

IMPLEMENT_DYNAMIC_CLASS(BoxCollider)

void BoxCollider::Update(float _dt)
{
}

void BoxCollider::Initialize()
{
}

void BoxCollider::Cleanup()
{
}

void BoxCollider::CalculateAABB()
{
	const std::vector<Vector3<float>>& verts = PeekVertices();
	if (verts.size() == 0)
		throw "No Dimensions Set on Box Collider";


	float maxLength = Vector3<float>(dimensions.width, dimensions.height, dimensions.depth).Magnitude();

	aabb.box.pos = Vector3<float>(-maxLength, -maxLength, -maxLength);
	aabb.box.width = maxLength;
	aabb.box.height = maxLength;
	aabb.box.depth = maxLength;
}

void BoxCollider::SetDimensions(Vector3<float>& base, float width, float height, float depth)
{
	std::vector<Vector3<float>> verts = {
		base,
		{base.x + width, base.y, base.z},
		{base.x, base.y + height, base.z},
		{base.x, base.y, base.z + depth},
		{base.x, base.y + height, base.z + depth},
		{base.x + width, base.y, base.z + depth},
		{base.x + width, base.y + height, base.z},
		{base.x + width, base.y + height, base.z + depth},
	};

	dimensions.pos = base;
	dimensions.width = width;
	dimensions.height = height;
	dimensions.depth = depth;

	Collider::SetVertices(verts);
}
