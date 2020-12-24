#include "engine.h"





void Engine::mainMenu()
{
	e_ChangeWindow = false;		// только что сменили окно


	// Задний фон с надписями для меню
	if (!e_BackgroundTexture.loadFromFile("texture/main_menu.png"))
	{
		throw("Can't load texture");
	}
	e_BackgroundSprite.setTexture(e_BackgroundTexture);


	// Включаем и устанавливаем курсор
	e_Window.setMouseCursorVisible(true);
	Cursor cursor;
	cursor.loadFromSystem(Cursor::Arrow);
	e_Window.setMouseCursor(cursor);


	drawMainMenu(); // Рисуем главное меню вне цикла, потому что там нет анимации


	while (!e_ChangeWindow)
	{
		///////////////////////// Обработка событий
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
					e_ChangeWindow = true;		// Выходим из главного меню
					e_UserMainMenuInput = static_cast<int>(GameWindows::Exit);	// Закрываем окно
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
			e_UserMainMenuInput = static_cast<int>(GameWindows::Exit);		// нажали на кнопку, значит меняем окно на рабочий стол (закрываем наше)
			e_ChangeWindow = true;
			e_Window.close();
		}
		if ((x > 850) and (x < 1110) and (y > 410) and (y < 480))		// (850, 410) (1110, 480)
		{
			e_UserMainMenuInput = static_cast<int>(GameWindows::LevelSelectionMenu);		// нажали на кнопку, значит меняем окно
			e_ChangeWindow = true;
		}
		if ((x > 890) and (x < 1070) and (y > 540) and (y < 600))		// (890, 540)  (1070, 600)
		{
			e_UserMainMenuInput = static_cast<int>(GameWindows::Settings);		// нажали на кнопку, значит меняем окно
			e_ChangeWindow = true;
		}
	}
}











































