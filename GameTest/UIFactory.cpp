#include "stdafx.h"
#include "UIFactory.h"

#include "GameObject.h"
#include "Sprite.h"
#include "Text.h"
#include "Transform.h"
#include "App/app.h";
#include "GameManager.h"
UIFactory::UIFactory()
{

}
UIFactory::~UIFactory()
{

}

GameObject* UIFactory::GetPlayerCrosshair()
{
	GameObject* crosshair = new GameObject();
	Sprite* sprite = new Sprite();
	sprite->SetSprite(crosshairSprite);
	sprite->SetStatic(true);
	crosshair->AddComponent(sprite);
	crosshair->GetTransform()->GetPosition() = { APP_VIRTUAL_WIDTH * 0.5f, APP_VIRTUAL_HEIGHT * 0.5f, 0 };
	crosshair->GetTransform()->GetScale().x = 0.5f;

	crosshair->SetName("Crosshair");

	return crosshair;
}

GameObject* UIFactory::GetPlayerLifeSprite()
{
	GameObject* life = new GameObject();
	Sprite* sprite = new Sprite();
	sprite->SetSprite(lifeSprite);
	sprite->SetStatic(true);
	life->GetTransform()->GetScale().x = 0.1f;

	life->AddComponent(sprite);

	life->SetTag("LifeSprite");

	return life;
}

GameObject* UIFactory::GetGameOverText()
{
	GameObject* gameOverTxt = new GameObject();
	Text* text = new Text();
	text->SetText("GameOver. Press R to Restart!");
	text->SetColor({ 1.0f, 1.0f, 1.0f });
	gameOverTxt->AddComponent(text);
	gameOverTxt->GetTransform()->GetPosition() = { APP_VIRTUAL_WIDTH * 0.5f - 100.0f, APP_VIRTUAL_HEIGHT * 0.5f + 50.0f, 0 };

	gameOverTxt->SetName("GameOver Text");

	return gameOverTxt;
}

GameObject* UIFactory::GetScoreText()
{
	GameObject* gameOverTxt = new GameObject();
	Text* text = new Text();
	text->SetText("Score: " + std::to_string(GameManager::Get().GetScore()));
	text->SetColor({ 1.0f, 1.0f, 1.0f });
	gameOverTxt->AddComponent(text);
	gameOverTxt->GetTransform()->GetPosition() = { APP_VIRTUAL_WIDTH * 0.5f - 100.0f, APP_VIRTUAL_HEIGHT - 50.0f, 0 };

	gameOverTxt->SetName("GameOver Text");

	return gameOverTxt;
}
