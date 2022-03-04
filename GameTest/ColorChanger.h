#pragma once
#include "ComponentScript.h"
class ColorChanger : public ComponentScript
{
private:
	virtual void Update(float _dt) override;
	virtual void Cleanup() override;

};

