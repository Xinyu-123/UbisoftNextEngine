#pragma once
#include "Singleton.h"


class IRenderable;
class Camera;
class RenderSystem : public Singleton<RenderSystem>
{
	DECLARE_SINGLETON(RenderSystem)

private:
	void Render();

	void AddRenderable(IRenderable* _renderable) { renderables.push_back(_renderable); }
	void RemoveRenderable(IRenderable* _renderable) 
	{
		renderables.erase(std::remove(renderables.begin(), renderables.end(), _renderable), renderables.end());
	}

	void AddCamera(Camera* _cam);
private:
	std::vector<IRenderable*> renderables;
	Camera* camera;

	bool renderColliders = false;

	friend class GameEngine;
	friend class GameObject;
};

