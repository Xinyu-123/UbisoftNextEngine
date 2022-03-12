#pragma once
#include "Singleton.h"

class GameObject;
class ProjectileFactory : public Singleton<ProjectileFactory>
{
	DECLARE_SINGLETON(ProjectileFactory)
public:
	GameObject* GetPlayerProjectile();
	GameObject* GetEnemyProjectile();

};

