#include "engine.h"













void Engine::startLevel()
{
	e_ChangeWindow = false;		// ������ ��� ������� ����

	// ������� ��������
	if (!e_BackgroundTexture.loadFromFile("texture/background.png"))
	{
		throw("Can't load texture");
	}
	e_BackgroundSprite.setTexture(e_BackgroundTexture);

	// �s������� ������
	e_Window.setMouseCursorVisible(false);



	Level level(e_SelectedLevel);
	level.placeLevel();

	Clock clock;
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
					e_ChangeWindow = true;		// ������� �� ���� ����
					e_UserMainMenuInput = static_cast<int>(GameWindows::MainMenu);	// ��������� � ���� �������� ����
				}
			}
		}
		////////////////////////////

		Time dt = clock.restart();
		float dtAsSeconds = dt.asSeconds();
		try
		{
			inputGameLevel(level);
			updateGameLevel(dtAsSeconds, level);
			drawGameLevel(level);
		}
		catch (...)
		{
			e_Window.close();
		}
	}
}





void Engine::inputGameLevel(Level& level)
{
	level.input(e_keyToMoveLeft, e_keyToMoveRight, e_keyToMoveTop, e_keyToMoveBot, e_keyToFire);
}




void Engine::updateGameLevel(const float dtAsSeconds, Level& level)
{
	level.update(dtAsSeconds);
}



void Engine::drawGameLevel(Level& level)
{
	e_Window.clear(Color::White);
	e_Window.draw(e_BackgroundSprite);


	level.draw(e_Window);




	e_Window.display();
}


























