#include "stdafx.h"
#include "EnemyFactory.h"

#include "GameObject.h"
#include "Sphere.h"
#include "Prism.h"
#include "Mesh.h"
#include "SphereCollider.h";

#include "TurretEnemyController.h"
#include "PredictionEnemyTurret.h"
#include "Quaternion.h"

#include "PhysicsPoint.h"
#include "StandardEnemyShip.h"
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
	controller->SetHealth(10.0f);
	controller->SetPoints(5);
	obj->AddComponent(controller);

	obj->SetTag("Enemy");

	return obj;
}

GameObject* EnemyFactory::GetStandardEnemyShip()
{
	GameObject* obj = new GameObject();

	Mesh* body = new Mesh();
	std::vector<Vector3<float>> verts;
	std::vector<unsigned short> idx;
	Sphere::GetSphere(verts, idx, 0.6f);
	body->SetVertices(verts);
	body->SetIndices(idx);
	body->SetColor({ 0.3f, 1.0f, 0.2f });
	obj->AddComponent(body);

	Mesh* cannon1 = new Mesh();
	Prism::GetPrism(verts, idx, 4, 0.2f, 1.0f);
	Quaternion<float> cannon1Rot = Quaternion<float>::RotationQuaternion(-PI / 8, { 0, 1, 0 }) * Quaternion<float>::RotationQuaternion(-PI / 6, { 1, 0, 0 });
	for (Vector3<float>& vert : verts)
	{
		vert = cannon1Rot.RotateAround(vert);
		vert.z += 0.5f;
		vert.x += 0.5f;
		vert.y -= 0.5f;
	}
	cannon1->SetVertices(verts);
	cannon1->SetIndices(idx);
	cannon1->SetColor({ 1.0f, 0.0f, 0.0f });
	obj->AddComponent(cannon1);

	Mesh* cannon2 = new Mesh();
	Prism::GetPrism(verts, idx, 4, 0.2f, 1.0f);
	Quaternion<float> cannon2Rot = Quaternion<float>::RotationQuaternion(PI / 8, { 0, 1, 0 }) * Quaternion<float>::RotationQuaternion(-PI / 6, { 1, 0, 0 });
	for (Vector3<float>& vert : verts)
	{
		vert = cannon2Rot.RotateAround(vert);
		vert.z += 0.5f;
		vert.x -= 0.5f;
		vert.y -= 0.5f;
	}
	cannon2->SetVertices(verts);
	cannon2->SetIndices(idx);
	cannon2->SetColor({ 1.0f, 0.0f, 0.0f });
	obj->AddComponent(cannon2);

	SphereCollider* collider = new SphereCollider();
	collider->SetRadius(0.6f);
	obj->AddComponent(collider);

	PhysicsPoint* physics = new PhysicsPoint();
	physics->SetMass(2.0f);
	physics->SetResistance(0.3f);
	obj->AddComponent(physics);

	StandardEnemyShip* controller = new StandardEnemyShip();
	controller->SetHealth(10.0f);
	controller->SetPoints(15);
	obj->AddComponent(controller);

	obj->SetTag("Enemy");

	return obj;
}

GameObject* EnemyFactory::GetPredictionTurret()
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
	head->SetColor({ 0.3f, 1.0f, 0.1f });
	obj->AddComponent(head);

	SphereCollider* collider = new SphereCollider();
	collider->SetRadius(0.5f);
	obj->AddComponent(collider);

	PredictionEnemyTurret* controller = new PredictionEnemyTurret();
	controller->SetHealth(15.0f);
	controller->SetPoints(10);
	obj->AddComponent(controller);

	obj->SetTag("Enemy");

	return obj;
}
