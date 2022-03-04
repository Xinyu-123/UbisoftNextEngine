#pragma once
#include "Collider.h"
class MeshCollider : public Collider
{
	DECLARE_DYNAMIC_DERIVED_CLASS(MeshCollider, Collider)
public:
	void SetVertices(std::vector<Vector3<float>>& _verts) override;
private:
	void Update(float _dt) override;
	void Initialize() override;
	void Cleanup() override;
	void CalculateAABB() override;

};

