#pragma once
#include "Singleton.h"
#include "App/app.h"

class GameObject;
class UIFactory : public Singleton<UIFactory>
{
	DECLARE_SINGLETON(UIFactory)
public:
	GameObject* GetPlayerCrosshair();
	GameObject* GetPlayerLifeSprite();
	GameObject* GetGameOverText();
	GameObject* GetScoreText();
public:
	CSimpleSprite* lifeSprite = App::CreateSprite("../Assets/Images/Life3.bmp", 1, 1);
	CSimpleSprite* crosshairSprite = App::CreateSprite("../Assets/Images/Crosshair2.bmp", 1, 1);

};
