#include "stdafx.h"
#include "Camera.h"
#include "GameObject.h"
#include "Transform.h"
IMPLEMENT_DYNAMIC_CLASS(Camera)

void Camera::Update(float _dt)
{
}

void Camera::Cleanup()
{
}

void Camera::Initialize()
{
	Component::Initialize();

	if (perspective == true)
	{
		perspective_mat = Mat4<float>::ProjectionHFOV(fov, aspect_ratio, near_plane, far_plane);
	}
	else
	{
		perspective_mat = Mat4<float>::Identity();

	}
}

Mat4<float> Camera::GetViewPerspectiveMat() const
{
	const Transform* transform = go->PeekTransform();
	Mat4<float> vp;

	vp = transform->GetTransformMatrix();
	vp *= perspective_mat;

	return vp;
}
