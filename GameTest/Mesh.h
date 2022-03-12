#pragma once
#include "Component.h"
#include "IRenderable.h"
#include "Vector3.h"
#include "Color.h"

class Camera;

class Mesh : public Component, public IRenderable
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Mesh, Component)

public:
	Mesh();
	void SetVertices(const std::vector<Vector3<float>>& _vertices) { vertices = _vertices; }
	void SetIndices(const std::vector<unsigned short>& _indices) { indices = _indices; }
	void SetColor(const Color& c) { color = c; }
private:

	void Render(const Camera* _camera) const override;
	void Initialize() override;
	void Update(float _dt) override;
	void Cleanup() override;

private:
	std::vector<Vector3<float>> vertices;
	std::vector<unsigned short> indices;
	Color color;
};

