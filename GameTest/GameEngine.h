#pragma once

#include "Singleton.h"
class GameEngine : public Singleton<GameEngine>
{
	DECLARE_SINGLETON(GameEngine)
public:
	void Initialize();
	void Load(const char* _filename);
	void Update(float _dt);
	void Render();
	void Shutdown();
	void Restart();


	friend class Singleton<GameEngine>;
};

