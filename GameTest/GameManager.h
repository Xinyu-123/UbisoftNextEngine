#pragma once
#include "Singleton.h"
#include "ComponentScript.h"
class GameManager : public Singleton<GameManager>, public ComponentScript
{
	DECLARE_SINGLETON(GameManager)
	DECLARE_DYNAMIC_DERIVED_CLASS(GameManager, ComponentScript)

public:
	void LoadSceneOne();
	GameObject* GetPlayer() { return playerGO; }
private:
	void Update(float _dt) override;
	void Cleanup() override;
	void Initialize();

private:
	GameObject* playerGO = nullptr;
};

