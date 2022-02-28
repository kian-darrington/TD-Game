#pragma once
#include "Engine/GameEngine.h"

class InGameText : public GameObject {
public:
	InGameText();
	void draw();
	void update(sf::Time& elapsed);
private:
	sf::Text text_;
};

typedef std::shared_ptr<InGameText> InGameTextPtr;