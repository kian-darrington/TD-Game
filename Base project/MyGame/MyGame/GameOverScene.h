#pragma once
#include "Engine/GameEngine.h"

class GameOverScene : public Scene {
public:
	GameOverScene(bool startScreen);
};

typedef std::shared_ptr<GameOverScene> GameOverScenePtr;