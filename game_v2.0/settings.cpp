#include "engine.h"






void Engine::settings()
{
	e_ChangeWindow = false;		// Только что сменили окно


	// Фоновая картинка
	if (!e_BackgroundTexture.loadFromFile("texture/background.png"))
	{
		throw("Can't load texture");
	}
	e_BackgroundSprite.setTexture(e_BackgroundTexture);


	// Включаем и устанавливаем курсор
	e_Window.setMouseCursorVisible(true);
	Cursor cursor;
	cursor.loadFromSystem(Cursor::Arrow);
	e_Window.setMouseCursor(cursor);



	while (!e_ChangeWindow)
	{
		///////////////////////// Обработка событий
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
					e_ChangeWindow = true;		// Выходим из окна настроек
					e_UserMainMenuInput = MainMenu;	// Переходим в окно главного меню
				}
			}
		}
		////////////////////////////


		try
		{
			drawSettings();
			inputSettings();
		}
		catch (...)
		{
			e_Window.close();
		}
	}
}











void Engine::drawSettings()
{
	e_Window.clear(Color::White);
	e_Window.draw(e_BackgroundSprite);

	Rect<float> temp;
	unsigned int PositionX, PositionY = VideoMode::getDesktopMode().height, resolution = VideoMode::getDesktopMode().width;		// Разрешение экрана
	Color SpaseBlue(63, 72, 204);
	
	
	Font font;
	if (!font.loadFromFile("font/game_font.ttf"))
	{
		throw("Can't open font");
	}

	// Надписи в настройках
	Text text1("Setting", font);
	text1.setFillColor(SpaseBlue);
	temp = text1.getGlobalBounds();
	PositionX = (resolution - temp.width) / 2.0;
	text1.setPosition(PositionX, PositionY / 10.0);
	text1.setStyle(Text::Bold);
	text1.setCharacterSize(38);

	Text text2("Moving", font);
	text2.setFillColor(SpaseBlue);
	PositionX = resolution / 4.0;
	PositionY /= 5.0;
	text2.setPosition(PositionX, PositionY);
	PositionY += text2.getCharacterSize() * 3.0;
	text2.setStyle(Text::Bold);
	text2.setCharacterSize(34);

	Text text3("Up: " + stringKeyToMoveTop, font);
	text3.setFillColor(SpaseBlue);
	text3.setPosition(PositionX, PositionY);
	PositionY += text3.getCharacterSize() * 1.5;

	Text text4("Down: " + stringKeyToMoveBot, font);
	text4.setFillColor(SpaseBlue);
	text4.setPosition(PositionX, PositionY);
	PositionY += text4.getCharacterSize() * 1.5;

	Text text5("Left: " + stringKeyToMoveLeft, font);
	text5.setFillColor(SpaseBlue);
	text5.setPosition(PositionX, PositionY);
	PositionY += text5.getCharacterSize() * 1.5;

	Text text6("Right: " + stringKeyToMoveRight, font);
	text6.setFillColor(SpaseBlue);
	text6.setPosition(PositionX, PositionY);
	PositionY += text6.getCharacterSize() * 5.0;

	Text text7("Fire", font);
	text7.setFillColor(SpaseBlue);
	text7.setPosition(PositionX, PositionY);
	PositionY += text7.getCharacterSize() * 3.0;
	text7.setStyle(Text::Bold);
	text7.setCharacterSize(34);

	Text text8("Laser fire: " + stringKeyToFire, font);
	text8.setFillColor(SpaseBlue);
	text8.setPosition(PositionX, PositionY);
	PositionY += text8.getCharacterSize() * 1.5;


	e_Window.draw(text1);
	e_Window.draw(text2);
	e_Window.draw(text3);
	e_Window.draw(text4);
	e_Window.draw(text5);
	e_Window.draw(text6);
	e_Window.draw(text7);
	e_Window.draw(text8);


	e_Window.display();
}




