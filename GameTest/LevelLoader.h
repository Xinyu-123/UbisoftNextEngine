#pragma once
#include "ComponentScript.h"
class LevelLoader : public ComponentScript
{
public:
	void LoadLevel();
	void SetLevel(int _level) { level = _level; }
private:
	void Update(float _dt) override;
	void Cleanup() override;
	void OnCollision(Collider* _other) override;
private:
	int level = 0;
};

