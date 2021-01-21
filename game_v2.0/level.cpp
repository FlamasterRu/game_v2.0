#include "level.h"






Level::Level(const std::string& selectedLevel)
	: numLevel(selectedLevel),
	l_enemyLocation("level/" + numLevel + ".txt"),
	l_numberOfEnemiesHarmless(0),
	l_RemainingEnemies(0),
	l_numberOfHeroes(1),
	l_IsWin(true)		// ¬ыиграли по умолчанию, пока не проиграли
{
	l_hero = new Hero * [l_numberOfHeroes];
	for (int i = 0; i < l_numberOfHeroes; ++i)
	{
		l_hero[i] = new Hero();
	}



	for (int i = 0; i < l_enemyLocation.numLines(); ++i)
	{
		for (int j = 0; j < l_enemyLocation.numItemsInLine(i); ++j)
		{
			if (l_enemyLocation(i, j) == "h")
			{
				++l_numberOfEnemiesHarmless;
			}
		}
	}


	l_enemyHarmles = new EnemyHarmless * [l_numberOfEnemiesHarmless];
	for (int i = 0; i < l_numberOfEnemiesHarmless; ++i)
	{
		l_enemyHarmles[i] = new EnemyHarmless();
	}

	l_RemainingEnemies += l_numberOfEnemiesHarmless;


	l_MaxLeftPlace = VideoMode::getDesktopMode().width / 20.f;
	l_MaxRightPlace = VideoMode::getDesktopMode().width - l_MaxLeftPlace;



	l_hero[0]->setPosition((VideoMode::getDesktopMode().width - l_hero[0]->getGlobalBounds().width) / 2, VideoMode::getDesktopMode().height * 0.8f);

	int e1 = 0;
	float height = VideoMode::getDesktopMode().height / 40.f, width = 0.f;
	for (int i = 0; i < l_enemyLocation.numLines(); ++i)
	{
		if (l_numberOfEnemiesHarmless > 0)
		{
			width = (VideoMode::getDesktopMode().width - l_enemyHarmles[0]->getGlobalBounds().width * l_enemyLocation.numItemsInLine(i) * 1.5f + l_enemyHarmles[0]->getGlobalBounds().width / 2.f) / 2.f;
		}

		for (int j = 0; j < l_enemyLocation.numItemsInLine(i); ++j)
		{
			if (l_enemyLocation(i, j) == "h")
			{
				l_enemyHarmles[e1]->setPosition(width, height);
				width += l_enemyHarmles[0]->getGlobalBounds().width * 1.5f;
				++e1;
			}
		}
		height += l_enemyHarmles[0]->getGlobalBounds().height * 1.5f;
	}
}







Level::~Level()
{
	if (l_hero != nullptr)
	{
		for (int i = 0; i < l_numberOfHeroes; ++i)
		{
			if (l_hero[i] != nullptr)
			{
				delete l_hero[i];
			}
		}
		delete[] l_hero;
	}
	if (l_enemyHarmles != nullptr)
	{
		for (int i = 0; i < l_numberOfEnemiesHarmless; ++i)
		{
			if (l_enemyHarmles[i] != nullptr)
			{
				delete l_enemyHarmles[i];
			}
		}
		delete[] l_enemyHarmles;
	}
}








void Level::input(Keyboard::Key keyToMoveLeft, Keyboard::Key keyToMoveRight, Keyboard::Key keyToMoveTop, Keyboard::Key keyToMoveBot, Keyboard::Key keyToFire)
{
	// ќбрабатываем нажатие клавиш движени€
	if (Keyboard::isKeyPressed(keyToMoveLeft))
	{
		l_hero[0]->moveLeft();
	}
	else
	{
		l_hero[0]->stopLeft();
	}

	if (Keyboard::isKeyPressed(keyToMoveRight))
	{
		l_hero[0]->moveRight();
	}
	else
	{
		l_hero[0]->stopRight();
	}

	if (Keyboard::isKeyPressed(keyToMoveTop))
	{
		l_hero[0]->moveTop();
	}
	else
	{
		l_hero[0]->stopTop();
	}

	if (Keyboard::isKeyPressed(keyToMoveBot))
	{
		l_hero[0]->moveBot();
	}
	else
	{
		l_hero[0]->stopBot();
	}

	if (Keyboard::isKeyPressed(keyToFire))
	{
		l_hero[0]->goFire();
	}
	else
	{
		l_hero[0]->stopFire();
	}

}



void Level::update(const float elapsedTime)
{
	l_hero[0]->update(elapsedTime);

	for (unsigned int i = 0; i < l_numberOfEnemiesHarmless; ++i)
	{
		if (l_enemyHarmles[i] != nullptr)
		{
			l_enemyHarmles[i]->update(elapsedTime);
		}
	}
}



void Level::draw(RenderWindow& window)
{
	window.draw(*l_hero[0]);

	for (unsigned int i = 0; i < l_numberOfEnemiesHarmless; ++i)
	{
		if (l_enemyHarmles[i] != nullptr)
		{
			window.draw(*l_enemyHarmles[i]);
		}
	}
}






