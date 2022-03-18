#pragma once
#include "Singleton.h"

class GameObject;
class LevelFactory : public Singleton<LevelFactory>
{
	DECLARE_SINGLETON(LevelFactory)
public:
	GameObject* GetHubLevel();
	GameObject* GetLevel1();
	GameObject* GetLevel2();
	GameObject* GetLevel3();
	GameObject* GetLevel4();
};

