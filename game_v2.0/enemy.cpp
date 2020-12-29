#include "enemy.h"












EnemyHarmless::EnemyHarmless() :
	e_MaxLeftPlace(0),
	e_MaxRightPlace(VideoMode::getDesktopMode().width),
	e_SpeedX(0),
	e_SpeedY(0)
{
	if (!e_Texture.loadFromFile("texture/enemy_harmless.jpg"))
	{
		throw("Can't load texture");
	}
	

	e_Convex.setPointCount(12);
	e_Convex.setPoint(0, sf::Vector2f(0, 16));
	e_Convex.setPoint(1, sf::Vector2f(16, 16));
	e_Convex.setPoint(2, sf::Vector2f(16, 0));
	e_Convex.setPoint(3, sf::Vector2f(32, 0));
	e_Convex.setPoint(4, sf::Vector2f(32, 16));
	e_Convex.setPoint(5, sf::Vector2f(48, 16));
	e_Convex.setPoint(6, sf::Vector2f(48, 0));
	e_Convex.setPoint(7, sf::Vector2f(64, 0));
	e_Convex.setPoint(8, sf::Vector2f(64, 16));
	e_Convex.setPoint(9, sf::Vector2f(80, 16));
	e_Convex.setPoint(10, sf::Vector2f(43, 80));
	e_Convex.setPoint(11, sf::Vector2f(37, 80));

	e_Convex.setTexture(&e_Texture);
	e_Convex.setFillColor(Color(255, 200, 0));

	e_Convex.setScale(0.65f, 0.65f);
}





void EnemyHarmless::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(e_Convex, states);
}




void EnemyHarmless::update(const float elapsedTime)
{
	Vector2f position = e_Convex.getPosition();
	position.x += e_SpeedX * elapsedTime;
	position.y += e_SpeedY * elapsedTime;

	if ((position.x <= e_MaxLeftPlace) or (position.x >= e_MaxRightPlace))
	{
		e_SpeedX *= -1;
	}

	e_Convex.setPosition(position);
}



void EnemyHarmless::setPosition(const Vector2f& position)
{
	e_Convex.setPosition(position);
}


void EnemyHarmless::setPosition(const float x, const float y)
{
	e_Convex.setPosition(x, y);
}




FloatRect EnemyHarmless::getGlobalBounds()
{
	return e_Convex.getGlobalBounds();
}



FloatRect EnemyHarmless::getLocalBounds()
{
	return e_Convex.getLocalBounds();
}



void EnemyHarmless::setMaxLeftPlace(const int x)
{
	e_MaxLeftPlace = x;
}

void EnemyHarmless::setMaxRightPlace(const int x)
{
	e_MaxRightPlace = x;
}














































