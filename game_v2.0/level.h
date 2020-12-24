#pragma once
#include "hero.h"
#include <string>
#include <fstream>
#include "enemy.h"




class Level
{
private:

	unsigned int l_numberOfHeroes = 1;
	Hero* l_hero = nullptr;

	unsigned int l_numberOfEnemiesHarmless = 0;
	EnemyHarmless* l_enemyHarmles = nullptr;




public:

	Level(const std::string& numLevel);
	~Level();


	void update(const float elapsedTime);
	void draw(sf::RenderWindow& window);
	void input(sf::Keyboard::Key keyToMoveLeft, sf::Keyboard::Key keyToMoveRight, sf::Keyboard::Key keyToMoveTop, sf::Keyboard::Key keyToMoveBot);





};

















