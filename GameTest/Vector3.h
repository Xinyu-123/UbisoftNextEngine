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

	T Dot(const Vector3<T>& _other) const
	{
		return (x * _other.x) + (y * _other.y) + (z * _other.z);
	}

	Vector3<T> Cross(const Vector3<T>& _other) const
	{
		Vector3<T> ret;
		ret.x = (y * _other.z) - (z * _other.y);
		ret.y = (z * _other.x) - (x * _other.z);
		ret.z = (x * _other.y) - (y * _other.x);
		return ret;
	}

	float Magnitude() const
	{
		return sqrt(MagnitudeSq());
	}

	float MagnitudeSq() const
	{
		return (x * x) + (y * y) + (z * z);
	}

	void Normalize()
	{
		if (MagnitudeSq() == (T)0)
			return;

		float magInverse = 1 / Magnitude();

		x *= magInverse;
		y *= magInverse;
		z *= magInverse;
	}

	Vector3<float> GetNormalized() const
	{
		if (MagnitudeSq() == (T)0)
			throw "Tried to normalize a Vector3 with magnitude 0";

		Vector3<float> ret = *this;

		float magInverse = 1 / Magnitude();

		ret.x *= magInverse;
		ret.y *= magInverse;
		ret.z *= magInverse;
		return ret;
	}

	// Operators
	Vector3 operator+(const Vector3& _other) const 
	{
		return { x + _other.x, y + _other.y, z + _other.z };
	}
	
	Vector3& operator+=(const Vector3& _other)
	{
		*this = *this + _other;
		return *this;
	}

	Vector3 operator-(const Vector3& _other) const
	{
		return { x - _other.x, y - _other.y, z - _other.z };
	}
	
	Vector3& operator-=(const Vector3& _other)
	{
		*this = *this - _other;
		return *this;
	}

	Vector3 operator*(const float _scalar) const
	{
		return { x * (T)_scalar, y * (T)_scalar, z * (T)_scalar };
	}	

	Vector3& operator*=(const float _scalar)
	{
		*this = *this * _scalar;
		return *this;
	}
	
	Vector3 operator/(const float _scalar) const
	{
		return { x / (T)_scalar, y / (T)_scalar, z / (T)_scalar };
	}
	
	Vector3& operator/=(const float _scalar)
	{
		*this = *this / _scalar;
		return *this;
	}

	bool operator==(const Vector3<T>& _other)
	{
		return x == _other.x && y == _other.y && z == _other.z;
	}

	// static helper functions
	static Vector3<T> Up()
	{
		return { 0, 1, 0 };
	}
	
	static Vector3<T> Forward()
	{
		return { 0, 0, 1 };
	}
	
	static Vector3<T> Right()
	{
		return { 1, 0, 0 };
	}
public:
	T x;
	T y;
	T z;
};

