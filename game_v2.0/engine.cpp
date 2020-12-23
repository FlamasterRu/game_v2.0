#include "engine.h"








Engine::Engine() : e_UserMainMenuInput(1)
{
	ContextSettings setting;
	setting.antialiasingLevel = 8;

	e_Window.create(VideoMode::getDesktopMode(), "Game_v2", Style::Fullscreen, setting);
	e_Window.setVerticalSyncEnabled(true);


	e_keyToFire = Keyboard::Space;
	e_keyToMoveBot = Keyboard::S;
	e_keyToMoveLeft = Keyboard::A;
	e_keyToMoveRight = Keyboard::D;
	e_keyToMoveTop = Keyboard::W;

	e_stringKeyToMoveRight = "D";
	e_stringKeyToMoveLeft = "A";
	e_stringKeyToMoveTop = "W";
	e_stringKeyToMoveBot = "S";
	e_stringKeyToFire = "Space";
}








int Engine::getUserMainMenuInput() const
{
	return e_UserMainMenuInput;
}









