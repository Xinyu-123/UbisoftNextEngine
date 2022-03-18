#pragma once

#include "Component.h"
class UIComponent : public Component
{
	DECLARE_ABSTRACT_DERIVED_CLASS(UIComponent, Component)

protected:
	UIComponent();
	virtual void Render() = 0;

private:
	friend class UIManager;
};

