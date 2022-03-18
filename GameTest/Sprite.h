#pragma once

#include "UIComponent.h"

class CSimpleSprite;

class Sprite final : public UIComponent
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Sprite, UIComponent)
public:
	Sprite();

	void SetSprite(CSimpleSprite* _sprite);
	void SetStatic(bool _static) { static_sprite = _static; }
private:
	void Render() override;
	void Update(float _dt) override;
	void Cleanup() override;
	void Initialize() override;
private: 
	std::string filePath;
	bool static_sprite = false;

	CSimpleSprite* sprite = nullptr;
};

