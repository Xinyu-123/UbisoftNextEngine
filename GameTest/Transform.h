#pragma once
#include "Component.h"
#include "Vector3.h"
#include "Quaternion.h"
class Transform final : public Component
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Transform, Component);
public:
	Transform();

	inline Vector3<float>& GetPosition() { return position; }
	inline const Vector3<float>& const PeekPosition() { return position; }
	
	inline Quaternion<float>& GetRotation() { return rotation; }
	inline const Quaternion<float>& const PeekRotation() { return rotation; }

	inline Vector3<float>& GetScale() { return scale; }
	inline const Vector3<float>& const PeekScale() { return scale; }

	void Initialize() override;
	void Update(float _dt) override;
	void Cleanup() override;
	void Reset();
private:
	Vector3<float> position;
	Quaternion<float> rotation;
	Vector3<float> scale = { 1, 1, 1 };
};

