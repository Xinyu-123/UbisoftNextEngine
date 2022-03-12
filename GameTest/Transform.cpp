#include "stdafx.h"
#include "Transform.h"

IMPLEMENT_DYNAMIC_CLASS(Transform);

Transform::Transform()
{

}

// Not Complete, Do not Call
Mat4<float> Transform::GetTransformMatrix() const
{
	Mat4<float> ret;
	//ret = Mat4<float>::RotationMatrix(rotation);

	ret.data[0].x *= scale.x;
	ret.data[1].y *= scale.y;
	ret.data[2].z *= scale.z;

	ret.data[0].w = position.x;
	ret.data[1].w = position.y;
	ret.data[2].w = position.z;


	return ret;
}

void Transform::Initialize()
{
}

void Transform::Update(float _dt)
{
}

void Transform::Cleanup()
{
}

void Transform::Reset()
{
}

