#include "stdafx.h"
#include "GameEngine.h"
#include "App\app.h"

#include "GameObjectManager.h"
#include "CollisionSystem.h"
#include "RenderSystem.h"

#include "Vector3.h"
#include "Math.h"
#include "Mat4.h"
#include "Quaternion.h"

#include "Color.h"
#include "Cube.h"

#include "Mesh.h"
#include "GameObject.h"
#include "Transform.h"

#include "BoxCollider.h"
#include "SphereCollider.h"

extern void registerEngineClasses();


void GameEngine::Initialize()
{
	registerEngineClasses();

	
	Mat4<float> one = Mat4<float>::Identity();
	Mat4<float> two = Mat4<float>::Identity();

	Quaternion<float> quat1(0.0f, 2.0f, 3.0f, 4.0f);
	Quaternion<float> quat2(0.2f, 0.4f, 3.4f, 123.45f);
	auto quat3 = quat2 * quat1;
	Vector3<float> vec1(0.0f, 1.0f, 0.0f);

	//vec1 = Quaternion<float>::RotateAround(0.78539816339f, Vector3<float>{ 3.0f, 0.0f, 2.0f }, vec1);

	Color c((unsigned char)0u, (unsigned char)50u, (unsigned char)150u);
	Color c2((unsigned char)15u, (unsigned char)10u, (unsigned char)150u);

	auto c3 = c + c2;

	// Color Works


	GameObjectManager::Get().Initialize();
	CollisionSystem::Get().Initialize();
}

void GameEngine::Load(const char* _filename)
{
	GameObject* obj = new GameObject();
	SphereCollider* sphere = new SphereCollider();
	sphere->SetRadius(5.0f);
	obj->AddComponent(sphere);

	Mesh* m = new Mesh();
	{
		std::vector<Vector3<float>> vert;
		std::vector<unsigned short> idx;
		Cube::GetCube(vert, idx);
		m->SetVertices(vert);
		m->SetIndices(idx);
		m->SetColor({ 0.7f, 1.0f, 0.3f });
	}
	obj->GetTransform()->GetPosition().z;
	obj->AddComponent(m);

	GameObjectManager::Get().AddGameObject(obj);

	GameObject* obj2 = new GameObject();

	Mesh* m2 = new Mesh();
	{
		std::vector<Vector3<float>> vert;
		std::vector<unsigned short> idx;
		Cube::GetCube(vert, idx);
		m2->SetVertices(vert);
		m2->SetIndices(idx);
		m2->SetColor({ 1.0f, 0.0f, 0.3f });
	}
	obj2->GetTransform()->GetPosition().z += 2.0f;
	obj2->AddComponent(m2);


	GameObjectManager::Get().AddGameObject(obj2);

}

// _dt is delta time in seconds
void GameEngine::Update(float _dt)
{
	GameObjectManager::Get().Update(_dt);
	CollisionSystem::Get().Update(_dt);
	GameObject* obj = GameObjectManager::Get().GetGameObjects()[0];

	if (App::IsKeyPressed('W'))
	{
		obj->GetTransform()->GetPosition().y += 0.5f * _dt;
	}
	if (App::IsKeyPressed('A'))
	{
		obj->GetTransform()->GetPosition().x -= 0.5f * _dt;
	}
	if (App::IsKeyPressed('S'))
	{
		obj->GetTransform()->GetPosition().y -= 0.5f * _dt;
	}
	if (App::IsKeyPressed('D'))
	{
		obj->GetTransform()->GetPosition().x += 0.5f * _dt;
	}
	if (App::IsKeyPressed(VK_UP))
	{
		obj->GetTransform()->GetPosition().z += 0.5f * _dt;
	}
	if (App::IsKeyPressed(VK_DOWN))
	{
		obj->GetTransform()->GetPosition().z -= 0.5f * _dt;
	}
	if (App::IsKeyPressed('Q'))
	{
		auto& rotation = obj->GetTransform()->GetRotation();
		rotation *= Quaternion<float>::RotationQuaternion(1.0f * _dt, { 0, 1, 0 });
	}
	if (App::IsKeyPressed('E'))
	{
		auto& rotation = obj->GetTransform()->GetRotation();
		rotation *= Quaternion<float>::RotationQuaternion(-1.0f * _dt, { 0, 1, 0 });
	}
	if (App::IsKeyPressed('Z'))
	{
		auto& rotation = obj->GetTransform()->GetRotation();
		rotation *= Quaternion<float>::RotationQuaternion(-1.0f * _dt, { 1, 0, 0 });
	}
}

void GameEngine::Render()
{
	RenderSystem::Get().Render();
}

void GameEngine::Shutdown()
{
}

void GameEngine::Restart()
{
}

GameEngine::GameEngine()
{

}

GameEngine::~GameEngine()
{

}