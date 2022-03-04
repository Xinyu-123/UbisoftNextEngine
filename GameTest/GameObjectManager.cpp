#include "stdafx.h"
#include "GameObjectManager.h"
#include "GameObject.h"
void GameObjectManager::Initialize()
{
}

void GameObjectManager::Load()
{
}

void GameObjectManager::Update(float _dt)
{
	for (auto gm : gameObjects)
	{
		gm->Update(_dt);
	}

	for (auto gm : gameObjectsToRemove)
	{
		gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), gm), gameObjects.end());
		delete gm;
	}
}

void GameObjectManager::AddGameObject(GameObject* const _gm)
{
	gameObjects.push_back(_gm);
}

void GameObjectManager::RemoveGameObject(GameObject* const _gm)
{
	// gameobject is already set to be destroyed
	if (_gm->toBeDestroyed == true)
		return;
	gameObjectsToRemove.push_back(_gm);
	_gm->toBeDestroyed = true;
}

GameObject* GameObjectManager::GetGameObjectByTag(std::string& _tag)
{
	return nullptr;
}

std::vector<GameObject*> GameObjectManager::GetGameObjectsByTag(std::string& _tag)
{
	return {};
}

std::vector<GameObject*>& GameObjectManager::GetGameObjects()
{
	return gameObjects;
}

void GameObjectManager::ClearGameObjects()
{
	gameObjectsToRemove.clear();

	for (auto gm : gameObjects)
	{
		gm->toBeDestroyed = true;
		gameObjectsToRemove.push_back(gm);
	}
	
}

GameObjectManager::GameObjectManager()
{

}

GameObjectManager::~GameObjectManager()
{
	// TO-DO remove and delete the remaining gameobjects
}
