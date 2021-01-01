#include "laser.h"








Laser::Laser(const Vector2f& position) :
	l_SpeedX(0),
	l_SpeedY(-350)
{
	if (!l_Texture.loadFromFile("texture/laser.jpg"))
	{
		throw("Can't load texture");
	}

	l_Convex.setPointCount(4);
	l_Convex.setPoint(0, sf::Vector2f(0.f, 0.f));
	l_Convex.setPoint(1, sf::Vector2f(8.f, 0.f));
	l_Convex.setPoint(2, sf::Vector2f(8.f, 20.f));
	l_Convex.setPoint(3, sf::Vector2f(0.f, 20.f));


	l_Convex.setTexture(&l_Texture);

	l_Convex.setPosition(position);
}




void Laser::update(const float elapsedTime)
{
	Vector2f position = l_Convex.getPosition();
	position.x += l_SpeedX * elapsedTime;
	position.y += l_SpeedY * elapsedTime;

	l_Convex.setPosition(position);
}








void Laser::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(l_Convex, states);
}





void Laser::setPosition(const Vector2f& position)
{
	l_Convex.setPosition(position);
}


void Laser::setPosition(const float x, const float y)
{
	l_Convex.setPosition(x, y);
}




FloatRect Laser::getGlobalBounds()
{
	return l_Convex.getGlobalBounds();
}


FloatRect Laser::getLocalBounds()
{
	return l_Convex.getLocalBounds();
}








