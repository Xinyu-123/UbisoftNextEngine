#include "stdafx.h"
#include "CollisionSystem.h"
#include "Collider.h"
#include "GameObject.h"
#include "Transform.h"
CollisionSystem::CollisionSystem()
{

}

CollisionSystem::~CollisionSystem()
{

}

void CollisionSystem::Update(float _dt)
{
	// sort all the colliders by aabb left side
	std::sort(colliders.begin(), colliders.end(), [](const Collider* _lhs, const Collider* _rhs) {
		return 
			_lhs->GetTransformedAABB().box.pos.x
			< 
			_rhs->GetTransformedAABB().box.pos.x;
	});



	std::list<Collider*> window;
	for (size_t i = 0; i < colliders.size(); ++i)
	{
		Collider* current = colliders[i];
		const Transform* currentTransform = current->go->PeekTransform();

		std::vector<Collider*> remove_window;
		for (Collider* collider : window)
		{
			const Transform* windowTransform = collider->go->PeekTransform();

			if (current->GetTransformedAABB().box.pos.x
				<
				collider->GetTransformedAABB().box.pos.x + collider->GetTransformedAABB().box.width)
			{
				remove_window.push_back(collider);
				continue;
			}

			if (current->GetTransformedAABB().CheckCollision(collider->GetTransformedAABB()) == false) // Check for AABB Collision
				continue;

			// Test for Collider Collision
			if (TestCollision(current, collider))
			{

				current->OnCollision(collider);
				collider->OnCollision(current);
			}
		}

		for (auto removeCollider : remove_window)
			window.remove(removeCollider);
	}

}

bool CollisionSystem::TestCollision(Collider* _collider1, Collider* _collider2)
{
	return false;
}

bool CollisionSystem::Sphere_To_Sphere_Collision(SphereCollider* collider, SphereCollider* _sphere)
{
	return false;
}

bool CollisionSystem::Sphere_To_Box_Collision(SphereCollider* collider, BoxCollider* _sphere)
{
	return false;
}

bool CollisionSystem::Sphere_To_Mesh_Collision(SphereCollider* _sphere, MeshCollider* collider)
{
	return false;
}

bool CollisionSystem::Box_To_Box_Collision(SphereCollider* collider, BoxCollider* _sphere)
{
	return false;
}

bool CollisionSystem::Box_To_Mesh_Collision(BoxCollider* collider, BoxCollider* _sphere)
{
	return false;
}

bool CollisionSystem::Mesh_To_Mesh_Collision(MeshCollider* _collider1, MeshCollider* _collider2)
{
	return false;
}

void CollisionSystem::Initialize()
{
}
