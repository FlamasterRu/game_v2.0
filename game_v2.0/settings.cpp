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
					e_ChangeWindow = true;		// Выходим из окна настроек
					e_UserMainMenuInput = static_cast<int>(GameWindows::MainMenu);	// Переходим в окно главного меню
				}
			}
		}
		////////////////////////////


		drawSettings();
		inputSettings();

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
	text1.setStyle(Text::Bold);
	text1.setCharacterSize(38);
	temp = text1.getGlobalBounds();
	PositionX = (resolution - temp.width) / 2.0;
	text1.setPosition(PositionX, PositionY / 10.0);


	Text text2("Moving", font);
	text2.setFillColor(SpaseBlue);
	text2.setStyle(Text::Bold);
	text2.setCharacterSize(34);
	PositionX = resolution / 4.0;
	PositionY /= 5.0;
	text2.setPosition(PositionX, PositionY);
	PositionY += text2.getCharacterSize() * 3.0;


	Text text3("Up: " + e_stringKeyToMoveTop, font);
	text3.setFillColor(SpaseBlue);
	text3.setPosition(PositionX, PositionY);
	PositionY += text3.getCharacterSize() * 1.5;

	Text text4("Down: " + e_stringKeyToMoveBot, font);
	text4.setFillColor(SpaseBlue);
	text4.setPosition(PositionX, PositionY);
	PositionY += text4.getCharacterSize() * 1.5;

	Text text5("Left: " + e_stringKeyToMoveLeft, font);
	text5.setFillColor(SpaseBlue);
	text5.setPosition(PositionX, PositionY);
	PositionY += text5.getCharacterSize() * 1.5;

	Text text6("Right: " + e_stringKeyToMoveRight, font);
	text6.setFillColor(SpaseBlue);
	text6.setPosition(PositionX, PositionY);
	PositionY += text6.getCharacterSize() * 5.0;

	Text text7("Fire", font);
	text7.setFillColor(SpaseBlue);
	text7.setPosition(PositionX, PositionY);
	text7.setStyle(Text::Bold);
	text7.setCharacterSize(34);
	PositionY += text7.getCharacterSize() * 3.0;


	Text text8("Laser fire: " + e_stringKeyToFire, font);
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
		resolution.x = VideoMode::getDesktopMode().width;
		resolution.y = VideoMode::getDesktopMode().height / 5;
		Vector2i mousePosition(Mouse::getPosition());

		if ((mousePosition.x > 470) and (mousePosition.x < 640))		// проверка на нажатие в зонах
		{
			if ((mousePosition.y > 320) and (mousePosition.y < 358))
			{
				// up
				e_keyToMoveTop = returnPressedKey(e_keyToMoveTop);
				e_stringKeyToMoveTop = keyboardKeyAsString(e_keyToMoveTop);
			}
			if ((mousePosition.y > 365) and (mousePosition.y < 403))
			{
				// down
				e_keyToMoveBot = returnPressedKey(e_keyToMoveBot);
				e_stringKeyToMoveBot = keyboardKeyAsString(e_keyToMoveBot);
			}
			if ((mousePosition.y > 410) and (mousePosition.y < 442))
			{
				// left
				e_keyToMoveLeft = returnPressedKey(e_keyToMoveLeft);
				e_stringKeyToMoveLeft = keyboardKeyAsString(e_keyToMoveLeft);
			}
			if ((mousePosition.y > 455) and (mousePosition.y < 488))
			{
				// right
				e_keyToMoveRight = returnPressedKey(e_keyToMoveRight);
				e_stringKeyToMoveRight = keyboardKeyAsString(e_keyToMoveRight);
			}
			if ((mousePosition.y > 705) and (mousePosition.y < 742))
			{
				// fire
				e_keyToFire = returnPressedKey(e_keyToFire);
				e_stringKeyToFire = keyboardKeyAsString(e_keyToFire);
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
	text.setPosition(VideoMode::getDesktopMode().width / 4.f, VideoMode::getDesktopMode().height * 0.9f);


	e_Window.draw(text);
	e_Window.display();


	while (temp == Keyboard::Key::Unknown)
	{
		Event event;
		while (e_Window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				e_Window.close();
			}
			if (event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::Key::Escape)
				{
					return key;
				}
				temp = event.key.code;
			}
		}
	}

	return temp;

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







