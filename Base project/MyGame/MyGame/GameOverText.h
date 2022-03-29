#pragma once
#include "Engine/GameEngine.h"

class GameOverText : public GameObject {
public:
	GameOverText(bool startScreen, int score);
	void draw();
	void update(sf::Time& elapsed);
private:
	sf::Text text_;
	bool startScreen_;
};

typedef std::shared_ptr<GameOverText> GameOverTextPtr;