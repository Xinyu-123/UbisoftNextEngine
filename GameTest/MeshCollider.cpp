#include "stdafx.h"
#include "MeshCollider.h"

IMPLEMENT_DYNAMIC_CLASS(MeshCollider)

void MeshCollider::Update(float _dt)
{
}

void MeshCollider::Initialize()
{
}

void MeshCollider::Cleanup()
{
}

void MeshCollider::CalculateAABB()
{
	const std::vector<Vector3<float>>& verts = PeekVertices();
	if (verts.size() == 0)
		throw "No Vertices Set on Mesh Collider";


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

void MeshCollider::SetVertices(std::vector<Vector3<float>>& _verts)
{
	Collider::SetVertices(_verts);
}