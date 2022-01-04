#pragma once
#include "Component.h"

class Camera : public Component
{
public:
	void Update(float _dt) override;
	void Cleanup() override;
};

