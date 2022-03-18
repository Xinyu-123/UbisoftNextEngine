#include "stdafx.h"
#include "Text.h"
#include "App/app.h"
#include "Transform.h"

IMPLEMENT_DYNAMIC_CLASS(Text)

void Text::Update(float _dt)
{
}

void Text::Render()
{
	float r, g, b;
	color.GetR(r);
	color.GetG(g);
	color.GetB(b);

	App::Print(transform->PeekPosition().x, transform->PeekPosition().y, text.c_str(), r, g, b, font);
}

void Text::Cleanup()
{
}
