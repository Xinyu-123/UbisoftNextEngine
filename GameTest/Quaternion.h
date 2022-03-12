#pragma once
#include "Vector4.h"
#include "Mat4.h"

template<class T>
class Quaternion final
{
public:
	Quaternion()
		:
		scalar((T)1.0),
		imaginary((T)0.0, (T)0.0, (T)0.0)
	{}

	Quaternion(const T& _real_part, const Vector3<T>& _imaginary_part)
		:
		scalar(_real_part),
		imaginary(_imaginary_part)
	{}
	
	Quaternion(const T& _real_part, const T& _imag_1, const T& _imag_2, const T& _imag_3)
		:
		scalar(_real_part),
		imaginary({ _imag_1, _imag_2, _imag_3 })
	{}

	~Quaternion() = default;

	Quaternion(const Quaternion<T>& _other)
	{
		*this = _other;
	}

	#pragma region operators

	Quaternion<T>& operator=(const Quaternion<T>& _other)
	{
		scalar = _other.scalar;
		imaginary = _other.imaginary;
		return *this;
	}

	Quaternion<T> operator+(const Quaternion<T>& _other) const 
	{
		Quaternion<T> ret;
		ret.scalar = scalar + _other.scalar;
		ret.imaginary = imaginary + _other.imaginary;

		return ret;
	}
	
	Quaternion<T>& operator+=(const Quaternion<T>& _other)
	{
		return *this = *this + _other;
	}
		
	Quaternion<T> operator-(const Quaternion<T>& _other) const
	{
		Quaternion<T> ret;
		ret.scalar = scalar - _other.scalar;
		ret.imaginary = imaginary - _other.imaginary;

		return ret;
	}
	
	Quaternion<T>& operator-=(const Quaternion<T>& _other)
	{
		return *this = *this - _other;
	}

	Quaternion<T> operator*(const Quaternion<T>& _other) const
	{
	
		float ret_scalar = scalar * _other.scalar - imaginary.Dot(_other.imaginary);

		Vector3<T> ret_imaginary = _other.imaginary * scalar + imaginary * _other.scalar + imaginary.Cross(_other.imaginary);
			
		return Quaternion<T>(ret_scalar, ret_imaginary);
	}

	Quaternion<T>& operator*=(const Quaternion<T>& _other)
	{
		return *this = _other * *this;
	}

	Quaternion<T> operator*(const float _scale) const
	{
		Quaternion<T> ret;
		ret.scalar = scalar * _scale;
		ret.imaginary = imaginary * _scale;

		return ret;
	}

	Quaternion<T>& operator*=(const float _scale)
	{
		return *this = *this * _scale;
	}

	#pragma endregion


	float Magnitude() const
	{
		return sqrtf(MagnitudeSq());
	}

	float MagnitudeSq() const
	{
		return (scalar * scalar) + imaginary.MagnitudeSq();
	}

	void Normalize()
	{
		if (MagnitudeSq() == 0.0f)
			return;

		float magInverse = 1 / Magnitude();

		scalar *= magInverse;
		imaginary *= magInverse;
	}

	Quaternion<T> GetNormalized()
	{
		Quaternion<T> ret = *this;
		ret.Normalize();
		return ret;
	}
	
	void ConvertToUnitNormQuaternion() {

		float angle = scalar;
		imaginary.Normalize();
		scalar = cosf(angle * 0.5f);
		imaginary = imaginary * sinf(angle * 0.5f);

	}

	Quaternion<T> GetConjugate() const 
	{
		Quaternion<T> conjugate;
		conjugate.scalar = scalar;
		conjugate.imaginary = imaginary * (-1);

		return conjugate;
	}

	Quaternion<T> GetInverse() const
	{
		float absoluteValue = MagnitudeSq();
		absoluteValue = 1 / absoluteValue;

		Quaternion<T> ret = GetConjugate();

		ret.scalar *= absoluteValue;
		ret.imaginary *= absoluteValue;

		return ret;
	}
	
	Vector3<T> RotateAround(const Vector3<T>& _point) const
	{
		//convert our vector to a pure quaternion
		Quaternion<T> p(0, _point);

		//convert quaternion to unit norm quaternion
		Quaternion<T> q = *this;
			
		q.Normalize();
		//q.ConvertToUnitNormQuaternion();

		//Get the inverse of the quaternion
		Quaternion<T> qInverse = q.GetInverse();

		//rotate the quaternion
		Quaternion<T> rotatedVector = q * p * qInverse;

		//return the vector part of the quaternion
		return rotatedVector.imaginary;
	}
	
	Vector3<T> RotateAround(const Vector4<T>& _point) const
	{
		return RotateAround((Vector3<T>)_point);
	}

	// static helper functions

	static Quaternion<T> LookAt(const Vector3<T>& sourcePoint, const Vector3<T>& destPoint, const Vector3<T>& front, const Vector3<T>& up)
	{
		Vector3<float> toVector = (destPoint - sourcePoint).GetNormalized();

		//compute rotation axis
		Vector3<float> rotAxis = front.Cross(toVector).GetNormalized();
		if (rotAxis.MagnitudeSq() == 0)
			rotAxis = up;

		//find the angle around rotation axis
		float dot = front.Dot(toVector);
		float ang = std::acosf(dot);

		auto s = std::sinf(ang / 2);
		auto u = rotAxis.GetNormalized();

		return Quaternion<T>(std::cosf(ang / 2), u.x * s, u.y * s, u.z * s);
	}



	constexpr static Quaternion Identity()
	{
		Quaternion q;
		q.scalar = 1;
		q.imaginary = Vector3<float>();

		return q;
	}

	// angle in radians
	static Quaternion RotationQuaternion(float _angle, Vector3<T> _axis)
	{
		Quaternion<T> q(_angle, _axis);

		//convert quaternion to unit norm quaternion
		q.ConvertToUnitNormQuaternion();

		return q;
	}

	// not working
	constexpr static Mat4<float> RotationMatrix()
	{
		Vector3<float> i = imaginary;
		float scalar = scalar;
		return Mat4<float>();
		//return {
		//	1 - 2 * i.y * i.y - 2 * i.z * i.z,	2 * i.x * i.y - 2 * scalar * i.z,		2 * i.x * i.z + 2 * scalar * i.y,	0,
		//	2 * i.x * i.y + 2 * scalar * i.z,	1 - 2 * i.x * i.x - 2 * i.z * i.z,		2 * i.y * i.z - 2 * scalar * i.x,	0,
		//	2 * i.x * i.z - 2 * scalar * i.y,	2 * i.y * i.z + 2 * scalar * i.x,		1 - 2 * i.x * i.x - 2 * i.y * i.y,	0,
		//	0,									0,										0,									1
		//};
	}
	// to-do
	// Quaternion to euler angles
	// 
public:

	T scalar;
	Vector3<T> imaginary;
};