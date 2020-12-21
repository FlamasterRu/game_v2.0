#pragma once
#include <SFML/Graphics.hpp>


enum MainMenuInput
{
	Exit,				// Выключить игру 0
	MainMenu,			// Отгрыть главное меню 1
	Settings,			// Открыть настройки 2
	LevelSelectionMenu,		// Открыть меню выбора уровня 3 (по кнопке StartGame в главном меню)
	StartGame
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


	// Кнопки управления
	Keyboard::Key keyToMoveRight;
	Keyboard::Key keyToMoveLeft;
	Keyboard::Key keyToMoveTop;
	Keyboard::Key keyToMoveBot;
	Keyboard::Key keyToFire;

	std::string stringKeyToMoveRight;
	std::string stringKeyToMoveLeft;
	std::string stringKeyToMoveTop;
	std::string stringKeyToMoveBot;
	std::string stringKeyToFire;





	//Для главного меню. Определение в файле main_menu.cpp
	void drawMainMenu();
	void mouseHandlingMainMenu(Mouse::Button button, int x, int y);


	//Для настроек. Определение в файле settings.cpp
	void drawSettings();
	void inputSettings();


	//Для меню выбора уровня. Определение в файле level_selection_menu.cpp
	void drawLevelSelectionMenu();
	void mouseHandlingLevelSelectionMenu(Mouse::Button button, int x, int y);





	
	Keyboard::Key returnPressedKey(Keyboard::Key key);		// Ввыводит предложение нажать клавишу, в случае отмены возвращает key
	Keyboard::Key pressedButtom();
	std::string keyboardKeyAsString(Keyboard::Key key);





public:

	Engine();

	int getUserMainMenuInput() const;



	void mainMenu();	// Окно главного меню
	void settings();	// Окно настроек
	void levelSelectionMenu();		// Окно выбора уровня (по кнопке StartGame)







};




