#include "stdafx.h"
#include "Mesh.h"
#include "GameObject.h"
#include "App/app.h"

void Mesh::Update(float _dt)
{
}

void Mesh::Cleanup()
{
	vertices.clear();
	indices.clear();
}



// Draw a wireframe of the mesh
void Mesh::Render(const Mat4<float>& _vp) const
{
	Transform* transform = gm->GetTransform();
	// create our world matrix
	Mat4<float> world;
	// Create the world-view-projection matrix
	Mat4<float> wvp = world * _vp;
}