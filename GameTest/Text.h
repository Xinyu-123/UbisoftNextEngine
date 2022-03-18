#pragma once
#include "UIComponent.h"
#include "Color.h"
#include "App/app.h"
class Text : public UIComponent
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Text, UIComponent)

public:
	void SetText(const std::string& _txt) { text = _txt; }
	const std::string& GetText() const { return text; }

	void SetColor(const Color& _c) { color = _c; }
	const Color& GetColor() { return color; }
private:
	void Update(float _dt) override;
	void Render() override;
	void Cleanup() override;

private:
	std::string text = "";
	Color color;
	void* font = GLUT_BITMAP_HELVETICA_18;
};

