#include "enemy.h"












EnemyHarmless::EnemyHarmless()
{
	// Текстура героя
	if (!e_Texture.loadFromFile("texture/enemy_harmless.jpg"))
	{
		throw("Can't load texture");
	}
	

	e_Convex.setPointCount(11);
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
	e_Convex.setPoint(10, sf::Vector2f(40, 80));

	e_Convex.setTexture(&e_Texture);
	e_Convex.setFillColor(Color(255, 0, 0));

	e_Convex.setScale(0.9f, 0.9f);
	
}





void EnemyHarmless::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(e_Convex, states);
}




void EnemyHarmless::update(const float elapsedTime)
{

}



void EnemyHarmless::setPosition(const Vector2f& position)
{
	e_Convex.setPosition(position);
}


























































