#pragma once
#include "Singleton.h"

#include "UIComponent.h"
class UIManager : public Singleton<UIManager>
{
	DECLARE_SINGLETON(UIManager)
private:
	void Render();

	void AddUI(UIComponent* _uiObject) { uiObjects.push_back(_uiObject); }
	void RemoveUI(UIComponent* _uiObject)
	{
		uiObjects.erase(std::remove(uiObjects.begin(), uiObjects.end(), _uiObject), uiObjects.end());
	}

private:
	std::vector<UIComponent*> uiObjects;

	friend class GameEngine;
	friend class GameObject;
	friend class GameObjectManager;
};

