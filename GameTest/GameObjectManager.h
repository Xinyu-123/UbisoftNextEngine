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
	void RemoveGameObject(GameObject* const _gm);
	GameObject* GetGameObjectByTag(std::string& _tag);
	std::vector<GameObject*> GetGameObjectsByTag(std::string& _tag);
	std::vector<GameObject*>& GetGameObjects();
	void ClearGameObjects();
	
private:
	void Update(float _dt);

private:
	std::vector<GameObject*> gameObjects;
	std::vector<GameObject*> gameObjectsToRemove;

	friend class GameEngine;
	friend class Singleton<GameObjectManager>;

};

