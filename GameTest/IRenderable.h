#pragma once
#include "Mat4.h"

class Camera;
class IRenderable
{
private:
	virtual void Render(const Camera* _camera) const = 0;

	friend class RenderSystem;
	friend class GameObject;
};