void Engine::inputSettings()
{
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		Vector2i resolution;
		bool flag = 1;
		resolution.x = VideoMode::getDesktopMode().width;
		resolution.y = VideoMode::getDesktopMode().height / 5;
		Vector2i mousePosition(Mouse::getPosition());

		if ((mousePosition.x > resolution.x / 4) and (mousePosition.x < resolution.x / 4 + 200))		// проверка на нажатие в зонах
		{
			if ((mousePosition.y > resolution.y + 90) and (mousePosition.y < resolution.y + 120))
			{
				// up
				keyToMoveTop = returnPressedKey(keyToMoveTop);
				stringKeyToMoveTop = keyboardKeyAsString(keyToMoveTop);
			}
			if ((mousePosition.y > resolution.y + 135) and (mousePosition.y < resolution.y + 165))
			{
				// down
				keyToMoveBot = returnPressedKey(keyToMoveBot);
				stringKeyToMoveBot = keyboardKeyAsString(keyToMoveBot);
			}
			if ((mousePosition.y > resolution.y + 180) and (mousePosition.y < resolution.y + 210))
			{
				// left
				keyToMoveLeft = returnPressedKey(keyToMoveLeft);
				stringKeyToMoveLeft = keyboardKeyAsString(keyToMoveLeft);
			}
			if ((mousePosition.y > resolution.y + 225) and (mousePosition.y < resolution.y + 255))
			{
				// right
				keyToMoveRight = returnPressedKey(keyToMoveRight);
				stringKeyToMoveRight = keyboardKeyAsString(keyToMoveRight);
			}
			if ((mousePosition.y > resolution.y + 465) and (mousePosition.y < resolution.y + 495))
			{
				// fire
				keyToFire = returnPressedKey(keyToFire);
				stringKeyToFire = keyboardKeyAsString(keyToFire);
			}
		}

	}
}













Keyboard::Key Engine::returnPressedKey(Keyboard::Key key)
{
	Keyboard::Key temp = Keyboard::Key::Unknown;
	Font font;
	if (!font.loadFromFile("font/game_font.ttf"))
	{
		throw("Can't open font");
	}
	Text text("Press Key", font);
	text.setFillColor(Color::White);
	text.setPosition(VideoMode::getDesktopMode().width / 4, VideoMode::getDesktopMode().height * 0.9);


	e_Window.draw(text);
	e_Window.display();

	// Ждем пока не нажмут какую-нибудь из клавиш или escape
	while (temp == Keyboard::Key::Unknown)
	{
		temp = pressedButtom();
		if (temp == Keyboard::Key::Escape)
		{
			// Задержка должна быть до обработки событий, иначе после задержки escape ещё раз передаётся в event
			sleep(TIME_DELAY_ESCAPE);
			sf::Event event;
			while (e_Window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					e_Window.close();
				}
			}
			return key;
		}
	}
	return temp;

}








