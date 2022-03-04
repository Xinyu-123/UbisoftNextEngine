#include "stdafx.h"
#include "Cube.h"
#include "Vector3.h"

void Cube::GetCube(std::vector<Vector3<float>>& _verts, std::vector<unsigned short>& _indices, float length)
{
	// set up the cube
	_verts.clear();
	_indices.clear();

	float half_length = length * 0.5f;


	_verts = {
		{-half_length, -half_length, -half_length},
		{half_length, -half_length, -half_length},
		{-half_length, half_length, -half_length},
		{half_length, half_length, -half_length},
		{-half_length, -half_length, half_length},
		{half_length, -half_length, half_length},
		{-half_length, half_length, half_length},
		{half_length, half_length, half_length},
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