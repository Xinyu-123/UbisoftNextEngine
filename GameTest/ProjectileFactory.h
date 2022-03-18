#pragma once
#include "Singleton.h"
#include "Color.h"

class GameObject;
class ProjectileFactory : public Singleton<ProjectileFactory>
{
	DECLARE_SINGLETON(ProjectileFactory)
public:
	GameObject* GetPlayerProjectile();
	GameObject* GetEnemyProjectile(float _radius = 0.3f, const Color& _c = { 1.0f, 0.0f, 0.0f });

};

