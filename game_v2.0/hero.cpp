#include "hero.h"





Hero::Hero() : 
	h_Position(1000.f, 500.f),
	h_BotPressed(false),
	h_GoFire(false), 
	h_LeftPressed(false),
	h_RightPressed(false),
	h_TopPressed(false),
	h_Speed(350)
{
	// Текстура героя
	if (!h_Texture.loadFromFile("texture/hero.jpg"))
	{
		throw("Can't load texture");
	}



	h_Convex.setPointCount(9);
	h_Convex.setPoint(0, sf::Vector2f(50, 0));
	h_Convex.setPoint(1, sf::Vector2f(65, 75));
	h_Convex.setPoint(2, sf::Vector2f(100, 100));
	h_Convex.setPoint(3, sf::Vector2f(65, 100));
	h_Convex.setPoint(4, sf::Vector2f(60, 115));
	h_Convex.setPoint(5, sf::Vector2f(40, 115));
	h_Convex.setPoint(6, sf::Vector2f(35, 100));
	h_Convex.setPoint(7, sf::Vector2f(0, 100));
	h_Convex.setPoint(8, sf::Vector2f(35, 75));


	h_Convex.setTexture(&h_Texture);
	h_Convex.setFillColor(Color(0, 150, 255));


}





void Hero::moveLeft()
{
	h_LeftPressed = true;
}


void Hero::moveRight()
{
	h_RightPressed = true;
}


void Hero::moveTop()
{
	h_TopPressed = true;
}


void Hero::moveBot()
{
	h_BotPressed = true;
}


void Hero::stopLeft()
{
	h_LeftPressed = false;
}


void Hero::stopRight()
{
	h_RightPressed = false;
}


void Hero::stopTop()
{
	h_TopPressed = false;
}


void Hero::stopBot()
{
	h_BotPressed = false;
}


void Hero::goFire()
{
	h_GoFire = true;
}


void Hero::stopFire()
{
	h_GoFire = false;
}








// Двигаем на основании пользовательского ввода в этом кадре, прошедшего времени и скорости
void Hero::update(const float elapsedTime)
{
	float maxX = VideoMode::getDesktopMode().width;		// Разрешение экрана
	float maxY = VideoMode::getDesktopMode().height;

	if (h_RightPressed)
	{
		if (h_Position.x + h_Speed * elapsedTime < maxX - h_Convex.getTextureRect().width)    	// Чтобы не выходил за пределы монитора
		{
			h_Position.x += h_Speed * elapsedTime;
		}
	}

	if (h_LeftPressed)
	{
		if (h_Position.x - h_Speed * elapsedTime > 0)
		{
			h_Position.x -= h_Speed * elapsedTime;
		}
	}

	if (h_TopPressed)
	{
		if (h_Position.y - h_Speed * elapsedTime > 0)
		{
			h_Position.y -= h_Speed * elapsedTime;
		}
	}

	if (h_BotPressed)
	{
		if (h_Position.y + h_Speed * elapsedTime < maxY - h_Convex.getTextureRect().height)
		{
			h_Position.y += h_Speed * elapsedTime;
		}
	}


	// перемещаем фигуру героя
	h_Convex.setPosition(h_Position);
}








void Hero::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(h_Convex, states);
}























