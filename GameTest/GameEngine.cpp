#include "stdafx.h"
#include "GameEngine.h"
#include "App\app.h"
#include "GameObjectManager.h"
#include "Vector3.h"
#include "Math.h"
#include "Mat4.h"
extern void registerEngineClasses();

void GameEngine::Initialize()
{
	registerEngineClasses();
	GameObjectManager::Get().Initialize();
	
	Mat4<float> one = Mat4<float>::Identity();
	Mat4<float> two = Mat4<float>::Identity();



}

void GameEngine::Load(const char* _filename)
{
		
}

void GameEngine::Update(float _dt)
{
	GameObjectManager::Get().Update(_dt);
}

void GameEngine::Render()
{
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