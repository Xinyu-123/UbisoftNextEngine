#pragma once
#include "Mat4.h"

class IRenderable
{
private:
	virtual void Render(const Mat4<float>& _vp) const = 0;

	friend class RenderSystem;
};