Keyboard::Key Engine::pressedButtom()
{
	if (Keyboard::isKeyPressed(Keyboard::Key::Q))
	{
		return Keyboard::Key::Q;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::W))
	{
		return Keyboard::Key::W;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::E))
	{
		return Keyboard::Key::E;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::R))
	{
		return Keyboard::Key::R;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::T))
	{
		return Keyboard::Key::T;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Y))
	{
		return Keyboard::Key::Y;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::U))
	{
		return Keyboard::Key::U;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::I))
	{
		return Keyboard::Key::I;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::O))
	{
		return Keyboard::Key::O;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::P))
	{
		return Keyboard::Key::P;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::A))
	{
		return Keyboard::Key::A;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::S))
	{
		return Keyboard::Key::S;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::D))
	{
		return Keyboard::Key::D;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::F))
	{
		return Keyboard::Key::F;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::G))
	{
		return Keyboard::Key::G;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::H))
	{
		return Keyboard::Key::H;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::J))
	{
		return Keyboard::Key::J;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::K))
	{
		return Keyboard::Key::K;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::L))
	{
		return Keyboard::Key::L;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Z))
	{
		return Keyboard::Key::Z;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::X))
	{
		return Keyboard::Key::X;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::C))
	{
		return Keyboard::Key::C;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::V))
	{
		return Keyboard::Key::V;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::B))
	{
		return Keyboard::Key::B;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::N))
	{
		return Keyboard::Key::N;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::M))
	{
		return Keyboard::Key::M;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Num1))
	{
		return Keyboard::Key::Num1;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Num2))
	{
		return Keyboard::Key::Num2;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Num3))
	{
		return Keyboard::Key::Num3;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Num4))
	{
		return Keyboard::Key::Num4;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Num5))
	{
		return Keyboard::Key::Num5;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Num6))
	{
		return Keyboard::Key::Num6;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Num7))
	{
		return Keyboard::Key::Num7;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Num8))
	{
		return Keyboard::Key::Num8;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Num9))
	{
		return Keyboard::Key::Num9;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Num0))
	{
		return Keyboard::Key::Num0;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Numpad1))
	{
		return Keyboard::Key::Numpad1;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Numpad2))
	{
		return Keyboard::Key::Numpad2;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Numpad3))
	{
		return Keyboard::Key::Numpad3;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Numpad4))
	{
		return Keyboard::Key::Numpad4;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Numpad5))
	{
		return Keyboard::Key::Numpad5;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Numpad6))
	{
		return Keyboard::Key::Numpad6;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Numpad7))
	{
		return Keyboard::Key::Numpad7;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Numpad8))
	{
		return Keyboard::Key::Numpad8;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Numpad9))
	{
		return Keyboard::Key::Numpad9;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Numpad0))
	{
		return Keyboard::Key::Numpad0;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Down))
	{
		return Keyboard::Key::Down;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Left))
	{
		return Keyboard::Key::Left;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Right))
	{
		return Keyboard::Key::Right;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Up))
	{
		return Keyboard::Key::Up;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Tab))
	{
		return Keyboard::Key::Tab;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::LShift))
	{
		return Keyboard::Key::LShift;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::RShift))
	{
		return Keyboard::Key::RShift;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::LControl))
	{
		return Keyboard::Key::LControl;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::RControl))
	{
		return Keyboard::Key::RControl;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::LAlt))
	{
		return Keyboard::Key::LAlt;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::RAlt))
	{
		return Keyboard::Key::RAlt;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Space))
	{
		return Keyboard::Key::Space;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
	{
		return Keyboard::Key::Escape;
	}
	else
	{
		return Keyboard::Key::Unknown;
	}
}


