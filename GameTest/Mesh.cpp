#include "stdafx.h"
#include "Mesh.h"
#include "Transform.h"
#include "GameObject.h"
#include "App/app.h"
#include "Camera.h"

IMPLEMENT_DYNAMIC_CLASS(Mesh)

Mesh::Mesh()
{
	renderable = true;
}

void Mesh::Update(float _dt)
{
}

void Mesh::Cleanup()
{
	vertices.clear();
	indices.clear();
}



// Draw a wireframe of the mesh
// Coordinates are from -1 to 1 in the x and y
// 0 - fov limit in the z
void Mesh::Render(const Camera* _camera) const
{
	Transform* transform = go->GetTransform();


	// Transform all the vertices and draw lines based on the indices
	std::vector<Vector4<float>> verts(vertices.size());

	for (size_t i = 0; i < vertices.size(); ++i)
	{
		verts[i] = (Vector4<float>)vertices[i];
	}

	for (Vector4<float>& vert : verts)
	{
		transform->TransformVertex(vert);
		_camera->TransformVertex(vert);

		vert = _camera->PeekPerspectiveMat() * vert;
		// Z-Divide
		float z_inverse = 1 / vert.z;
		vert.x *= z_inverse;
		vert.y *= z_inverse;
		APP_NATIVE_TO_VIRTUAL_COORDS(vert.x, vert.y)
	}

	if (indices.size() % 2 != 0)
		throw "invalid indices size";

	for (size_t i = 0; i < indices.size(); i += 2)
	{
		float r, g, b;
		color.GetR(r);
		color.GetG(g);
		color.GetB(b);

		// don't draw if z is negative
		if (verts[indices[i]].z < 0 || verts[indices[i + 1]].z < 0)
			continue;

		App::DrawLine
		(
			verts[indices[i]].x, verts[indices[i]].y, // Vertex 1
			verts[indices[i + 1]].x, verts[indices[i + 1]].y, // Vertex 2
			r, g, b
		);
	}
}

void Mesh::Initialize()
{
	Component::Initialize();
}
