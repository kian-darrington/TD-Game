#include "Line.h"

Line::Line(int type, sf::Vector2f pos) {
	if (type == 0) {
		sprite_.setTexture(GAME.getTexture("Resources/visible-horizontal-line.png"));
		assignTag("right");
	}
	else if (type == 1) {
		sprite_.setTexture(GAME.getTexture("Resources/visible-vertical-line.png"));
		assignTag("down");
	}
	else if (type == 2) {
		sprite_.setTexture(GAME.getTexture("Resources/visible-horizontal-line.png"));
		assignTag("left");
	}
	else if (type == 3) {
		sprite_.setTexture(GAME.getTexture("Resources/visible-vertical-line.png"));
		assignTag("up");
	}
	else if (type == 4) {
		sprite_.setTexture(GAME.getTexture("Resourses/visible-corner.png"));
	}
	else if (type == 5) {
		sprite_.setTexture(GAME.getTexture("Resources/horizontal-line.png"));
		assignTag("right");
	}
	else if (type == 6){
		sprite_.setTexture(GAME.getTexture("Resources/horizontal-line.png"));
		assignTag("down");
	}
	else if (type == 7) {
		sprite_.setTexture(GAME.getTexture("Resources/horizontal-line.png"));
		assignTag("left");
	}
	else if (type == 8) {
		sprite_.setTexture(GAME.getTexture("Resources/horizontal-line.png"));
		assignTag("up");
	}
	else if (type == 9) {
		sprite_.setTexture(GAME.getTexture("Resourses/corner.png"));
	}
	sprite_.setPosition(pos);
}

void Line::draw() {
	GAME.getRenderWindow().draw(sprite_);
}

sf::FloatRect Line::getCollisionRect() {
	return sprite_.getGlobalBounds();
}

void Line::update(sf::Time& elapsed) {

}
void Line::changePos(sf::Vector2f pos) {
	sprite_.setPosition(pos);
}