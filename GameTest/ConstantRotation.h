#pragma once
#include "ComponentScript.h"

class Mesh;

class ConstantRotation : public ComponentScript
{
	DECLARE_DYNAMIC_DERIVED_CLASS(ConstantRotation, ComponentScript)
private:
	void Initialize() override;
	void Update(float _dt) override;
	void Cleanup() override;
private:
};

