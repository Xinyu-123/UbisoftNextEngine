#include "stdafx.h"
#include "GameEngine.h"
#include "App\app.h"

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

#include <ranges>
#include <random>
#include "GameManager.h"
extern void registerEngineClasses();


void GameEngine::Initialize()
{
	registerEngineClasses();

	GameManager::Get().Initialize();
	GameObjectManager::Get().Initialize();
	CollisionSystem::Get().Initialize();
}

void GameEngine::Load(const char* _filename)
{
	GameObjectManager::Get().Load();

	GameManager::Get().LoadInitial();
}

// _dt is delta time in seconds
void GameEngine::Update(float _dt)
{
	GameManager::Get().Update(_dt);
	GameObjectManager::Get().Update(_dt);
	CollisionSystem::Get().Update(_dt);

	// this is where I Load Scene
	if (GameManager::Get().loadScene == true)
	{
		GameManager::Get().LoadScene();
	}

	if (App::IsKeyPressed('R'))
	{
		GameEngine::Get().Restart();
	}
}

void GameEngine::Render()
{
	RenderSystem::Get().Render();
	UIManager::Get().Render();
}

void GameEngine::Shutdown()
{
	GameManager::Get().Cleanup();
	GameObjectManager::Get().ClearGameObjects();
}

void GameEngine::Restart()
{
	Shutdown();
	Load("");
	GameManager::Get().score = 0;
	GameManager::Get().lives = 3;
	Initialize();
}

GameEngine::GameEngine()
{

}

GameEngine::~GameEngine()
{

}