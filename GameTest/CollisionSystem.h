#pragma once
#include "Singleton.h"
#include "BoxCollider.h"
#include "MeshCollider.h"

class Collider;
class SphereCollider;
class CollisionSystem : public Singleton<CollisionSystem>
{
	DECLARE_SINGLETON(CollisionSystem)

public:

private:
	void Initialize();
	void Update(float _dt);

	void AddCollider(Collider* _collider) 
	{ 
		if (_collider == nullptr)
			return;

		colliders.push_back(_collider); 
	}

	void RemoveCollider(Collider* _collider)
	{
		colliders.erase(std::remove(colliders.begin(), colliders.end(), _collider), colliders.end());
	}

	bool TestCollision(Collider* _collider1, Collider* _collider2);

	bool Sphere_To_Sphere_Collision(SphereCollider* collider, SphereCollider* _sphere);
	bool Sphere_To_Box_Collision(SphereCollider* collider, BoxCollider* _sphere);
	bool Sphere_To_Mesh_Collision(SphereCollider* _sphere, MeshCollider* collider);
	bool Box_To_Box_Collision(SphereCollider* collider, BoxCollider* _sphere);
	bool Box_To_Mesh_Collision(BoxCollider* collider, BoxCollider* _sphere);
	bool Mesh_To_Mesh_Collision(MeshCollider* _collider1, MeshCollider* _collider2);

private:
	std::vector<Collider*> colliders;

	
	friend class GameEngine;
	friend class GameObject;
};

