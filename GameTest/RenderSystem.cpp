#include "stdafx.h"
#include "RenderSystem.h"
#include "IRenderable.h"
void RenderSystem::Render()
{
	Mat4<float> _vp = Mat4<float>::Identity();
	for (auto r : renderables)
		r->Render(_vp);
}
