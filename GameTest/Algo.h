#pragma once

#include "Vector3.h"
#include "Vector4.h"
#include "Quaternion.h"
namespace Algo
{
	template<class T>
	inline constexpr Vector3<T> Lerp(const Vector3<T>& _start, const Vector3<T>& _end, float _t)
	{
		Vector3<T> ret;
		ret = _start + (_end - _start) * _t;

		return ret;
	}
	
	template<class T>
	inline constexpr Vector4<T> Lerp(const Vector4<T>& _start, const Vector4<T>& _end, float _t) 
	{
		Vector4<T> ret;
		ret = _start + (_end - _start) * _t;

		return ret;
	}
	

	// doesn't work
	template<class T>
	inline constexpr Quaternion<T> Slerp(const Quaternion<T>& _start, const Quaternion<T>& _end, float _t)
	{
		float dotproduct = _start.imaginary.Dot(_end.imaginary) + _start.scalar * _end.scalar;
		float theta, st, sut, sout, coeff1, coeff2;

		_t *= 0.5f;

		theta = (float)acos(dotproduct);
		if (theta < 0.0) theta = -theta;

		st = (float)sin(theta);
		sut = (float)sin(_t * theta);
		sout = (float)sin((1 - _t) * theta);

		if (st < 0.01f && st > -0.01f)
		{
			return _start;
		}
		else
		{
			coeff1 = sout / st;
			coeff2 = sut / st;
		}

		Quaternion<T> ret;
		ret.imaginary.x = coeff1 * _start.imaginary.x + coeff2 * _end.imaginary.x;
		ret.imaginary.y = coeff1 * _start.imaginary.y + coeff2 * _end.imaginary.y;
		ret.imaginary.z = coeff1 * _start.imaginary.z + coeff2 * _end.imaginary.z;
		ret.scalar = coeff1 * _start.scalar + coeff2 * _end.scalar;
		if (ret.Magnitude() == 0)
		{
			int a = 4;
			a += 34;
		}
		return ret.GetNormalized();
	}



};

