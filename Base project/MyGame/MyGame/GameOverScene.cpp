#include "GameOverScene.h"
#include "GameOverText.h"
#include "Enemy.h"

GameOverScene::GameOverScene() {
	GameOverTextPtr text = std::make_shared<GameOverText>();
	addGameObject(text);
}