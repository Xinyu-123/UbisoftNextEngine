#include "stdafx.h"
#include "Collider.h"
#include "GameObject.h"

IMPLEMENT_ABSTRACT_CLASS(Collider)

Collider::Collider()
{
	collider = true;
}

void Collider::CalculateAABB()
{

}

void Collider::AddCollisionEvent(std::function<void(Collider*)> _event)
{
	collisionEvents.push_back(_event);
}

void Collider::RemoveCollisionEvent(std::function<void(Collider*)> _event)
{
	// Does not work since you cannot compare function wrappers
	// Need to create some type of function indexing system
	//collisionEvents.erase(std::remove(collisionEvents.begin(), collisionEvents.end(), _event), collisionEvents.end());
}

AABB Collider::GetTransformedAABB() const
{
	AABB ret = aabb;
	const Transform* transform = go->PeekTransform();
	ret.GetTransformedBox(transform);
	return ret;
}

void Collider::OnCollision(Collider* _other)
{
	for (auto collisionEvent : collisionEvents)
	{
		collisionEvent(_other);
	}
}