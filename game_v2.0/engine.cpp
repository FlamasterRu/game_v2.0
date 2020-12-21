#include "engine.h"








Engine::Engine() : e_UserMainMenuInput(1)
{
	ContextSettings setting;
	setting.antialiasingLevel = 8;

	e_Window.create(VideoMode::getDesktopMode(), "Game_v2", Style::Fullscreen, setting);
	e_Window.setVerticalSyncEnabled(true);


	keyToFire = Keyboard::Space;
	keyToMoveBot = Keyboard::S;
	keyToMoveLeft = Keyboard::A;
	keyToMoveRight = Keyboard::D;
	keyToMoveTop = Keyboard::W;

	stringKeyToMoveRight = "D";
	stringKeyToMoveLeft = "A";
	stringKeyToMoveTop = "W";
	stringKeyToMoveBot = "S";
	stringKeyToFire = "Space";
}








int Engine::getUserMainMenuInput() const
{
	return e_UserMainMenuInput;
}









