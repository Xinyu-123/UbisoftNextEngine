#pragma once
#include "Vector3.h"
#include "Box.h"

class Transform;
class AABB
{
private:
	bool CheckCollision(const AABB _other);
	Box GetTransformedBox(const Transform* _transform);
public:
	// the back-bottom-left most point of the AABB
	Box box;

	friend class Collider;
	friend class CollisionSystem;
};

