#include "stdafx.h"
#include "GameEngine.h"
#include "App\app.h"

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

#include <ranges>
#include <random>
#include "GameManager.h"
extern void registerEngineClasses();


void GameEngine::Initialize()
{
	registerEngineClasses();


	GameObjectManager::Get().Initialize();
	CollisionSystem::Get().Initialize();
}

void GameEngine::Load(const char* _filename)
{
	
	GameObjectManager::Get().Load();
	GameObject* gameManagerObj = new GameObject();
	gameManagerObj->SetName("GameManager");
	gameManagerObj->AddComponent(static_cast<Component*>(&GameManager::Get()));
	GameObjectManager::Get().AddGameObject(gameManagerObj);



	GameManager::Get().LoadSceneOne();
}

// _dt is delta time in seconds
void GameEngine::Update(float _dt)
{
	GameObjectManager::Get().Update(_dt);
	CollisionSystem::Get().Update(_dt);

	
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