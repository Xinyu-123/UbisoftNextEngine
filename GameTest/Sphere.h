#pragma once


template <class T>
class Vector3;
class Sphere
{
public:
	static void GetSphere(std::vector<Vector3<float>>& _verts, std::vector<unsigned short>& _indices, float radius = 1.0f, size_t lat_divides = 16, size_t long_divides = 32);

};

