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

