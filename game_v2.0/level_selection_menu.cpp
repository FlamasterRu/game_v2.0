#include "engine.h"







void Engine::levelSelectionMenu()
{
	e_ChangeWindow = false;		// ������ ��� ������� ����


	// ������ ��� � ��������� ��� ���� ������ ������
	if (!e_BackgroundTexture.loadFromFile("texture/level_selection_menu.png"))
	{
		throw("Can't load texture");
	}
	e_BackgroundSprite.setTexture(e_BackgroundTexture);


	// �������� � ������������� ������
	e_Window.setMouseCursorVisible(true);
	Cursor cursor;
	cursor.loadFromSystem(Cursor::Arrow);
	e_Window.setMouseCursor(cursor);


	drawLevelSelectionMenu(); // ������ ���� ������ ������ ��� �����, ������ ��� ��� ��� ��������


	while (!e_ChangeWindow)
	{
		///////////////////////// ��������� �������
		sf::Event event;
		while (e_Window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
			{
				e_Window.close();
			}

			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == Keyboard::Escape)
				{
					e_ChangeWindow = true;		// ������� �� ���� ���� ������ ������
					e_UserMainMenuInput = MainMenu;	// ��������� � ���� �������� ����
				}
			}

			if (event.type == sf::Event::MouseButtonPressed)
			{
				mouseHandlingLevelSelectionMenu(event.mouseButton.button, event.mouseButton.x, event.mouseButton.y);
			}
		}
		////////////////////////////


		try
		{

		}
		catch (...)
		{
			e_Window.close();
		}
	}
}






void Engine::drawLevelSelectionMenu()
{
	e_Window.clear(Color::White);
	e_Window.draw(e_BackgroundSprite);


	e_Window.display();
}



void Engine::mouseHandlingLevelSelectionMenu(Mouse::Button button, int x, int y)
{
	if (button == Mouse::Button::Left)
	{
		if ((x > 540) and (x < 690) and (y > 310) and (y < 360))		// (540, 310) (690, 360)
		{
			// Level 1

		}
		if ((x > 790) and (x < 940) and (y > 310) and (y < 360))		// (790, 310) (940, 360)
		{
			// Level 2

		}
		if ((x > 1040) and (x < 1190) and (y > 310) and (y < 360))		// (1040, 310) (1190, 360)
		{
			// Level 3

		}
		if ((x > 1290) and (x < 1440) and (y > 310) and (y < 360))		// (1290, 310) (1440, 360)
		{
			// Level 4

		}
		if ((x > 540) and (x < 690) and (y > 430) and (y < 480))		// (540, 430) (690, 480)
		{
			// Level 5

		}
		if ((x > 790) and (x < 940) and (y > 430) and (y < 480))		// (790, 430) (940, 480)
		{
			// Level 6

		}
		if ((x > 1040) and (x < 1190) and (y > 430) and (y < 480))		// (1040, 430) (1190, 480)
		{
			// Level 7

		}
		if ((x > 1290) and (x < 1440) and (y > 430) and (y < 480))		// (1290, 430) (1440, 480)
		{
			// Level 8

		}
		if ((x > 540) and (x < 690) and (y > 550) and (y < 600))		// (540, 550) (690, 600)
		{
			// Level 9

		}
		if ((x > 790) and (x < 960) and (y > 550) and (y < 600))		// (790, 550) (960, 600)
		{
			// Level 10

		}
		if ((x > 1040) and (x < 1210) and (y > 550) and (y < 600))		// (1040, 550) (1210, 600)
		{
			// Level 11

		}
		if ((x > 1290) and (x < 1460) and (y > 550) and (y < 600))		// (1290, 550) (1460, 600)
		{
			// Level 12

		}
	}
}



























