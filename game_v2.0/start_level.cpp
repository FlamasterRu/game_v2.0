#include "engine.h"













void Engine::startLevel()
{
	e_ChangeWindow = false;		// Только что сменили окно

	// Фоновая картинка
	if (!e_BackgroundTexture.loadFromFile("texture/background.png"))
	{
		throw("Can't load texture");
	}
	e_BackgroundSprite.setTexture(e_BackgroundTexture);

	// Вsключаем курсор
	e_Window.setMouseCursorVisible(false);



	Level level(e_SelectedLevel);
	level.placeLevel();

	Clock clock;
	Time dt;
	float dtAsSeconds;
	int gameResult = 0;
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
					e_ChangeWindow = true;		// Выходим из окна игры
					e_UserMainMenuInput = static_cast<int>(GameWindows::MainMenu);	// Переходим в окно главного меню
				}
			}
		}
		////////////////////////////

		if (gameResult == 0)
		{
			inputGameLevel(level);

			dt = clock.restart();
			dtAsSeconds = dt.asSeconds();
			updateGameLevel(dtAsSeconds, level);

			drawGameLevel(level);
			gameResult = level.check();
		}
		else
		{
			drawGameOver(gameResult, level);
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





void Engine::drawGameOver(const int gameResult, Level& level)
{
	e_Window.clear(Color::White);
	e_Window.draw(e_BackgroundSprite);

	Rect<float> temp;
	unsigned int PositionX, PositionY = VideoMode::getDesktopMode().height, resolution = VideoMode::getDesktopMode().width;
	Color SpaseBlue(63, 72, 204);


	Font font;
	if (!font.loadFromFile("font/game_font.ttf"))
	{
		throw("Can't open font");
	}

	std::string str;
	if (gameResult == 1)
	{
		str = "You Win!";
	}
	else
	{
		str = "You Lose";
	}


	Text text1("GAME OVER", font);
	text1.setFillColor(SpaseBlue);
	text1.setStyle(Text::Bold);
	text1.setCharacterSize(80);
	text1.setOutlineThickness(5);
	temp = text1.getGlobalBounds();
	PositionX = (resolution - temp.width) / 2.0f;
	text1.setPosition(PositionX, PositionY / 6.0f);


	Text text2(str, font);
	text2.setFillColor(Color::Red);
	text2.setCharacterSize(50);
	text2.setOutlineThickness(5);
	temp = text2.getGlobalBounds();
	PositionX = (resolution - temp.width) / 2.0f;
	text2.setPosition(PositionX, PositionY / 2.0f);


	Text text3("Press Escape", font);
	text3.setFillColor(Color::White);
	text3.setPosition(VideoMode::getDesktopMode().width / 10.f, VideoMode::getDesktopMode().height * 0.9f);


	level.draw(e_Window);
	e_Window.draw(text1);
	e_Window.draw(text2);
	e_Window.draw(text3);


	e_Window.display();
}




















