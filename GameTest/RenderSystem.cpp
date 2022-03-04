#include "stdafx.h"
#include "RenderSystem.h"
#include "IRenderable.h"
#include <iostream>

RenderSystem::RenderSystem()
	:
	camera(nullptr)
{

}

RenderSystem::~RenderSystem()
{

}

void RenderSystem::Render()
{
	// sort the renderables by z position?
	Mat4<float> _vp = Mat4<float>::Identity();

	for (auto r : renderables)
	{
		try
		{
			r->Render(_vp);
		}
		catch (const char* _msg)
		{
			//OutputDebugStringA((_msg));
			std::cout << _msg << std::endl;
		}
	}

	if (renderColliders == false)
		return;

	// render the colliders
}

void RenderSystem::AddCamera(Camera* _cam)
{
	if (camera != nullptr)
		return;

	camera = _cam;
}
