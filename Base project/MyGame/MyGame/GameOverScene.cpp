#include "GameOverScene.h"
#include "GameOverText.h"
#include "Enemy.h"

GameOverScene::GameOverScene(bool startScreen) {
	GameOverTextPtr text = std::make_shared<GameOverText>(startScreen);
	addGameObject(text);
}