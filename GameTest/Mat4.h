#pragma once
#include <vector>
#include "Vector4.h"
template<class T>
class Mat4
{
public:
	Mat4()
		:
		data(4)
	{ }

	Mat4 operator*(const Mat4& _other)
	{
		Mat4 ret;

		for (int i = 0; i < 4; ++i)
		{
			ret.data[i].x = data[0].x * _other.data[i].x + data[1].x * _other.data[i].y + data[2].x * _other.data[i].z + data[3].x * _other.data[i].w;
			ret.data[i].y = data[0].y * _other.data[i].x + data[1].y * _other.data[i].y + data[2].y * _other.data[i].z + data[3].y * _other.data[i].w;
			ret.data[i].z = data[0].z * _other.data[i].x + data[1].z * _other.data[i].y + data[2].z * _other.data[i].z + data[3].z * _other.data[i].w;
			ret.data[i].w = data[0].w * _other.data[i].x + data[1].w * _other.data[i].y + data[2].w * _other.data[i].z + data[3].w * _other.data[i].w;

		}

		return ret;
	}

	static Mat4 Identity()
	{
		Mat4 ret;
		ret.data[0].x = (T)1;
		ret.data[1].y = (T)1;
		ret.data[2].z = (T)1;
		ret.data[3].w = (T)1;
		return ret;
	}
public:
	std::vector<Vector4<T>> data;
};