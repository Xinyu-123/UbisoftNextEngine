#include "stdafx.h"
#include "UIManager.h"

UIManager::UIManager()
{

}

UIManager::~UIManager()
{

}

void UIManager::Render()
{
	for (auto uiObject : uiObjects)
	{
		uiObject->Render();
	}
}