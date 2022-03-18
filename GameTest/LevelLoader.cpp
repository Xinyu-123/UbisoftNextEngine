#include "stdafx.h"
#include "LevelLoader.h"
#include "GameManager.h"
#include "Collider.h"
#include "GameObject.h"

void LevelLoader::LoadLevel()
{
	GameManager::Get().LoadScene(level);
}

void LevelLoader::Update(float _dt)
{
}

void LevelLoader::Cleanup()
{
}

void LevelLoader::OnCollision(Collider* _other)
{
	if (_other->GetGameObject()->GetName() == "Player")
	{
		LoadLevel();
	}
}
