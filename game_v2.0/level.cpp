#include "level.h"






Level::Level(std::string numLevel)
{
	std::ifstream iFile;
	iFile.open("level/" + numLevel + ".txt", std::ios_base::in);
	if (!iFile.is_open())
	{
		throw("Can't open file");
	}
	iFile >> numberOfHeroes;


	hero = new Hero[numberOfHeroes];




	iFile.close();
}







Level::~Level()
{
	if (hero != nullptr)
	{
		delete[] hero;
	}
}








void Level::input(sf::Keyboard::Key keyToMoveLeft, sf::Keyboard::Key keyToMoveRight, sf::Keyboard::Key keyToMoveTop, sf::Keyboard::Key keyToMoveBot)
{
	// Обрабатываем нажатие клавиш движения
	if (Keyboard::isKeyPressed(keyToMoveLeft))
	{
		hero[0].moveLeft();
	}
	else
	{
		hero[0].stopLeft();
	}

	if (Keyboard::isKeyPressed(keyToMoveRight))
	{
		hero[0].moveRight();
	}
	else
	{
		hero[0].stopRight();
	}

	if (Keyboard::isKeyPressed(keyToMoveTop))
	{
		hero[0].moveTop();
	}
	else
	{
		hero[0].stopTop();
	}

	if (Keyboard::isKeyPressed(keyToMoveBot))
	{
		hero[0].moveBot();
	}
	else
	{
		hero[0].stopBot();
	}

}



void Level::update(float elapsedTime)
{
	hero[0].update(elapsedTime);
}



void Level::draw(RenderWindow& window)
{
	window.draw(hero[0]);
}











