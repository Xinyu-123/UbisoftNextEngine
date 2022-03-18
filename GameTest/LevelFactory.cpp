#include "stdafx.h"
#include "LevelFactory.h"

#include "GameObject.h"
#include "SphereCollider.h"
#include "BoxCollider.h"
#include "Mesh.h"
#include "LevelLoader.h"

#include "Prism.h"
#include "Sphere.h"
#include "Cube.h"

#include "Transform.h"
#include "ConstantRotation.h"

LevelFactory::LevelFactory()
{

}

LevelFactory::~LevelFactory()
{

}

GameObject* LevelFactory::GetLevel1()
{
	GameObject* obj = new GameObject();

	Mesh* body = new Mesh();
	std::vector<Vector3<float>> verts;
	std::vector<unsigned short> idx;
	Cube::GetCube(verts, idx, 0.8f);
	body->SetVertices(verts);
	body->SetIndices(idx);
	body->SetColor({ 0.0f, 1.0f, 0.3f });
	obj->AddComponent(body);

	SphereCollider* collider = new SphereCollider();
	collider->SetRadius(0.5f);
	obj->AddComponent(collider);

	LevelLoader* loader = new LevelLoader();
	loader->SetLevel(1);
	obj->AddComponent(loader);

	obj->GetTransform()->GetRotation() = Quaternion<float>::RotationQuaternion(PI / 10, { 0, 0, 1 });

	ConstantRotation* cRot = new ConstantRotation();
	obj->AddComponent(cRot);

	obj->SetTag("Level Loader");

	return obj;
}


GameObject* LevelFactory::GetLevel2()
{
	GameObject* obj = new GameObject();

	Mesh* body = new Mesh();
	std::vector<Vector3<float>> verts;
	std::vector<unsigned short> idx;
	Cube::GetCube(verts, idx, 0.8f);
	body->SetVertices(verts);
	body->SetIndices(idx);
	body->SetColor({ 0.8f, 0.8f, 0.2f });
	obj->AddComponent(body);

	SphereCollider* collider = new SphereCollider();
	collider->SetRadius(0.5f);
	obj->AddComponent(collider);

	LevelLoader* loader = new LevelLoader();
	loader->SetLevel(2);
	obj->AddComponent(loader);

	obj->GetTransform()->GetRotation() = Quaternion<float>::RotationQuaternion(PI / 10, { 0, 0, 1 });

	ConstantRotation* cRot = new ConstantRotation();
	obj->AddComponent(cRot);

	obj->SetTag("Level Loader");

	return obj;
}


GameObject* LevelFactory::GetLevel3()
{
	GameObject* obj = new GameObject();

	Mesh* body = new Mesh();
	std::vector<Vector3<float>> verts;
	std::vector<unsigned short> idx;
	Cube::GetCube(verts, idx, 0.8f);
	body->SetVertices(verts);
	body->SetIndices(idx);
	body->SetColor({ 0.3f, 0.8f, 0.8f });
	obj->AddComponent(body);

	SphereCollider* collider = new SphereCollider();
	collider->SetRadius(0.5f);
	obj->AddComponent(collider);

	LevelLoader* loader = new LevelLoader();
	loader->SetLevel(3);
	obj->AddComponent(loader);

	obj->GetTransform()->GetRotation() = Quaternion<float>::RotationQuaternion(PI / 10, { 0, 0, 1 });

	ConstantRotation* cRot = new ConstantRotation();
	obj->AddComponent(cRot);

	obj->SetTag("Level Loader");

	return obj;
}

GameObject* LevelFactory::GetLevel4()
{
	GameObject* obj = new GameObject();

	Mesh* body = new Mesh();
	std::vector<Vector3<float>> verts;
	std::vector<unsigned short> idx;
	Cube::GetCube(verts, idx, 0.8f);
	body->SetVertices(verts);
	body->SetIndices(idx);
	body->SetColor({ 1.0f, 1.0f, 1.0f });
	obj->AddComponent(body);

	SphereCollider* collider = new SphereCollider();
	collider->SetRadius(0.5f);
	obj->AddComponent(collider);

	LevelLoader* loader = new LevelLoader();
	loader->SetLevel(4);
	obj->AddComponent(loader);

	obj->GetTransform()->GetRotation() = Quaternion<float>::RotationQuaternion(PI / 10, { 0, 0, 1 });

	ConstantRotation* cRot = new ConstantRotation();
	obj->AddComponent(cRot);

	obj->SetTag("Level Loader");

	return obj;
}

GameObject* LevelFactory::GetHubLevel()
{
	GameObject* obj = new GameObject();

	Mesh* body = new Mesh();
	std::vector<Vector3<float>> verts;
	std::vector<unsigned short> idx;
	Cube::GetCube(verts, idx, 0.8f);
	body->SetVertices(verts);
	body->SetIndices(idx);
	body->SetColor({ 0.0f, 0.2f, 1.0f });
	obj->AddComponent(body);

	SphereCollider* collider = new SphereCollider();
	collider->SetRadius(0.5f);
	obj->AddComponent(collider);

	LevelLoader* loader = new LevelLoader();
	loader->SetLevel(0);
	obj->AddComponent(loader);

	obj->GetTransform()->GetRotation() = Quaternion<float>::RotationQuaternion(PI / 10, { 0, 0, 1 });

	ConstantRotation* cRot = new ConstantRotation();
	obj->AddComponent(cRot);

	obj->SetTag("Level Loader");

	return obj;
}
