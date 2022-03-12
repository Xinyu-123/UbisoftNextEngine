#include "stdafx.h"
#include "GameManager.h"

#include "GameObjectManager.h"
#include "CollisionSystem.h"
#include "RenderSystem.h"

#include "Color.h"
#include "Cube.h"
#include "Sphere.h"

#include "GameObject.h"
#include "Transform.h"

#include "Mesh.h"
#include "Camera.h"

#include "BoxCollider.h"
#include "SphereCollider.h"

#include "CharacterController.h"
#include "ConstantRotation.h"
#include "CameraController.h"
#include "PhysicsPoint.h"

#include "PlayerFactory.h"
#include "EnemyFactory.h"

IMPLEMENT_DYNAMIC_CLASS(GameManager)

GameManager::GameManager()
{

}
GameManager::~GameManager()
{

}

void GameManager::Update(float _dt)
{
}

void GameManager::Cleanup()
{
}

void GameManager::Initialize()
{
}

void GameManager::LoadSceneOne()
{
	std::random_device rng;
	std::uniform_real_distribution<float> rangeX(-5.0f, 5.0f);
	std::uniform_real_distribution<float> rangeY(-5.0f, 5.0f);
	std::uniform_real_distribution<float> rangeZ(2.0f, 15.0f);

	static int NUM_BOXES = 10;

	//for (int i = 0; i < NUM_BOXES; ++i)
	//{
	//	GameObject* obj2 = new GameObject();

	//	Mesh* m2 = new Mesh();
	//	std::vector<Vector3<float>> vert;
	//	std::vector<unsigned short> idx;
	//	Cube::GetCube(vert, idx, 1.0f);
	//	m2->SetVertices(vert);
	//	m2->SetIndices(idx);
	//	m2->SetColor({ 1.0f, 0.0f, 0.3f });
	//	obj2->GetTransform()->GetPosition().x += rangeX(rng);
	//	obj2->GetTransform()->GetPosition().y += rangeY(rng);
	//	obj2->GetTransform()->GetPosition().z += rangeZ(rng);

	//	obj2->AddComponent(m2);

	//	BoxCollider* box = new BoxCollider();
	//	box->SetDimensions(Vector3<float>{ -0.5f, -0.5f, -0.5f }, 1.0f, 1.0f, 1.0f);
	//	obj2->AddComponent(box);
	//	ConstantRotation* rot = new ConstantRotation();
	//	obj2->AddComponent(rot);

	//	obj2->SetTag("Box");


	//	GameObjectManager::Get().AddGameObject(obj2);
	//}

	for (int i = 0; i < NUM_BOXES; ++i)
	{
		GameObject* enemy = EnemyFactory::Get().GetStandardTuret();
		enemy->GetTransform()->GetPosition().x = rangeX(rng);
		enemy->GetTransform()->GetPosition().y = rangeY(rng);
		enemy->GetTransform()->GetPosition().z = rangeZ(rng);

		enemy->GetTransform()->GetRotation() = Quaternion<float>::RotationQuaternion(rangeX(rng), { rangeX(rng), rangeX(rng), rangeX(rng) });

		GameObjectManager::Get().AddGameObject(enemy);
	}


	playerGO = PlayerFactory::Get().GetPlayer();
	GameObjectManager::Get().AddGameObject(playerGO);

}
