#include "stdafx.h"
#include "CollisionSystem.h"
#include "Collider.h"
#include "GameObject.h"
#include "Transform.h"
#include "SphereCollider.h"
#include "Plane.h"
#include <limits>
CollisionSystem::CollisionSystem()
{

}

CollisionSystem::~CollisionSystem()
{

}

std::vector<Collider*> CollisionSystem::TestCollision(Collider* _collider) const
{
	std::vector<Collider*> ret;
	for (auto col : colliders)
	{
		if (_collider->GetTransformedAABB().CheckCollision(_collider->GetTransformedAABB()) == false) // Check for AABB Collision
			continue;

		if (TestCollision(_collider, col))
			ret.push_back(col);
	}

	return ret;
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
				>
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

		window.push_back(current);
	}

}

bool CollisionSystem::TestCollision(Collider* _collider1, Collider* _collider2) const  
{
	// Sort the colliders so the priority of _collider1 is sphere->box->mesh
	if (_collider2->getDerivedClassHashCode() == BoxCollider::getClassHashCode())
		std::swap(_collider1, _collider2);

	if (_collider2->getDerivedClassHashCode() == SphereCollider::getClassHashCode())
		std::swap(_collider1, _collider2);

	if (_collider1->getDerivedClassHashCode() == SphereCollider::getClassHashCode())
	{
		if (_collider2->getDerivedClassHashCode() == SphereCollider::getClassHashCode())
			return Sphere_To_Sphere_Collision(static_cast<SphereCollider*>(_collider1), static_cast<SphereCollider*>(_collider2));


		if (_collider2->getDerivedClassHashCode() == BoxCollider::getClassHashCode())
			return Sphere_To_Box_Collision(static_cast<SphereCollider*>(_collider1), static_cast<BoxCollider*>(_collider2));
	}

	if (_collider1->getDerivedClassHashCode() == BoxCollider::getClassHashCode())
	{
		if (_collider2->getDerivedClassHashCode() == BoxCollider::getClassHashCode())
			return Box_To_Box_Collision(static_cast<BoxCollider*>(_collider1), static_cast<BoxCollider*>(_collider2));
	}

	return false;
}

bool CollisionSystem::Sphere_To_Sphere_Collision(const SphereCollider* _collider1, const SphereCollider* _collider2) const 
{
	float distSq = (_collider1->transform->PeekPosition() - _collider2->transform->PeekPosition()).MagnitudeSq();
	float combined_radius = (_collider1->PeekRadius() + _collider2->PeekRadius());

	return distSq <= combined_radius * combined_radius;
}

bool CollisionSystem::Sphere_To_Box_Collision(const SphereCollider* _collider1, const BoxCollider* _collider2) const 
{
	Transform* transform1 = _collider1->transform;
	Transform* transform2 = _collider2->transform;

	// Not as simple as I have thought
	std::vector<Vector3<float>> boxVerts = _collider2->PeekVertices();

	// Create the Planes
	const std::vector<char> planeIdx =
	{
		0, 2, 1, 6, // front plane
		3, 4, 0, 2,  // left plane
		5, 7, 3, 4, // back plane
		1, 6, 5, 7, // right plane
		7, 6, 4, 2, // top plane
		0, 1, 3, 5 // bottom plane
	};


	// transform the verts
	for (Vector3<float>& vert : boxVerts)
	{
		transform2->TransformVertex(vert);
	}

	// Test the distance from the center of the sphere to the closest point on each plane of the box
	for (short i = 0; i < planeIdx.size(); i += 4)
	{
		std::vector<Vector3<float>> planeVerts = {
			boxVerts[planeIdx[i]], boxVerts[planeIdx[i + 1]], boxVerts[planeIdx[i + 2]], boxVerts[planeIdx[i + 3]]
		};
		Plane plane;
		plane.GenerateBoundedPlane(planeVerts);

		const Vector3<float>& spherePos = transform1->PeekPosition();

		Vector3<float> closest_point_on_plane = plane.GetClosestPoint(spherePos);

		if ((closest_point_on_plane - spherePos).MagnitudeSq() <= _collider1->radius * _collider1->radius)
			return true;
	}

	return false;
}

bool CollisionSystem::Box_To_Box_Collision(const BoxCollider* _collider1, const BoxCollider* _collider2) const 
{
	const Transform* transform1 = _collider1->go->PeekTransform();
	const Transform* transform2 = _collider2->go->PeekTransform();
	
	// Implement Separating Axis Theorem
	std::vector<Vector3<float>> axes1 =
	{
		transform1->GetRight(),
		transform1->GetUp(),
		transform1->GetForward(),
	};
	std::vector<Vector3<float>> axes2 = 
	{
		transform2->GetRight(),
		transform2->GetUp(),
		transform2->GetForward(),
	};

	std::vector<Vector3<float>> allAxes =
	{
		axes1[0],
		axes1[1],
		axes1[2],
		axes2[0],
		axes2[1],
		axes2[2],
		axes1[0].Cross(axes2[0]),
		axes1[0].Cross(axes2[1]),
		axes1[0].Cross(axes2[2]),
		axes1[1].Cross(axes2[0]),
		axes1[1].Cross(axes2[1]),
		axes1[1].Cross(axes2[2]),
		axes1[2].Cross(axes2[0]),
		axes1[2].Cross(axes2[1]),
		axes1[2].Cross(axes2[2])
	};

	auto aVerts = _collider1->PeekVertices();
	auto bVerts = _collider2->PeekVertices();

	// transform the verts
	for (int i = 0; i < aVerts.size(); ++i)
	{
		transform1->TransformVertex(aVerts[i]);
		transform2->TransformVertex(bVerts[i]);
	}

	if (HasProjectionOverlap(aVerts, bVerts, allAxes))
		return true;

	return false;
}

