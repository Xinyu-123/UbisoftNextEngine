#pragma once

template <class T>
class Vector3;
class Prism
{
public:
	static void GetPrism(std::vector<Vector3<float>>& _verts, std::vector<unsigned short>& _indices, int faceEdges = 4, float width = 0.5f, float length = 1.0f);

};


