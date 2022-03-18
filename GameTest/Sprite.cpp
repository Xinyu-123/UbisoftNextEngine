#include "stdafx.h"
#include "Sprite.h"

#include "Transform.h"
#include "App/app.h"
#include "App/SimpleSprite.h"
IMPLEMENT_DYNAMIC_CLASS(Sprite)

Sprite::Sprite()
{

}


void Sprite::SetSprite(CSimpleSprite* _sprite)
{
	sprite = _sprite;
}

void Sprite::Render()
{
	sprite->SetPosition(transform->PeekPosition().x, transform->PeekPosition().y);
	sprite->SetScale(transform->PeekScale().x);

	sprite->Draw();

	
}

void Sprite::Update(float _dt)
{
}

void Sprite::Cleanup()
{
}

void Sprite::Initialize()
{
	UIComponent::Initialize();
	sprite->SetPosition(transform->PeekPosition().x, transform->PeekPosition().y);
	sprite->SetScale(transform->PeekScale().x);
}
