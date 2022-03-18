#include "stdafx.h"
#include "GameManager.h"

#include "GameObjectManager.h"
#include "CollisionSystem.h"
#include "RenderSystem.h"
#include "UIManager.h"

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
#include "UIFactory.h";

#include "Sprite.h"

#include "App/SimpleSound.h"
#include "App/app.h"
#include "GameEngine.h"
#include "LevelFactory.h"


GameManager::GameManager()
	:
	rng(std::random_device()()),
	rangeX(-15.0f, 15.0f),
	rangeY(-15.0f, 15.0f),
	rangeZ(5.0f, 25.0f)
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
	GameObjectManager::Get().AddGameObjectRunTime(UIFactory::Get().GetPlayerCrosshair());
	GameObject* scoreObj = UIFactory::Get().GetScoreText();
	ScoreText = static_cast<Text*>(scoreObj->FindComponentOfType(Text::getClassHashCode()));
	GameObjectManager::Get().AddGameObjectRunTime(scoreObj);
}

void GameManager::LoadScene(int _scene)
{
	loadScene = true;
	scene_to_load = _scene;
}


void GameManager::LoadScene()
{
	GameEngine::Get().Shutdown();
	switch (scene_to_load)
	{
	case 0:
		LoadSceneHub();
		break;
	case 1:
		LoadSceneOne();
		break;
	case 2:
		LoadSceneTwo();
		break;
	case 3:
		LoadSceneThree();
		break;
	case 4:
		LoadSceneFour();
		break;
	}

	GameManager::Get().Initialize();
	GameObjectManager::Get().Initialize();
	loadScene = false;
}

void GameManager::LoadInitial()
{
	LoadSceneHub();
}

void GameManager::LoadSceneHub()
{
	const int NUM_LEVELS = 3;



	for (int i = 0; i < NUM_LEVELS; ++i)
	{
		GameObject* level = LevelFactory::Get().GetLevel1();
		level->GetTransform()->GetPosition() = { rangeX(rng), rangeY(rng), rangeZ(rng) };
		GameObjectManager::Get().AddGameObject(level);
	}
	
	for (int i = 0; i < NUM_LEVELS; ++i)
	{
		GameObject* level = LevelFactory::Get().GetLevel2();
		level->GetTransform()->GetPosition() = { rangeX(rng), rangeY(rng), rangeZ(rng) };
		GameObjectManager::Get().AddGameObject(level);
	}
	
	for (int i = 0; i < NUM_LEVELS; ++i)
	{
		GameObject* level = LevelFactory::Get().GetLevel3();
		level->GetTransform()->GetPosition() = { rangeX(rng), rangeY(rng), rangeZ(rng) };
		GameObjectManager::Get().AddGameObject(level);
	}
	
	for (int i = 0; i < NUM_LEVELS; ++i)
	{
		GameObject* level = LevelFactory::Get().GetLevel4();
		level->GetTransform()->GetPosition() = { rangeX(rng), rangeY(rng), rangeZ(rng) };
		GameObjectManager::Get().AddGameObject(level);
	}


	playerGO = PlayerFactory::Get().GetPlayer();
	GameObjectManager::Get().AddGameObject(playerGO);
}

void GameManager::LoadSceneOne()
{
	const int NUM_ENEMIES = 12;

	for (int i = 0; i < NUM_ENEMIES; ++i)
	{
		GameObject* enemy = EnemyFactory::Get().GetStandardTuret();
		enemy->GetTransform()->GetPosition() = { rangeX(rng), rangeY(rng), rangeZ(rng) };
		enemy->GetTransform()->GetRotation() = Quaternion<float>::RotationQuaternion(rangeX(rng), { rangeX(rng), rangeX(rng), rangeX(rng) });

		GameObjectManager::Get().AddGameObject(enemy);
	}

	GameObject* hub = LevelFactory::Get().GetHubLevel();
	hub->GetTransform()->GetPosition() = { -3, 0, 28 };
	GameObjectManager::Get().AddGameObject(hub);

	playerGO = PlayerFactory::Get().GetPlayer();
	GameObjectManager::Get().AddGameObject(playerGO);
	
}

