#pragma once
#include "Singleton.h"

class GameObject;

class GameObjectManager final : public Singleton<GameObjectManager>
{
	DECLARE_SINGLETON(GameObjectManager)

public:
	void Initialize();
	void Load();
		

	void AddGameObject(GameObject* const _gm);
	void AddGameObjectRunTime(GameObject* const _gm);
	void RemoveGameObject(GameObject* const _gm);
	GameObject* GetGameObjectByTag(const std::string& _tag);
	std::vector<GameObject*> GetGameObjectsByTag(const std::string& _tag);
	GameObject* GetGameObjectByName(const std::string& _name);
	std::vector<GameObject*> GetGameObjectsByName(const std::string& _name);
	std::vector<GameObject*>& GetGameObjects();
	void ClearGameObjects();
	
private:
	void Update(float _dt);

private:
	std::vector<GameObject*> gameObjects;
	std::vector<GameObject*> gameObjectsToRemove;
	std::vector<GameObject*> gameObjectsToAdd;

	friend class GameEngine;
	friend class Singleton<GameObjectManager>;

};

