#include "stdafx.h"
#include "Prism.h"
#include "Vector3.h"

void Prism::GetPrism(std::vector<Vector3<float>>& _verts, std::vector<unsigned short>& _indices, int faceEdges, float width, float length)
{
	// set up the prism
	_verts.clear();
	_indices.clear();


	// Only do the Rectangular Prism for now
	if (faceEdges != 4)
		return;


	float half_width = width * 0.5f;
	float half_length = length * 0.5f;


	_verts = {
		{-half_width, -half_width, -half_length},
		{half_width, -half_width, -half_length},
		{-half_width, half_width, -half_length},
		{half_width, half_width, -half_length},
		{-half_width, -half_width, half_length},
		{half_width, -half_width, half_length},
		{-half_width, half_width, half_length},
		{half_width, half_width, half_length},
	};

	_indices =
	{
		0, 1, // Front Face
		0, 2,
		1, 3,
		2, 3,
		0, 4, // Front face to Back face
		1, 5,
		2, 6,
		3, 7,
		4, 5, // Back Face
		4, 6,
		5, 7,
		6, 7
	};
}
