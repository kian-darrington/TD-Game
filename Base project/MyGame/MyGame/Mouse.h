#pragma once
#include "Engine/GameEngine.h"

class Cursor : public GameObject {
public:
	Cursor();
	void draw();
	void update(sf::Time& elapsed);
	sf::FloatRect getCollisionRect();
private:
	sf::Sprite sprite_;
};

typedef std::shared_ptr<Cursor> CursorPtr;