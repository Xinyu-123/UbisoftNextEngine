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

	Vector3<float> GetForward() const
	{
		return rotation.RotateAround({ 0, 0, 1 });
	}
	
	Vector3<float> GetRight() const
	{
		return rotation.RotateAround({ 1, 0, 0 });
	}
	
	Vector3<float> GetUp() const
	{
		return rotation.RotateAround({ 0, 1, 0 });
	}

	template<class T>
	void TransformVertex(Vector4<T>& _vertex) const;
	template<class T>
	void TransformVertex(Vector3<T>& _vertex) const;


	Mat4<float> GetTransformMatrix() const;


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
inline void Transform::TransformVertex(Vector4<T>& _vertex) const
{
	Vector3<T> v = (Vector3<T>)_vertex;
	TransformVertex(v);
	_vertex = v;
}

template<class T>
inline void Transform::TransformVertex(Vector3<T>& _vertex) const
{
	_vertex.x *= scale.x;
	_vertex.y *= scale.y;
	_vertex.z *= scale.z;
	
	_vertex = rotation.RotateAround(_vertex);
	_vertex += position;
}

