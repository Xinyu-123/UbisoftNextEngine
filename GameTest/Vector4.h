#pragma once
#include "Vector3.h"

template<class T>
class Vector4
{
public:
	Vector4()
		:
		x(T(0)), y(T(0)), z(T(0)), w(T(0))
	{ }

	Vector4(const T& _x, const T& _y, const T& _z, const T& _w)
		:
		x(_x), y(_y), z(_z), w(_w)
	{ }
	
	Vector4(const Vector3<T>& _vec3 , T _w = (T)1)
		:
		x(_vec3.x), y(_vec3.y), z(_vec3.z), w(_w)
	{ }

	T Dot(const Vector4& other)
	{
		return (x * other.x) + (y * other.y) + (z * other.z) + (w * other.w);
	}

	float Magnitude() const
	{
		return (x + y + z + w) * 0.25f;
	}

	// Operators
	Vector4 operator+(const Vector4& other) const
	{
		return { x + other.x, y + other.y, z + other.z, w + other.w };
	}

	Vector4& operator+=(const Vector4& other)
	{
		*this = *this + other;
		return *this;
	}

	Vector4 operator-(const Vector4& other) const
	{
		return { x - other.x, y - other.y, z - other.z, w - other.w };
	}

	Vector4& operator-=(const Vector4& other)
	{
		*this = *this - other;
		return *this;
	}

	Vector4 operator*(const float scalar) const
	{
		return { x * (T)scalar, y * (T)scalar, z * (T)scalar, w * (T)scalar };
	}

	Vector4& operator*=(const float scalar)
	{
		*this = *this * other;
		return *this;
	}

	Vector4 operator/(const float scalar) const
	{
		return { x / (T)scalar, y / (T)scalar, z / (T)scalar, w / (T)scalar };
	}

	Vector4& operator/=(const float scalar)
	{
		*this = *this / scalar;
		return *this;
	}

	explicit operator Vector3<T>() const
	{
		return { x, y, z };
	}

	


public:
	T x;
	T y;
	T z;
	T w;
};