int Level::check()
{
	if (l_RemainingEnemies == 0)
	{
		return 1;	// победа
	}

	FloatRect heroRect = l_hero[0]->getGlobalBounds();
	Vector2f temp;
	FloatRect laserRect;
	for (unsigned int i = 0; i < l_numberOfHeroes; ++i)
	{
		for (int j = 0; j < 100; ++j)
		{
			laserRect = l_hero[i]->getLaserGlobalBounds(j);
			if (laserRect.width == 0)
			{
				continue;
			}

			if ((laserRect.left <= -100) or (laserRect.left >= 2000) or (laserRect.top <= -100) or (laserRect.top >= 1200))
			{
				l_hero[i]->deleteLaser(j);
			}


			for (int k = 0; k < l_numberOfEnemiesHarmless; ++k)
			{
				if (l_enemyHarmles[k] != nullptr)
				{
					FloatRect enemyRect = l_enemyHarmles[k]->getGlobalBounds();

					temp.x = laserRect.left;
					temp.y = laserRect.top;
					if ((temp.x > enemyRect.left) and (temp.x < enemyRect.left + enemyRect.width) and (temp.y > enemyRect.top) and (temp.y < enemyRect.top + enemyRect.height * 0.7f))
					{
						--l_RemainingEnemies;
						delete l_enemyHarmles[k];
						l_enemyHarmles[k] = nullptr;
						l_hero[i]->deleteLaser(j);
						continue;
					}

					temp.x = laserRect.left + laserRect.width;
					temp.y = laserRect.top;
					if ((temp.x > enemyRect.left) and (temp.x < enemyRect.left + enemyRect.width) and (temp.y > enemyRect.top) and (temp.y < enemyRect.top + enemyRect.height * 0.7f))
					{
						--l_RemainingEnemies;
						delete l_enemyHarmles[k];
						l_enemyHarmles[k] = nullptr;
						l_hero[i]->deleteLaser(j);
						continue;
					}

					temp.x = laserRect.left + laserRect.width;
					temp.y = laserRect.top + laserRect.height;
					if ((temp.x > enemyRect.left) and (temp.x < enemyRect.left + enemyRect.width) and (temp.y > enemyRect.top) and (temp.y < enemyRect.top + enemyRect.height * 0.7f))
					{
						--l_RemainingEnemies;
						delete l_enemyHarmles[k];
						l_enemyHarmles[k] = nullptr;
						l_hero[i]->deleteLaser(j);
						continue;
					}

					temp.x = laserRect.left;
					temp.y = laserRect.top + laserRect.height;
					if ((temp.x > enemyRect.left) and (temp.x < enemyRect.left + enemyRect.width) and (temp.y > enemyRect.top) and (temp.y < enemyRect.top + enemyRect.height * 0.7f))
					{
						--l_RemainingEnemies;
						delete l_enemyHarmles[k];
						l_enemyHarmles[k] = nullptr;
						l_hero[i]->deleteLaser(j);
						continue;
					}
				}
			}


		}
	}


	for (int i = 0; i < l_numberOfEnemiesHarmless; ++i)
	{
		if (l_enemyHarmles[i] != nullptr)
		{
			FloatRect enemyRect = l_enemyHarmles[i]->getGlobalBounds();
			if ((enemyRect.left <= -100) or (enemyRect.left >= 2000) or (enemyRect.top <= -100) or (enemyRect.top >= 1200))
			{
				l_IsWin = false;
				delete l_enemyHarmles[i];
				l_enemyHarmles[i] = nullptr;
				return 2;		// поражение
			}


			temp.x = heroRect.left + heroRect.width * 0.5f;
			temp.y = heroRect.top;
			if ((temp.x > enemyRect.left) and (temp.x < enemyRect.left + enemyRect.width) and (temp.y > enemyRect.top) and (temp.y < enemyRect.top + enemyRect.height))
			{
				return 2;		// поражение
			}

			temp.x = heroRect.left + heroRect.width;
			temp.y = heroRect.top + heroRect.height;
			if ((temp.x > enemyRect.left) and (temp.x < enemyRect.left + enemyRect.width) and (temp.y > enemyRect.top) and (temp.y < enemyRect.top + enemyRect.height))
			{
				return 2;		// поражение
			}

			temp.x = heroRect.left;
			temp.y = heroRect.top + heroRect.height;
			if ((temp.x > enemyRect.left) and (temp.x < enemyRect.left + enemyRect.width) and (temp.y > enemyRect.top) and (temp.y < enemyRect.top + enemyRect.height))
			{
				return 2;		// поражение
			}
		}
	}

	bool flag = 0;
	for (int i = 0; i < l_numberOfEnemiesHarmless; ++i)
	{
		if (l_enemyHarmles[i] != nullptr)
		{
			if ((l_enemyHarmles[i]->getGlobalBounds().left <= l_MaxLeftPlace) or (l_enemyHarmles[i]->getGlobalBounds().left + l_enemyHarmles[i]->getGlobalBounds().width >= l_MaxRightPlace))
			{
				flag = 1;
			}
		}
	}
	if (flag == 1)
	{
		for (int i = 0; i < l_numberOfEnemiesHarmless; ++i)
		{
			if (l_enemyHarmles[i] != nullptr)
			{
				l_enemyHarmles[i]->turnAround();
			}
		}
	}






	return 0;		// всЄ норм продолжаем игру
}













































































