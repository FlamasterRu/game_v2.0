#pragma once
#include "hero.h"
#include <string>
#include <fstream>
#include "enemy.h"





class Level
{
private:

	const std::string numLevel;

	unsigned int l_numberOfHeroes = 1;
	Hero* l_hero = nullptr;

	unsigned int l_numberOfEnemiesHarmless = 0;
	EnemyHarmless* l_enemyHarmles = nullptr;



	






public:

	Level(const std::string& numLevel);
	~Level();


	void update(const float elapsedTime);
	void draw(RenderWindow& window);
	void input(Keyboard::Key keyToMoveLeft, Keyboard::Key keyToMoveRight, Keyboard::Key keyToMoveTop, Keyboard::Key keyToMoveBot, Keyboard::Key keyToFire);
	void placeLevel();




};

















