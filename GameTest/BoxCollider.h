#pragma once

#include "Collider.h"

class BoxCollider final : public Collider
{
	DECLARE_DYNAMIC_DERIVED_CLASS(BoxCollider, Collider)

public:
	void SetDimensions(Vector3<float>& base, float width, float height, float depth);
	const Box& PeekDimensions() const { return dimensions; }
private:
	void Update(float _dt) override;
	void Initialize() override;
	void Cleanup() override;
	void CalculateAABB() override;

private:
	Box dimensions;
};

