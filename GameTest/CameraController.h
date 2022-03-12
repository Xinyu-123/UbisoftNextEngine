#pragma once

#include "ComponentScript.h"

class Camera;
class CameraController final : public ComponentScript
{
	DECLARE_DYNAMIC_DERIVED_CLASS(CameraController, ComponentScript)

public:

private:
	void Update(float _dt) override;
	void Initialize() override;
	void Cleanup() override;

private:
	Camera* camera;
	Transform* transform;
	float lastMouseX = 0;
	float lastMouseY = 0;

	bool isGrounded = true;
	float velocity = 0.0f;
	float moveSpeed = 2.0f;
};

