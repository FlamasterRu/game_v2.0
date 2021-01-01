#pragma once
#include <SFML/Graphics.hpp>
#include "level.h"


enum class GameWindows
{
	Exit,				// Выключить игру 0
	MainMenu,			// Отгрыть главное меню 1
	Settings,			// Открыть настройки 2
	LevelSelectionMenu,		// Открыть меню выбора уровня 3 (по кнопке StartGame в главном меню)
	StartLevel		// Начать игру (по кнопке уровня)
};


const sf::Time TIME_DELAY_ESCAPE = sf::seconds(0.37f);   // чтобы сразу не выключить игру, так как пользователь не моментально отпускает кнопку Esc

using namespace sf;


class Engine
{
private:

	RenderWindow e_Window;

	Sprite e_BackgroundSprite;
	Texture e_BackgroundTexture;

	int e_UserMainMenuInput;		// пункт главного меню из MainMenuInput

	int e_ChangeWindow = false;		// флаг на смену окна (меню, игра, настройки)

	std::string e_SelectedLevel = "1";


	// Кнопки управления
	Keyboard::Key e_keyToMoveRight;
	Keyboard::Key e_keyToMoveLeft;
	Keyboard::Key e_keyToMoveTop;
	Keyboard::Key e_keyToMoveBot;
	Keyboard::Key e_keyToFire;

	std::string e_stringKeyToMoveRight;
	std::string e_stringKeyToMoveLeft;
	std::string e_stringKeyToMoveTop;
	std::string e_stringKeyToMoveBot;
	std::string e_stringKeyToFire;





	//Для главного меню. Определение в файле main_menu.cpp
	void drawMainMenu();
	void mouseHandlingMainMenu(Mouse::Button button, int x, int y);


	//Для настроек. Определение в файле settings.cpp
	void drawSettings();
	void inputSettings();
	Keyboard::Key returnPressedKey(Keyboard::Key key);		// Ввыводит предложение нажать клавишу, в случае отмены возвращает key
	Keyboard::Key pressedButtom();
	std::string keyboardKeyAsString(Keyboard::Key key);


	//Для меню выбора уровня. Определение в файле level_selection_menu.cpp
	void drawLevelSelectionMenu();
	void mouseHandlingLevelSelectionMenu(Mouse::Button button, int x, int y);


	//Для игрового окна. Определение в файле start_level.cpp
	void inputGameLevel(Level& level);
	void updateGameLevel(const float dtAsSeconds, Level& level);
	void drawGameLevel(Level& level);
	void drawGameOver(const int gameResult, Level& level);




public:

	Engine();

	int getUserMainMenuInput() const;



	void mainMenu();	// Окно главного меню
	void settings();	// Окно настроек
	void levelSelectionMenu();		// Окно выбора уровня (по кнопке StartGame)
	void startLevel();			// Окно уровня игры (уже сама суть игра)



};




