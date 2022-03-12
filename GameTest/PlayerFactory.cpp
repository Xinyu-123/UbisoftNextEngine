#include "stdafx.h"
#include "PlayerFactory.h"

#include "Color.h"
#include "Prism.h"

#include "GameObject.h"
#include "Transform.h"

#include "Mesh.h"
#include "Camera.h"

#include "BoxCollider.h"
#include "SphereCollider.h"

#include "CharacterController.h"
#include "PhysicsPoint.h"

PlayerFactory::PlayerFactory()
{

}

PlayerFactory::~PlayerFactory()
{

}

GameObject* PlayerFactory::GetPlayer()
{
	GameObject* obj = new GameObject();

	Camera* camera = new Camera();
	obj->AddComponent(camera);

	CharacterController* cameraController = new CharacterController();
	obj->AddComponent(cameraController);

	PhysicsPoint* physicsPoint = new PhysicsPoint();
	physicsPoint->SetMass(4.0f);
	obj->AddComponent(physicsPoint);

	Mesh* cannon = new Mesh();
	std::vector<Vector3<float>> verts;
	std::vector<unsigned short> idx;
	Prism::GetPrism(verts, idx, 4, 0.3f, 0.6f);
	Quaternion<float> cannon1Rot = Quaternion<float>::RotationQuaternion(-PI / 8, { 0, 1, 0 }) * Quaternion<float>::RotationQuaternion(-PI / 6, { 1, 0, 0 });
	for (Vector3<float>& vert : verts)
	{
		vert = cannon1Rot.RotateAround(vert);
		vert.z += 0.5f;
		vert.x += 0.5f;
		vert.y -= 0.5f;
	}
	cannon->SetVertices(verts);
	cannon->SetIndices(idx);
	cannon->SetColor({ 0.0f, 0.0f, 1.0f });
	obj->AddComponent(cannon);

	Mesh* cannon2 = new Mesh();
	Prism::GetPrism(verts, idx, 4, 0.3f, 0.6f);

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
	cannon2->SetColor({ 0.0f, 0.0f, 1.0f });
	obj->AddComponent(cannon2);

	SphereCollider* collider = new SphereCollider();
	collider->SetRadius(0.2f);
	obj->AddComponent(collider);

	obj->SetName("Player");

	return obj;
}
