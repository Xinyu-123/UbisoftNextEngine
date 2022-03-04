#pragma once
#include "Component.h"
#include "Vector3.h"
#include "Quaternion.h"
#include "Mat4.h"
class Transform final : public Component
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Transform, Component);
public:
	Transform();

	Vector3<float>& GetPosition() { return position; }
	const Vector3<float>&  PeekPosition() const {	return position; }
	
	Quaternion<float>& GetRotation() { return rotation; }
	const Quaternion<float>& PeekRotation() const { return rotation; }

	Vector3<float>& GetScale() { return scale; }
	const Vector3<float>& PeekScale() const { return scale; }

	template<class T>
	void TransformVertex(Vector4<T>& _vertex);
	template<class T>
	void TransformVertex(Vector3<T>& _vertex);
	template<class T>
	Mat4<T> GetTransformMatrix();


private:
	void Initialize() override;
	void Update(float _dt) override;
	void Cleanup() override;
	void Reset();
private:
	Vector3<float> position = { 0, 0, 0 };
	Quaternion<float> rotation = Quaternion<float>::Identity();
	Vector3<float> scale = { 1, 1, 1 };
};

template<class T>
inline void Transform::TransformVertex(Vector4<T>& _vertex)
{
	Vector3<T> v = (Vector3<T>)_vertex;
	TransformVertex(v);
	_vertex = v;
}

template<class T>
inline void Transform::TransformVertex(Vector3<T>& _vertex)
{
	_vertex.x *= scale.x;
	_vertex.y *= scale.y;
	_vertex.z *= scale.z;
	
	_vertex = rotation.RotateAround(_vertex);
	_vertex += position;
}

template<class T>
inline Mat4<T> Transform::GetTransformMatrix()
{
	return Mat4<T>();
}
