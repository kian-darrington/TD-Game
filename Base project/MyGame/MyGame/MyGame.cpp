#include "Engine/GameEngine.h"
#include "GameOverScene.h"

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 700;

const std::string WINDOW_TITLE = "Cookie Crush TD";
// The main
int main()
{
	// Seed the random number generator.
	srand((int)time(NULL));

	// Initialize the game.
	GAME.initialize(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

	// Create our scene.
	GameOverScenePtr scene = std::make_shared<GameOverScene>(true);
	GAME.setScene(scene);

	// Run the game loop.
	GAME.run();

	return 0;
}
