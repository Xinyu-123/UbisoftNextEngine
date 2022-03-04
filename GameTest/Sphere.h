#pragma once


template <class T>
class Vector3;
class Sphere
{
	static void GetSphere(std::vector<Vector3<float>>& _verts, std::vector<unsigned short>& _indices, size_t lat_divides = 8, size_t long_divides = 36);
};

