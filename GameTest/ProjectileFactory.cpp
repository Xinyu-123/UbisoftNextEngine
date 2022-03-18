#include "stdafx.h"
#include "ProjectileFactory.h"

#include "GameObject.h"
#include "Mesh.h"
#include "Sphere.h"
#include "SphereCollider.h"
#include "PhysicsPoint.h"

#include "PlayerProjectile.h"
#include "EnemyProjectile.h"

ProjectileFactory::ProjectileFactory()
{

}
ProjectileFactory::~ProjectileFactory()
{

}

GameObject* ProjectileFactory::GetPlayerProjectile()
{
	const float radius = 0.3f;
	const float mass = 1.0f;

	GameObject* obj = new GameObject();

	Mesh* m = new Mesh();
	std::vector<Vector3<float>> verts;
	std::vector<unsigned short> idx;
	Sphere::GetSphere(verts, idx, radius);
	m->SetVertices(verts);
	m->SetIndices(idx);
	m->SetColor({ 1.0f, 1.0f, 0.0f });
	obj->AddComponent(m);


	SphereCollider* collider = new SphereCollider();
	collider->SetRadius(radius);
	obj->AddComponent(collider);

	PhysicsPoint* physics = new PhysicsPoint();
	physics->SetMass(mass);
	obj->AddComponent(physics);

	PlayerProjectile* logic = new PlayerProjectile();
	logic->SetDamage(5.0f);
	obj->AddComponent(logic);

	obj->SetTag("Player Projectile");
	return obj;
}

GameObject* ProjectileFactory::GetEnemyProjectile(float _radius, const Color& _c)
{
	const float radius = _radius;
	const float mass = 1.0f;

	GameObject* obj = new GameObject();

	Mesh* m = new Mesh();
	std::vector<Vector3<float>> verts;
	std::vector<unsigned short> idx;
	Sphere::GetSphere(verts, idx, radius);
	m->SetVertices(verts);
	m->SetIndices(idx);
	m->SetColor(_c);
	obj->AddComponent(m);


	SphereCollider* collider = new SphereCollider();
	collider->SetRadius(radius);
	obj->AddComponent(collider);

	PhysicsPoint* physics = new PhysicsPoint();
	physics->SetMass(mass);
	obj->AddComponent(physics);

	EnemyProjectile* logic = new EnemyProjectile();
	obj->AddComponent(logic);

	obj->SetTag("Enemy Projectile");


	return obj;
}
