#include "level.h"






Level::Level(const std::string& selectedLevel) : numLevel(selectedLevel)
{
	std::ifstream iFile;
	iFile.open("level/" + numLevel + ".txt", std::ios_base::in);
	if (!iFile.is_open())
	{
		throw("Can't open file");
	}


	std::string name;

	iFile >> name >> l_numberOfHeroes;
	if (name == "hero")
	{
		l_hero = new Hero[l_numberOfHeroes];
	}
	else
	{
		throw ("Error in level file " + numLevel + " in str 1.");
	}



	iFile >> name >> l_numberOfEnemiesHarmless;
	if (name == "enemy_harmless")
	{
		l_enemyHarmles = new EnemyHarmless[l_numberOfEnemiesHarmless];
	}
	else
	{
		throw ("Error in level file " + numLevel + " in str 2.");
	}


	iFile.close();
}







Level::~Level()
{
	if (l_hero != nullptr)
	{
		delete[] l_hero;
	}
	if (l_enemyHarmles != nullptr)
	{
		delete[] l_enemyHarmles;
	}
}








void Level::input(Keyboard::Key keyToMoveLeft, Keyboard::Key keyToMoveRight, Keyboard::Key keyToMoveTop, Keyboard::Key keyToMoveBot, Keyboard::Key keyToFire)
{
	// Обрабатываем нажатие клавиш движения
	if (Keyboard::isKeyPressed(keyToMoveLeft))
	{
		l_hero[0].moveLeft();
	}
	else
	{
		l_hero[0].stopLeft();
	}

	if (Keyboard::isKeyPressed(keyToMoveRight))
	{
		l_hero[0].moveRight();
	}
	else
	{
		l_hero[0].stopRight();
	}

	if (Keyboard::isKeyPressed(keyToMoveTop))
	{
		l_hero[0].moveTop();
	}
	else
	{
		l_hero[0].stopTop();
	}

	if (Keyboard::isKeyPressed(keyToMoveBot))
	{
		l_hero[0].moveBot();
	}
	else
	{
		l_hero[0].stopBot();
	}

	if (Keyboard::isKeyPressed(keyToFire))
	{
		l_hero[0].goFire();
	}
	else
	{
		l_hero[0].stopFire();
	}

}



void Level::update(const float elapsedTime)
{
	l_hero[0].update(elapsedTime);

	for (int i = 0; i < l_numberOfEnemiesHarmless; ++i)
	{
		l_enemyHarmles[i].update(elapsedTime);
	}
}



void Level::draw(RenderWindow& window)
{
	window.draw(l_hero[0]);

	for (int i = 0; i < l_numberOfEnemiesHarmless; ++i)
	{
		window.draw(l_enemyHarmles[i]);
	}
}




void Level::placeLevel()
{
	if (numLevel == "1")		//разместить уровень 1
	{
		l_hero[0].setPosition((VideoMode::getDesktopMode().width - l_hero[0].getGlobalBounds().width) / 2, VideoMode::getDesktopMode().height * 0.8f);

		int k = 0;
		unsigned int height = VideoMode::getDesktopMode().height / 10;
		for (int i = 0; i < 3; ++i)
		{
			int maxLeftPlace = VideoMode::getDesktopMode().width * 0.1;
			int maxRightPlace = VideoMode::getDesktopMode().width * 0.9 - l_enemyHarmles[0].getGlobalBounds().width;
			unsigned int width = (VideoMode::getDesktopMode().width - 11.5 * l_enemyHarmles[0].getGlobalBounds().width) / 2;
			for (int j = 0; j < 8; ++j)
			{
				l_enemyHarmles[k].setMaxLeftPlace(maxLeftPlace);
				maxLeftPlace += l_enemyHarmles[0].getGlobalBounds().width * 1.5;

				l_enemyHarmles[l_numberOfEnemiesHarmless - 1 - k].setMaxRightPlace(maxRightPlace);
				maxRightPlace -= l_enemyHarmles[0].getGlobalBounds().width * 1.5;

				l_enemyHarmles[k].setPosition(width, height);
				width += l_enemyHarmles[0].getGlobalBounds().width * 1.5;
				++k;
			}
			height += l_enemyHarmles[0].getGlobalBounds().height * 1.5;
		}
	}




}

































