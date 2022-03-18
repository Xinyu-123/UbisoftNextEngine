#pragma once
#include "Singleton.h"
#include "ComponentScript.h"
#include "Text.h"

class Text;
class GameManager : public Singleton<GameManager>
{
	DECLARE_SINGLETON(GameManager)

public:
	void LoadScene(int _scene);
	void LoadScene();
	void LoadInitial();
	void IncreaseScore(int _score) 
	{ 
		score += _score; 
		ScoreText->SetText("Score: " + std::to_string(score));
	}
	int GetScore() const { return score; }
	GameObject* GetPlayer() { return playerGO; }
private:
	void Update(float _dt);
	void Cleanup();
	void Initialize();

	void LoadSceneHub();
	void LoadSceneOne();
	void LoadSceneTwo();
	void LoadSceneThree();
	void LoadSceneFour();
public:
	bool loadScene = false;
	int scene_to_load = 0;
	int lives = 3;
private:
	GameObject* playerGO = nullptr;
	Text* ScoreText = nullptr;
	int score = 0;

	std::mt19937 rng;
	std::uniform_real_distribution<float> rangeX;
	std::uniform_real_distribution<float> rangeY;
	std::uniform_real_distribution<float> rangeZ;

	friend class GameEngine;
};

