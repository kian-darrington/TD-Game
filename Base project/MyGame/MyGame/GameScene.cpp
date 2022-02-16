#include "GameScene.h"
#include "Line.h"
#include "Enemy.h"
#include "Background.h"

const int vright = 0, vdown = 1, vleft = 2, vup = 3, right = 4, down = 5, left = 6, up = 7;

GameScene::GameScene() {
	sf::Vector2f pos;
	setLevelOne();
	pos.x = 0;
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
	BackgroundPtr background = std::make_shared<Background>();
	addGameObject(background);

	//visible path
	pos.x = 0;
	pos.y = GAME.getRenderWindow().getSize().y / 2 - 23;
	LinePtr vfirstLine = std::make_shared<Line>(vright, pos);
	addGameObject(vfirstLine);
	pos.x = 20;
	pos.y = GAME.getRenderWindow().getSize().y / 2 - 23;
	LinePtr filler1 = std::make_shared<Line>(vright, pos);
	addGameObject(filler1);
	pos.x = 240;
	pos.y = (GAME.getRenderWindow().getSize().y / 2) - 300;
	LinePtr vsecondLine = std::make_shared<Line>(vup, pos);
	addGameObject(vsecondLine);
	pos.x = 240;
	pos.y = (GAME.getRenderWindow().getSize().y / 2) - 310;
	LinePtr vthirdLine = std::make_shared<Line>(vright, pos);
	addGameObject(vthirdLine);
	pos.x = 320;
	pos.y = (GAME.getRenderWindow().getSize().y / 2) - 310;
	LinePtr filler2 = std::make_shared<Line>(vright, pos);
	addGameObject(filler2);
	pos.x = 540;
	pos.y = (GAME.getRenderWindow().getSize().y / 2) - 300;
	LinePtr vfourthLine = std::make_shared<Line>(vdown, pos);
	addGameObject(vfourthLine);
	pos.x = 540;
	pos.y = (GAME.getRenderWindow().getSize().y / 2);
	LinePtr vfifthLine = std::make_shared<Line>(vdown, pos);
	addGameObject(vfifthLine);
	pos.x = 540;
	pos.y = (GAME.getRenderWindow().getSize().y / 2) + 240;
	LinePtr vsixthLine = std::make_shared<Line>(vright, pos);
	addGameObject(vsixthLine);
	pos.x = 620;
	pos.y = (GAME.getRenderWindow().getSize().y / 2) + 240;
	LinePtr filler3 = std::make_shared<Line>(vright, pos);
	addGameObject(filler3);
	pos.x = 840;
	pos.y = (GAME.getRenderWindow().getSize().y / 2) - 10;
	LinePtr vLine7 = std::make_shared<Line>(vup, pos);
	addGameObject(vLine7);
	pos.x = 900;
	pos.y = (GAME.getRenderWindow().getSize().y / 2) - 10;
	LinePtr vLine8 = std::make_shared<Line>(vright, pos);
	addGameObject(vLine8);
}