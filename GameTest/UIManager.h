#pragma once
#include "Singleton.h"
class UIManager : public Singleton<UIManager>
{
	DECLARE_SINGLETON(UIManager)
private:
	void Render();

	//void AddRenderable(IRenderable* _renderable) { renderables.push_back(_renderable); }
	//void RemoveRenderable(IRenderable* _renderable)
	//{
	//	renderables.erase(std::remove(renderables.begin(), renderables.end(), _renderable), renderables.end());
	//}

private:
	/*std::vector<IRenderable*> renderables;*/
	friend class GameEngine;
};

