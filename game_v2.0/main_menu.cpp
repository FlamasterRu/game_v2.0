#include "engine.h"





void Engine::mainMenu()
{
	e_ChangeWindow = false;		// ������ ��� ������� ����


	// ������ ��� � ��������� ��� ����
	if (!e_BackgroundTexture.loadFromFile("texture/main_menu.png"))
	{
		throw("Can't load texture");
	}
	e_BackgroundSprite.setTexture(e_BackgroundTexture);


	// �������� � ������������� ������
	e_Window.setMouseCursorVisible(true);
	Cursor cursor;
	cursor.loadFromSystem(Cursor::Arrow);
	e_Window.setMouseCursor(cursor);


	drawMainMenu(); // ������ ������� ���� ��� �����, ������ ��� ��� ��� ��������


	while (!e_ChangeWindow)
	{
		///////////////////////// ��������� �������
		Event event;
		while (e_Window.pollEvent(event))
		{

			if (event.type == Event::Closed)
			{
				e_Window.close();
			}

			if (event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::Escape)
				{
					e_ChangeWindow = true;		// ������� �� �������� ����
					e_UserMainMenuInput = static_cast<int>(GameWindows::Exit);	// ��������� ����
				}
			}

			if (event.type == Event::MouseButtonPressed)
			{
				mouseHandlingMainMenu(event.mouseButton.button, event.mouseButton.x, event.mouseButton.y);
			}
		}
		////////////////////////////

	}
}





void Engine::drawMainMenu()
{
	e_Window.clear(Color::White);
	e_Window.draw(e_BackgroundSprite);
	e_Window.display();
}



void Engine::mouseHandlingMainMenu(Mouse::Button button, int x, int y)
{
	if (button == Mouse::Button::Left)
	{
		if ((x > 910) and (x < 1030) and (y > 640) and (y < 700))		// (910, 640)   (1030, 700)
		{
			e_UserMainMenuInput = static_cast<int>(GameWindows::Exit);		// ������ �� ������, ������ ������ ���� �� ������� ���� (��������� ����)
			e_ChangeWindow = true;
			e_Window.close();
		}
		if ((x > 850) and (x < 1110) and (y > 410) and (y < 480))		// (850, 410) (1110, 480)
		{
			e_UserMainMenuInput = static_cast<int>(GameWindows::LevelSelectionMenu);		// ������ �� ������, ������ ������ ����
			e_ChangeWindow = true;
		}
		if ((x > 890) and (x < 1070) and (y > 540) and (y < 600))		// (890, 540)  (1070, 600)
		{
			e_UserMainMenuInput = static_cast<int>(GameWindows::Settings);		// ������ �� ������, ������ ������ ����
			e_ChangeWindow = true;
		}
	}
}











































