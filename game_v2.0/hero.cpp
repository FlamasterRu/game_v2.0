#include "hero.h"





Hero::Hero() : 
	h_Position(1000.f, 500.f),
	h_BotPressed(false),
	h_GoFire(false), 
	h_LeftPressed(false),
	h_RightPressed(false),
	h_TopPressed(false),
	h_Speed(100)
{
	// Текстура героя
	if (!h_Texture.loadFromFile("texture/hero.jpg"))
	{
		throw("Can't load texture");
	}



	h_Convex.setPointCount(4);
	h_Convex.setPoint(0, sf::Vector2f(0, 0));
	h_Convex.setPoint(1, sf::Vector2f(0, 50));
	h_Convex.setPoint(2, sf::Vector2f(50, 50));
	h_Convex.setPoint(3, sf::Vector2f(50, 0));


	h_Convex.setTexture(&h_Texture);
	h_Convex.setFillColor(Color::Yellow);


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
void Hero::update(float elapsedTime)
{
	float maxX = VideoMode::getDesktopMode().width;		// Разрешение экрана
	float maxY = VideoMode::getDesktopMode().height;

	if (h_RightPressed)
	{
		if (h_Position.x + h_Speed * elapsedTime < maxX)    	// Чтобы не выходил за пределы монитора
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
		if (h_Position.y + h_Speed * elapsedTime < maxY)
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























