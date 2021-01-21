#pragma once
#include "hero.h"
#include <string>
#include <fstream>
#include "matrix.h"
#include "enemy.h"





class Level
{
private:

	const std::string numLevel;

	unsigned int l_numberOfHeroes;
	Hero** l_hero = nullptr;

	unsigned int l_numberOfEnemiesHarmless;
	EnemyHarmless** l_enemyHarmles = nullptr;

	DifferentSizeArrays< std::string > l_enemyLocation;


	int l_RemainingEnemies;
	bool l_IsWin;



	float l_MaxLeftPlace;
	float l_MaxRightPlace;





public:

	Level(const std::string& numLevel);
	~Level();


	void update(const float elapsedTime);
	void draw(RenderWindow& window);
	void input(Keyboard::Key keyToMoveLeft, Keyboard::Key keyToMoveRight, Keyboard::Key keyToMoveTop, Keyboard::Key keyToMoveBot, Keyboard::Key keyToFire);
	int check();
	



};

















