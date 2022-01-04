#pragma once
#include "Component.h"
#include "IRenderable.h"
#include "Vector3.h"
class Mesh : public Component, public IRenderable
{
public:
	void Update(float _dt) override;
	void Cleanup() override;
private:
	void Render(const Mat4<float>& _vp) const override;

private:
	std::vector<Vector3<float>> vertices;
	std::vector<size_t> indices;
};

