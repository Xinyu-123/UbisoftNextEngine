#pragma once
#include "Singleton.h"

class GameObject;
class PlayerFactory : public Singleton<PlayerFactory>
{
	DECLARE_SINGLETON(PlayerFactory)
public:
	GameObject* GetPlayer();
};