void GameManager::LoadSceneTwo()
{
	const int NUM_ENEMIES = 9;

	for (int i = 0; i < NUM_ENEMIES; ++i)
	{
		GameObject* enemy = EnemyFactory::Get().GetPredictionTurret();
		enemy->GetTransform()->GetPosition() = { rangeX(rng), rangeY(rng), rangeZ(rng) };
		enemy->GetTransform()->GetRotation() = Quaternion<float>::RotationQuaternion(rangeX(rng), { rangeX(rng), rangeX(rng), rangeX(rng) });

		GameObjectManager::Get().AddGameObject(enemy);
		
		GameObject* enemy2 = EnemyFactory::Get().GetStandardTuret();
		enemy2->GetTransform()->GetPosition() = { rangeX(rng), rangeY(rng), rangeZ(rng) };
		enemy2->GetTransform()->GetRotation() = Quaternion<float>::RotationQuaternion(rangeX(rng), { rangeX(rng), rangeX(rng), rangeX(rng) });

		GameObjectManager::Get().AddGameObject(enemy2);
	}

	GameObject* hub = LevelFactory::Get().GetHubLevel();
	hub->GetTransform()->GetPosition() = { -3, 0, 28 };
	GameObjectManager::Get().AddGameObject(hub);

	playerGO = PlayerFactory::Get().GetPlayer();
	GameObjectManager::Get().AddGameObject(playerGO);
}

void GameManager::LoadSceneThree()
{
	const int NUM_ENEMIES = 9;

	for (int i = 0; i < NUM_ENEMIES; ++i)
	{
		GameObject* enemy = EnemyFactory::Get().GetStandardEnemyShip();
		enemy->GetTransform()->GetPosition() = { rangeX(rng), rangeY(rng), rangeZ(rng) };
		enemy->GetTransform()->GetRotation() = Quaternion<float>::RotationQuaternion(rangeX(rng), { rangeX(rng), rangeX(rng), rangeX(rng) });

		GameObjectManager::Get().AddGameObject(enemy);
		
		GameObject* enemy2 = EnemyFactory::Get().GetStandardTuret();
		enemy2->GetTransform()->GetPosition() = { rangeX(rng), rangeY(rng), rangeZ(rng) };
		enemy2->GetTransform()->GetRotation() = Quaternion<float>::RotationQuaternion(rangeX(rng), { rangeX(rng), rangeX(rng), rangeX(rng) });

		GameObjectManager::Get().AddGameObject(enemy2);
	}

	GameObject* hub = LevelFactory::Get().GetHubLevel();
	hub->GetTransform()->GetPosition() = { -3, 0, 28 };
	GameObjectManager::Get().AddGameObject(hub);

	playerGO = PlayerFactory::Get().GetPlayer();
	GameObjectManager::Get().AddGameObject(playerGO);
}

void GameManager::LoadSceneFour()
{
	const int NUM_ENEMIES = 12;

	for (int i = 0; i < NUM_ENEMIES; ++i)
	{
		GameObject* enemy = EnemyFactory::Get().GetStandardEnemyShip();
		enemy->GetTransform()->GetPosition() = { rangeX(rng), rangeY(rng), rangeZ(rng) };
		enemy->GetTransform()->GetRotation() = Quaternion<float>::RotationQuaternion(rangeX(rng), { rangeX(rng), rangeX(rng), rangeX(rng) });

		GameObjectManager::Get().AddGameObject(enemy);

		GameObject* enemy2 = EnemyFactory::Get().GetStandardTuret();
		enemy2->GetTransform()->GetPosition() = { rangeX(rng), rangeY(rng), rangeZ(rng) };
		enemy2->GetTransform()->GetRotation() = Quaternion<float>::RotationQuaternion(rangeX(rng), { rangeX(rng), rangeX(rng), rangeX(rng) });

		GameObjectManager::Get().AddGameObject(enemy2);
		
		GameObject* enemy3 = EnemyFactory::Get().GetStandardTuret();
		enemy3->GetTransform()->GetPosition() = { rangeX(rng), rangeY(rng), rangeZ(rng) };
		enemy3->GetTransform()->GetRotation() = Quaternion<float>::RotationQuaternion(rangeX(rng), { rangeX(rng), rangeX(rng), rangeX(rng) });

		GameObjectManager::Get().AddGameObject(enemy3);
	}

	GameObject* hub = LevelFactory::Get().GetHubLevel();
	hub->GetTransform()->GetPosition() = { -3, 0, 28 };
	GameObjectManager::Get().AddGameObject(hub);

	playerGO = PlayerFactory::Get().GetPlayer();
	GameObjectManager::Get().AddGameObject(playerGO);
}
