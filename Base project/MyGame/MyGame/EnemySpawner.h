#pragma once
#include "Engine/GameEngine.h"

class EnemySpawner : public GameObject {
public:
	void update(sf::Time& elapsed);
private:
	int timer_ = 0;
	int difficultyTimer_ = 0;
	int difficulty_ = 1;
};

typedef std::shared_ptr<EnemySpawner> EnemySpawnerPtr;