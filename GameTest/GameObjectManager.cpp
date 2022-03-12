#include "stdafx.h"
#include "GameObjectManager.h"
#include "GameObject.h"
void GameObjectManager::Initialize()
{
	for (auto gm : gameObjects)
	{
		gm->Initialize();
	}
}

void GameObjectManager::Load()
{
}

void GameObjectManager::Update(float _dt)
{
	
	for (auto gm : gameObjects)
	{
		if(gm->IsActive())
			gm->Update(_dt);
	}

	for (auto gm : gameObjectsToRemove)
	{
		gm->Cleanup();
		gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), gm), gameObjects.end());
		// clear the other systems aswell

		delete gm;
	}

	gameObjectsToRemove.clear();

	for (auto gm : gameObjectsToAdd)
	{
		gameObjects.push_back(gm);
	}
	gameObjectsToAdd.clear();
}

void GameObjectManager::AddGameObject(GameObject* const _gm)
{
	gameObjects.push_back(_gm);
}

void GameObjectManager::AddGameObjectRunTime(GameObject* const _gm)
{
	gameObjectsToAdd.push_back(_gm);
	_gm->Initialize();
}

void GameObjectManager::RemoveGameObject(GameObject* const _gm)
{
	// gameobject is already set to be destroyed
	if (_gm->toBeDestroyed == true)
		return;

	gameObjectsToRemove.push_back(_gm);
	_gm->toBeDestroyed = true;
}

GameObject* GameObjectManager::GetGameObjectByTag(const std::string& _tag)
{
	for (GameObject* obj : gameObjects)
	{
		if (obj->tag == _tag)
			return obj;
	}

	return nullptr;
}

std::vector<GameObject*> GameObjectManager::GetGameObjectsByTag(const std::string& _tag)
{
	return {};
}

GameObject* GameObjectManager::GetGameObjectByName(const std::string& _name)
{
	for (GameObject* obj : gameObjects)
	{
		if (obj->name == _name)
			return obj;
	}

	return nullptr;
}

std::vector<GameObject*> GameObjectManager::GetGameObjectsByName(const std::string& _name)
{
	return std::vector<GameObject*>();
}

std::vector<GameObject*>& GameObjectManager::GetGameObjects()
{
	return gameObjects;
}

void GameObjectManager::ClearGameObjects()
{

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
