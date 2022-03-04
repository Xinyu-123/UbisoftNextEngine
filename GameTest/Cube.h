#pragma once

template <class T>
class Vector3;
class Cube
{
public:
	static void GetCube(std::vector<Vector3<float>>& _verts, std::vector<unsigned short>& _indices, float length = 0.5f);
};

