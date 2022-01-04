#pragma once
#include <vector>

template<class T>
class Vector3
{
public:
	Vector3()
		:
		x(T(0)), y(T(0)), z(T(0))
	{ }

	Vector3(T _x, T _y, T _z)
		:
		x(_x), y(_y), z(_z)
	{ }

	T Dot(const Vector3& other)
	{
		return (x * other.x) + (y * other.y) + (z * other.z);
	}

	float Magnitude() const
	{
		return (x + y + z) * 0.333333333f;
	}

	// Operators
	Vector3 operator+(const Vector3& other) const 
	{
		return { x + other.x, y + other.y, z + other.z };
	}
	
	Vector3& operator+=(const Vector3& other)
	{
		*this = *this + other;
		return *this;
	}

	Vector3 operator-(const Vector3& other) const
	{
		return { x - other.x, y - other.y, z - other.z };
	}
	
	Vector3& operator-=(const Vector3& other)
	{
		*this = *this - other;
		return *this;
	}

	Vector3 operator*(const float scalar) const
	{
		return { x * (T)scalar, y * (T)scalar, z * (T)scalar };
	}	

	Vector3& operator*=(const float scalar)
	{
		*this = *this * other;
		return *this;
	}
	
	Vector3 operator/(const float scalar) const
	{
		return { x / (T)scalar, y / (T)scalar, z / (T)scalar };
	}
	
	Vector3& operator/=(const float scalar)
	{
		*this = *this / scalar;
		return *this;
	}

public:
	T x;
	T y;
	T z;
};

