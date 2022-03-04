#pragma once

#include "Vector3.h"
class Box
{
public:
	bool IsColliding(const Box& _other);
public:
	Vector3<float> pos = { 0.0f, 0.0f, 0.0f };
	float width = 1.0f;
	float height = 1.0f;
	float depth = 1.0f;
};

