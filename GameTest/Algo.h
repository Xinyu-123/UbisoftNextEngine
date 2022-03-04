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
	
	template<class T>
	inline constexpr Quaternion<T> Slerp(const Quaternion<T>& _start, const Quaternion<T>& _end, float _t)
	{
		// No idea how to do this yet
	}



};

