#include "EnemySpawner.h"
#include "GameScene.h"
#include "Enemy.h"

const int SPACE_DELAY = 920;
const int ENEMY_NUMBER = 6;

// Enemy Number 1 = Cookie
// 2 = Cake
// 3 = Ice Cream
// 4 = Doughnut
// 5 = Crepe
// 6 = Brownie

void EnemySpawner::update(sf::Time& elapsed) {
	timer_ -= elapsed.asMilliseconds();
	difficultyTimer_ += elapsed.asMilliseconds();
	// Mediates difficulty changes so that the game gets harder
	if (difficultyTimer_ > 60000) {
		difficulty_++;
		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		scene.increaseDangerLevel();
		difficultyTimer_ = 0;
	}
	// Enemy spawner code
	if (timer_ < 1) {
		sf::Vector2f pos;
		pos.x = -64;
		pos.y = GAME.getRenderWindow().getSize().y / 2 - 15;
		int enemyType = 1;
		switch (difficulty_) {
		case 1:
			enemyType = 1;
			break;
		case 2:
			enemyType = 1 + rand() % 2; // 1-2 (inclusive), range for number generation
			break;
		case 3:
			enemyType = 1 + rand() % 3; // 1-3
			break;
		case 4:
			enemyType = 1 + rand() % 4; // 1-4
			break;
		case 5:
			enemyType = 2 + rand() % 3; // 2-4
			break;
		case 6:
			enemyType = 2 + rand() % 4; // 2-5
			break;
		case 7:
			enemyType = 3 + rand() % 3; // 3-5
			break;
		case 8:
			enemyType = 3 + rand() % 4; // 3-6
			break;
		case 9:
			enemyType = 4 + rand() % 3; // 4-6
			break;
		case 10:
			enemyType = 5 + rand() % 2; // 5-6
			break;
		default:
			enemyType = ENEMY_NUMBER; // 6
			break;
		}
		// Makes enemy
		EnemyPtr enemy1 = std::make_shared<Enemy>(pos, enemyType);
		GAME.getCurrentScene().addGameObject(enemy1);
		// This make the spawn delay shorter as the game progresses
		timer_ = SPACE_DELAY / (1 + (float)(difficulty_ / 5.0f));
	}
}