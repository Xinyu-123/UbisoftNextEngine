#include "stdafx.h"
#include "AABB.h"
#include "Transform.h"

bool AABB::CheckCollision(const AABB _other)
{
	if (box.pos.x + box.width < _other.box.pos.x) // too far left
		return false;

	if (box.pos.x > _other.box.pos.x + _other.box.width) // too far right
		return false;

	if (box.pos.y + box.height < _other.box.pos.y) // too far down
		return false;

	if (box.pos.y > _other.box.pos.y + _other.box.height) // too far up
		return false;

	if (box.pos.z + box.depth < _other.box.pos.z) // too far back
		return false;

	if (box.pos.z > _other.box.pos.z + _other.box.depth) // too far forward
		return false;


	return true;
}

Box AABB::GetTransformedBox(const Transform* _transform)
{
	Box ret = box;

	// No need to scale the box, might change it later though
	//ret.pos.x *= _transform->PeekScale().x;
	//ret.pos.y *= _transform->PeekScale().y;
	//ret.pos.z *= _transform->PeekScale().z;
	//ret.width *= _transform->PeekScale().x;
	//ret.height *= _transform->PeekScale().y;
	//ret.depth *= _transform->PeekScale().z;

	ret.pos.x += _transform->PeekPosition().x;
	ret.pos.y += _transform->PeekPosition().y;
	ret.pos.z += _transform->PeekPosition().z;


	return ret;
}

