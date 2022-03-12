#pragma once
#include "Component.h"
#include "Mat4.h"

#include "Transform.h"

class Camera : public Component
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Camera, Component)
public:
	template<class T>
	void TransformVertex(Vector4<T>& _vertex) const;
	template<class T>
	void TransformVertex(Vector3<T>& _vertex) const;

	const Mat4<float>& PeekPerspectiveMat() const { return perspective_mat; }
private:
	void Update(float _dt) override;
	void Cleanup() override;
	void Initialize() override;

	Mat4<float> GetViewPerspectiveMat() const;
private:
	bool perspective = true;
	float fov = 120.0f;
	float aspect_ratio = 0.75f;
	float near_plane = 0.1f;
	float far_plane = 10.0f;
	Mat4<float> perspective_mat;

	friend class RenderSystem;
};

template<class T>
inline void Camera::TransformVertex(Vector4<T>& _vertex) const
{
	Vector3<T> v = (Vector3<T>)_vertex;
	TransformVertex(v);
	_vertex = v;
}

template<class T>
inline void Camera::TransformVertex(Vector3<T>& _vertex) const
{
	_vertex -= go->PeekTransform()->PeekPosition();
	_vertex.x /= go->PeekTransform()->PeekScale().x;
	_vertex.y /= go->PeekTransform()->PeekScale().y;
	_vertex.z /= go->PeekTransform()->PeekScale().z;

	_vertex = go->PeekTransform()->PeekRotation().GetInverse().RotateAround(_vertex);
}
