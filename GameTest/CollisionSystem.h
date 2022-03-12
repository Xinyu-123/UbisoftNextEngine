#pragma once
#include "Singleton.h"
#include "BoxCollider.h"
#include "MeshCollider.h"
#include "Ray.h"

class Collider;
class SphereCollider;
class CollisionSystem : public Singleton<CollisionSystem>
{
	DECLARE_SINGLETON(CollisionSystem)

public:
	std::vector<Collider*> TestCollision(Collider* _collider) const;
	std::vector<Collider*> RayCollision(const Ray& _ray);
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

	bool TestCollision(Collider* _collider1, Collider* _collider2) const;

	bool Sphere_To_Sphere_Collision(const SphereCollider* _collider1, const SphereCollider* _collider2) const;
	bool Sphere_To_Box_Collision(const SphereCollider* _collider1, const BoxCollider* _collider2) const;
	bool Box_To_Box_Collision(const BoxCollider* _collider1, const BoxCollider* _collider2) const;

	bool Ray_To_Sphere_Collision(const Ray& _ray, const SphereCollider* _collider) const;
	bool Ray_To_Box_Collision(const Ray& _ray, const BoxCollider* _collider) const;

	bool HasProjectionOverlap(const std::vector<Vector3<float>>& aVerts, const std::vector<Vector3<float>>& bVerts, const std::vector<Vector3<float>>& allAxes) const;
private:
	std::vector<Collider*> colliders;

	
	friend class GameEngine;
	friend class GameObject;
};

