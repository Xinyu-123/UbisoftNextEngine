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


	aabb.box.pos = { 0, 0, 0 };

	for (auto& vert : verts)
	{
		if (-abs(vert.x) < aabb.box.pos.x)
			aabb.box.pos.x = -abs(vert.x);
		if (-abs(vert.y) < aabb.box.pos.y)
			aabb.box.pos.y = -abs(vert.y);
		if (-abs(vert.z) < aabb.box.pos.z)
			aabb.box.pos.z = -abs(vert.z);

	}

	aabb.box.width = -aabb.box.pos.x;
	aabb.box.height = -aabb.box.pos.y;
	aabb.box.depth = -aabb.box.pos.z;
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
	Collider::SetVertices(verts);

	dimensions.pos = base;
	dimensions.width = width;
	dimensions.height = height;
	dimensions.depth = depth;
}
