#pragma once

class IRenderable;

class RenderSystem
{
public:
private:
	void Render();
private:
	std::vector<IRenderable*> renderables;
	friend class GameEngine;
};

