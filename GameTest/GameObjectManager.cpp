#include "stdafx.h"
#include "GameObjectManager.h"
#include "GameObject.h"
#include "Component.h"
#include "RenderSystem.h"
#include "UIManager.h"
#include "CollisionSystem.h"
#include "IRenderable.h"
#include "Camera.h"
#include "Component.h"
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

void GameObjectManager::AddComponentRunTime(GameObject* const _go, Component* const _component)
{
	componentsToAdd.push_back({ _go, _component });
}

void GameObjectManager::RemoveComponent(Component* const _component)
{
	componentsToRemove.push_back(_component);
}

void GameObjectManager::Update(float _dt)
{
	
	for (auto gm : gameObjects)
	{
		if(gm->IsActive())
			gm->Update(_dt);
	}

	for (auto component : componentsToRemove)
	{
		component->Cleanup();
		component->go->RemoveComponent(component);
	}
	componentsToRemove.clear();

	for (auto& componentPair : componentsToAdd)
	{
		componentPair.first->AddComponent(componentPair.second);
	}
	componentsToAdd.clear();

	for (auto gm : gameObjectsToRemove)
	{
		gm->Cleanup();
		gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), gm), gameObjects.end());

		delete gm;
	}
	gameObjectsToRemove.clear();

	for (auto gm : gameObjectsToAdd)
	{
		gm->Initialize();
		AddGameObject(gm);
	}
	gameObjectsToAdd.clear();
	
}

void GameObjectManager::AddGameObject(GameObject* const _gm)
{
	for (auto pair : _gm->components)
	{
		for (auto _component : pair.second)
		{

			if (_component->renderable == true)
			{
				// Create a macro to cast Component to derived class to IRenderable
				IRenderable* r = dynamic_cast<IRenderable*>(_component);
				if (r != nullptr)
					RenderSystem::Get().AddRenderable(r);
			}


			if (_component->isA(Camera::getClassHashCode()))
			{
				RenderSystem::Get().AddCamera(static_cast<Camera*>(_component));
			}

			if (_component->isA(UIComponent::getClassHashCode()))
			{
				UIManager::Get().AddUI(static_cast<UIComponent*>(_component));
			}


			if (_component->isA(Collider::getClassHashCode()))
			{
				Collider* c = static_cast<Collider*>(_component);
				CollisionSystem::Get().AddCollider(c);
			}
		}
	}
	gameObjects.push_back(_gm);
}

void GameObjectManager::AddGameObjectRunTime(GameObject* const _gm)
{
	gameObjectsToAdd.push_back(_gm);
	
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

	for (auto gm : gameObjectsToRemove)
	{
		gm->Cleanup();
		gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), gm), gameObjects.end());

		delete gm;
	}

	gameObjectsToRemove.clear();

	for (auto gm : gameObjects)
	{
		gm->toBeDestroyed = true;
		gameObjectsToRemove.push_back(gm);
	}

	for (auto gm : gameObjectsToRemove)
	{
		gm->Cleanup();
		gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), gm), gameObjects.end());

		delete gm;
	}

	gameObjectsToRemove.clear();
	gameObjects.clear();
}

GameObjectManager::GameObjectManager()
{

}

GameObjectManager::~GameObjectManager()
{
	// TO-DO remove and delete the remaining gameobjects
}
