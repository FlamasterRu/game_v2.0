#pragma once
#include <SFML/Graphics.hpp>


enum MainMenuInput
{
	Exit,				// ��������� ���� 0
	MainMenu,			// ������� ������� ���� 1
	Settings,			// ������� ��������� 2
	LevelSelectionMenu,		// ������� ���� ������ ������ 3 (�� ������ StartGame � ������� ����)
	StartGame
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


	// ������ ����������
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





	//��� �������� ����. ����������� � ����� main_menu.cpp
	void drawMainMenu();
	void mouseHandlingMainMenu(Mouse::Button button, int x, int y);


	//��� ��������. ����������� � ����� settings.cpp
	void drawSettings();
	void inputSettings();


	//��� ���� ������ ������. ����������� � ����� level_selection_menu.cpp
	void drawLevelSelectionMenu();
	void mouseHandlingLevelSelectionMenu(Mouse::Button button, int x, int y);





	
	Keyboard::Key returnPressedKey(Keyboard::Key key);		// �������� ����������� ������ �������, � ������ ������ ���������� key
	Keyboard::Key pressedButtom();
	std::string keyboardKeyAsString(Keyboard::Key key);





public:

	Engine();

	int getUserMainMenuInput() const;



	void mainMenu();	// ���� �������� ����
	void settings();	// ���� ��������
	void levelSelectionMenu();		// ���� ������ ������ (�� ������ StartGame)







};




