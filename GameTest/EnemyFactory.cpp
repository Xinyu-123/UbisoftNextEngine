#include "stdafx.h"
#include "EnemyFactory.h"

#include "GameObject.h"
#include "Sphere.h"
#include "Prism.h"
#include "Mesh.h"
#include "SphereCollider.h";

#include "TurretEnemyController.h"
EnemyFactory::EnemyFactory()
{

}

EnemyFactory::~EnemyFactory()
{

}

GameObject* EnemyFactory::GetStandardTuret()
{
	GameObject* obj = new GameObject();

	Mesh* body = new Mesh();
	std::vector<Vector3<float>> verts;
	std::vector<unsigned short> idx;
	Prism::GetPrism(verts, idx, 4, 0.3f, 0.6f);
	body->SetVertices(verts);
	body->SetIndices(idx);
	body->SetColor({ 1.0f, 0.0f, 0.0f });
	obj->AddComponent(body);

	Mesh* head = new Mesh();
	Sphere::GetSphere(verts, idx, 0.15f);
	for (Vector3<float>& vert : verts)
	{
		vert.z += 0.45f;
	}
	head->SetVertices(verts);
	head->SetIndices(idx);
	head->SetColor({ 0.3f, 0.0f, 0.5f });
	obj->AddComponent(head);

	SphereCollider* collider = new SphereCollider();
	collider->SetRadius(0.5f);
	obj->AddComponent(collider);

	TurretEnemyController* controller = new TurretEnemyController();
	obj->AddComponent(controller);

	obj->SetTag("Enemy");

	return obj;
}