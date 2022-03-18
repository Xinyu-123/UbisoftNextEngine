#pragma once
#include "Singleton.h"

class GameObject;
class EnemyFactory : public Singleton<EnemyFactory>
{
	DECLARE_SINGLETON(EnemyFactory)
public:
	GameObject* GetStandardTuret();
	GameObject* GetStandardEnemyShip();
	GameObject* GetPredictionTurret();
};
