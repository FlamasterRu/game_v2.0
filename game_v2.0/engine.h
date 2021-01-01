#pragma once
#include <SFML/Graphics.hpp>
#include "level.h"


enum class GameWindows
{
	Exit,				// ��������� ���� 0
	MainMenu,			// ������� ������� ���� 1
	Settings,			// ������� ��������� 2
	LevelSelectionMenu,		// ������� ���� ������ ������ 3 (�� ������ StartGame � ������� ����)
	StartLevel		// ������ ���� (�� ������ ������)
};


const sf::Time TIME_DELAY_ESCAPE = sf::seconds(0.37f);   // ����� ����� �� ��������� ����, ��� ��� ������������ �� ����������� ��������� ������ Esc

using namespace sf;


class Engine
{
private:

	RenderWindow e_Window;

	Sprite e_BackgroundSprite;
	Texture e_BackgroundTexture;

	int e_UserMainMenuInput;		// ����� �������� ���� �� MainMenuInput

	int e_ChangeWindow = false;		// ���� �� ����� ���� (����, ����, ���������)

	std::string e_SelectedLevel = "1";


	// ������ ����������
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





	//��� �������� ����. ����������� � ����� main_menu.cpp
	void drawMainMenu();
	void mouseHandlingMainMenu(Mouse::Button button, int x, int y);


	//��� ��������. ����������� � ����� settings.cpp
	void drawSettings();
	void inputSettings();
	Keyboard::Key returnPressedKey(Keyboard::Key key);		// �������� ����������� ������ �������, � ������ ������ ���������� key
	Keyboard::Key pressedButtom();
	std::string keyboardKeyAsString(Keyboard::Key key);


	//��� ���� ������ ������. ����������� � ����� level_selection_menu.cpp
	void drawLevelSelectionMenu();
	void mouseHandlingLevelSelectionMenu(Mouse::Button button, int x, int y);


	//��� �������� ����. ����������� � ����� start_level.cpp
	void inputGameLevel(Level& level);
	void updateGameLevel(const float dtAsSeconds, Level& level);
	void drawGameLevel(Level& level);
	void drawGameOver(const int gameResult, Level& level);




public:

	Engine();

	int getUserMainMenuInput() const;



	void mainMenu();	// ���� �������� ����
	void settings();	// ���� ��������
	void levelSelectionMenu();		// ���� ������ ������ (�� ������ StartGame)
	void startLevel();			// ���� ������ ���� (��� ���� ���� ����)



};




