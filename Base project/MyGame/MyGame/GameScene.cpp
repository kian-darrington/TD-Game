#include "GameScene.h"
#include "Line.h"
#include "Enemy.h"

const int vright = 0, vdown = 1, vleft = 2, vup = 3, right = 4, down = 5, left = 6, up = 7;

GameScene::GameScene() {
	sf::Vector2f pos;
	setLevelOne();
	pos.x = 32;
	pos.y = GAME.getRenderWindow().getSize().y / 2 - 5;
	EnemyPtr enemy1 = std::make_shared<Enemy>(pos);
	addGameObject(enemy1);
}

void GameScene::setLevelOne() {
	sf::Vector2f pos;
	pos.x = 0;
	pos.y = GAME.getRenderWindow().getSize().y / 2;
	LinePtr firstLine = std::make_shared<Line>(right, pos);
	addGameObject(firstLine);
	pos.x = 300;
	pos.y = (GAME.getRenderWindow().getSize().y / 2) - 300;
	LinePtr secondLine = std::make_shared<Line>(up, pos);
	addGameObject(secondLine);
	pos.x = 300;
	pos.y = (GAME.getRenderWindow().getSize().y / 2) - 300;
	LinePtr thirdLine = std::make_shared<Line>(right, pos);
	addGameObject(thirdLine);
	pos.x = 600;
	pos.y = (GAME.getRenderWindow().getSize().y / 2) - 300;
	LinePtr fourthLine = std::make_shared<Line>(down, pos);
	addGameObject(fourthLine);
	pos.x = 600;
	pos.y = (GAME.getRenderWindow().getSize().y / 2);
	LinePtr fifthLine = std::make_shared<Line>(down, pos);
	addGameObject(fifthLine);
	pos.x = 600;
	pos.y = (GAME.getRenderWindow().getSize().y / 2) + 300;
	LinePtr sixthLine = std::make_shared<Line>(right, pos);
	addGameObject(sixthLine);
	pos.x = 900;
	pos.y = (GAME.getRenderWindow().getSize().y / 2);
	LinePtr Line7 = std::make_shared<Line>(up, pos);
	addGameObject(Line7);
	pos.x = 900;
	pos.y = (GAME.getRenderWindow().getSize().y / 2);
	LinePtr Line8 = std::make_shared<Line>(right, pos);
	addGameObject(Line8);
}