#pragma once
#include "Component.h"
#include "AABB.h"
class Collider : public Component
{
	DECLARE_ABSTRACT_DERIVED_CLASS(Collider, Component)

public:
	const std::vector<Vector3<float>>& PeekVertices() const { return vertices; }
	void AddCollisionEvent(std::function<void(Collider*)> _event);
	void RemoveCollisionEvent(std::function<void(Collider*)> _event);
	AABB GetTransformedAABB() const;
protected:
	Collider();
	virtual void SetVertices(std::vector<Vector3<float>>& _verts)
	{
		vertices = _verts;
		CalculateAABB();
	}

	virtual void CalculateAABB() = 0;

private:
	void OnCollision(Collider* _other);

protected:
	AABB aabb;

private:
	std::vector<Vector3<float>> vertices;
	std::vector<std::function<void(Collider*)>> collisionEvents;
	std::vector<Collider*> previousCollisions;

	friend class CollisionSystem;
};

