#pragma once

template<class T>
class Vector4
{
public:
	Vector4()
		:
		x(T(0)), y(T(0)), z(T(0)), w(T(0))
	{ }

	Vector4(T _x, T _y, T _z, T _w)
		:
		x(_x), y(_y), z(_z), w(_w)
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

public:
	T x;
	T y;
	T z;
	T w;
};