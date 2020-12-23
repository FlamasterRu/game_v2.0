#pragma once
#include "hero.h"
#include <string>
#include <fstream>





class Level
{
private:

	unsigned int numberOfHeroes;
	Hero* hero = nullptr;






public:

	Level(std::string numLevel);
	~Level();


	void update(float elapsedTime);
	void draw(sf::RenderWindow& window);
	void input(sf::Keyboard::Key keyToMoveLeft, sf::Keyboard::Key keyToMoveRight, sf::Keyboard::Key keyToMoveTop, sf::Keyboard::Key keyToMoveBot);





};

