float FindOverlap(float astart, float aend, float bstart, float bend)
{
	if (astart < bstart)
	{
		if (aend < bstart)
			return 0.0f;

		return aend - bstart;
	}

	if (bend < astart)
		return 0.0f;


	return bend - astart;
}

bool CollisionSystem::HasProjectionOverlap(const std::vector<Vector3<float>>& aVerts,
	const std::vector<Vector3<float>>& bVerts, const std::vector<Vector3<float>>& allAxes) const
{
	bool hasOverlap = true;

	float minOverlap = 0;

	for (int i = 0; i < allAxes.size(); i++)
	{
		float bProjMin = std::numeric_limits<float>::max();
		float aProjMin = std::numeric_limits<float>::max();
		float bProjMax = std::numeric_limits<float>::min();
		float aProjMax = std::numeric_limits<float>::min();

		Vector3 axis = allAxes[i];

		for (int j = 0; j < bVerts.size(); j++)
		{
			float val = bVerts[j].Dot(axis);

			if (val < bProjMin)
				bProjMin = val;


			if (val > bProjMax)
				bProjMax = val;
		}

		for (int j = 0; j < aVerts.size(); j++)
		{
			float val = aVerts[j].Dot(axis);

			if (val < aProjMin)
				aProjMin = val;

			if (val > aProjMax)
				aProjMax = val;
		}

		float overlap = FindOverlap(aProjMin, aProjMax, bProjMin, bProjMax);

		if (overlap <= 0)
			return false;

	}

	return true;
}


std::vector<Collider*> CollisionSystem::RayCollision(const Ray& _ray)
{
	std::vector<Collider*> ret;
	for (auto collider : colliders)
	{
		AABB colliderAABB = collider->GetTransformedAABB();


		if (collider->getDerivedClassHashCode() == SphereCollider::getClassHashCode())
		{
			if (Ray_To_Sphere_Collision(_ray, static_cast<SphereCollider*>(collider)))
				ret.push_back(collider);
		}

		if (collider->getDerivedClassHashCode() == BoxCollider::getClassHashCode())
		{
			if (Ray_To_Box_Collision(_ray, static_cast<BoxCollider*>(collider)))
				ret.push_back(collider);
		}

	}
	return ret;
}

bool CollisionSystem::Ray_To_Sphere_Collision(const Ray& _ray, const SphereCollider* _collider) const
{
	// Find closest point on the line from the sphere
	// dot product
	Vector3<float> rayDir = (_ray.end - _ray.start).GetNormalized();
	Vector3<float> point = _collider->transform->PeekPosition();

	float t = (-((_ray.start.x - point.x) * rayDir.x) - ((_ray.start.y - point.y) * rayDir.y) - ((_ray.start.z - point.z) * rayDir.z)) /
		(rayDir.x * rayDir.x + rayDir.y * rayDir.y + rayDir.z * rayDir.z);

	Vector3<float> closest_point = { _ray.start.x + rayDir.x * t, _ray.start.y + rayDir.y * t , _ray.start.z + rayDir.z * t };

	if (t < 0) // closest point is behind the line
	{
		Vector3<float> sphere_to_line = _ray.start - point;
		if (sphere_to_line.MagnitudeSq() <= _collider->radius * _collider->radius)
			return true;
	}

	float max_t = (_ray.end.x - _ray.start.x) / rayDir.x;

	if (max_t < t) // point is too far forward
	{
		Vector3<float> sphere_to_line = _ray.end - point;
		if (sphere_to_line.MagnitudeSq() <= _collider->radius * _collider->radius)
			return true;
	}

	return (closest_point - point).MagnitudeSq() <= _collider->radius * _collider->radius;
}

bool CollisionSystem::Ray_To_Box_Collision(const Ray& _ray, const BoxCollider* _collider) const
{
	// Separating Axis Theorom with x, y and z axis
	const Transform* transform2 = _collider->go->PeekTransform();

	// Implement Separating Axis Theorem
	std::vector<Vector3<float>> axes1 =
	{
		(_ray.end - _ray.start).GetNormalized()
	};
	std::vector<Vector3<float>> axes2 =
	{
		transform2->GetRight(),
		transform2->GetUp(),
		transform2->GetForward(),
	};

	std::vector<Vector3<float>> allAxes =
	{
		axes1[0],
		axes2[0],
		axes2[1],
		axes2[2],
		axes1[0].Cross(axes2[0]),
		axes1[0].Cross(axes2[1]),
		axes1[0].Cross(axes2[2]),
	};

	std::vector<Vector3<float>> aVerts =
	{
		_ray.start, _ray.end
	};

	auto bVerts = _collider->PeekVertices();

	// transform the verts
	for (int i = 0; i < bVerts.size(); ++i)
		transform2->TransformVertex(bVerts[i]);


	if (HasProjectionOverlap(aVerts, bVerts, allAxes))
		return true;

	return false;
}


void CollisionSystem::Initialize()
{
}
