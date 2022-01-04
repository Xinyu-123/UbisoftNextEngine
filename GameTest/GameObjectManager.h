#pragma once
#include "Singleton.h"

class GameObject;

class GameObjectManager final : public Singleton<GameObjectManager>
{
public:
	void Initialize();
	void Load();
		
	void Update(float _dt);

	void AddGameObject(GameObject* const _gm);
	void RemoveGameObject(GameObject* const _gm);
	void ClearGameObjects();
private:
	std::vector<GameObject*> gameObjects;
	std::vector<GameObject*> gameObjectsToRemove;
	friend class Singleton<GameObjectManager>;
};