std::string Engine::keyboardKeyAsString(Keyboard::Key key)
{
	if (key == (Keyboard::Key::Q))
	{
		return "Q";
	}
	else if (key == (Keyboard::Key::W))
	{
		return "W";
	}
	else if (key == (Keyboard::Key::E))
	{
		return "E";
	}
	else if (key == (Keyboard::Key::R))
	{
		return "R";
	}
	else if (key == (Keyboard::Key::T))
	{
		return "T";
	}
	else if (key == (Keyboard::Key::Y))
	{
		return "Y";
	}
	else if (key == (Keyboard::Key::U))
	{
		return "U";
	}
	else if (key == (Keyboard::Key::I))
	{
		return "I";
	}
	else if (key == (Keyboard::Key::O))
	{
		return "O";
	}
	else if (key == (Keyboard::Key::P))
	{
		return "P";
	}
	else if (key == (Keyboard::Key::A))
	{
		return "A";
	}
	else if (key == (Keyboard::Key::S))
	{
		return "S";
	}
	else if (key == (Keyboard::Key::D))
	{
		return "D";
	}
	else if (key == (Keyboard::Key::F))
	{
		return "F";
	}
	else if (key == (Keyboard::Key::G))
	{
		return "G";
	}
	else if (key == (Keyboard::Key::H))
	{
		return "H";
	}
	else if (key == (Keyboard::Key::J))
	{
		return "J";
	}
	else if (key == (Keyboard::Key::K))
	{
		return "K";
	}
	else if (key == (Keyboard::Key::L))
	{
		return "L";
	}
	else if (key == (Keyboard::Key::Z))
	{
		return "Z";
	}
	else if (key == (Keyboard::Key::X))
	{
		return "X";
	}
	else if (key == (Keyboard::Key::C))
	{
		return "C";
	}
	else if (key == (Keyboard::Key::V))
	{
		return "V";
	}
	else if (key == (Keyboard::Key::B))
	{
		return "B";
	}
	else if (key == (Keyboard::Key::N))
	{
		return "N";
	}
	else if (key == (Keyboard::Key::M))
	{
		return "M";
	}
	else if (key == (Keyboard::Key::Num1))
	{
		return "Num1";
	}
	else if (key == (Keyboard::Key::Num2))
	{
		return "Num2";
	}
	else if (key == (Keyboard::Key::Num3))
	{
		return "Num3";
	}
	else if (key == (Keyboard::Key::Num4))
	{
		return "Num4";
	}
	else if (key == (Keyboard::Key::Num5))
	{
		return "Num5";
	}
	else if (key == (Keyboard::Key::Num6))
	{
		return "Num6";
	}
	else if (key == (Keyboard::Key::Num7))
	{
		return "Num7";
	}
	else if (key == (Keyboard::Key::Num8))
	{
		return "Num8";
	}
	else if (key == (Keyboard::Key::Num9))
	{
		return "Num9";
	}
	else if (key == (Keyboard::Key::Num0))
	{
		return "Num0";
	}
	else if (key == (Keyboard::Key::Numpad1))
	{
		return "Numpad1";
	}
	else if (key == (Keyboard::Key::Numpad2))
	{
		return "Numpad2";
	}
	else if (key == (Keyboard::Key::Numpad3))
	{
		return "Numpad3";
	}
	else if (key == (Keyboard::Key::Numpad4))
	{
		return "Numpad4";
	}
	else if (key == (Keyboard::Key::Numpad5))
	{
		return "Numpad5";
	}
	else if (key == (Keyboard::Key::Numpad6))
	{
		return "Numpad6";
	}
	else if (key == (Keyboard::Key::Numpad7))
	{
		return "Numpad7";
	}
	else if (key == (Keyboard::Key::Numpad8))
	{
		return "Numpad8";
	}
	else if (key == (Keyboard::Key::Numpad9))
	{
		return "Numpad9";
	}
	else if (key == (Keyboard::Key::Numpad0))
	{
		return "Numpad0";
	}
	else if (key == (Keyboard::Key::Down))
	{
		return "Down";
	}
	else if (key == (Keyboard::Key::Left))
	{
		return "Left";
	}
	else if (key == (Keyboard::Key::Right))
	{
		return "Right";
	}
	else if (key == (Keyboard::Key::Up))
	{
		return "Up";
	}
	else if (key == (Keyboard::Key::Tab))
	{
		return "Tab";
	}
	else if (key == (Keyboard::Key::LShift))
	{
		return "LShift";
	}
	else if (key == (Keyboard::Key::RShift))
	{
		return "RShift";
	}
	else if (key == (Keyboard::Key::LControl))
	{
		return "LControl";
	}
	else if (key == (Keyboard::Key::RControl))
	{
		return "RControl";
	}
	else if (key == (Keyboard::Key::LAlt))
	{
		return "LAlt";
	}
	else if (key == (Keyboard::Key::RAlt))
	{
		return "RAlt";
	}
	else if (key == (Keyboard::Key::Space))
	{
		return "Space";
	}
	else if (key == (Keyboard::Key::Escape))
	{
		return "Escape";
	}
	else
	{
		return "Unknown";
	}
}







