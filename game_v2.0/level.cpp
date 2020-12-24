#include "level.h"






Level::Level(const std::string& numLevel)
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








void Level::input(sf::Keyboard::Key keyToMoveLeft, sf::Keyboard::Key keyToMoveRight, sf::Keyboard::Key keyToMoveTop, sf::Keyboard::Key keyToMoveBot)
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











