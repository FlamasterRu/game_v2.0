#pragma once
#include <SFML/Graphics.hpp>


using namespace sf;




class Enemy : public sf::Drawable
{
private:
	Vector2f e_Position;  ////  оординаты левого верхнего угла примоугольника, который описывает фигурку геро€



public:

	virtual void update(const float elapsedTime) = 0;
	virtual void setPosition(const Vector2f& position) = 0;


protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};








class EnemyHarmless : public Enemy
{
private:
	Texture e_Texture;
	sf::ConvexShape e_Convex;



public:

	EnemyHarmless();


	void update(const float elapsedTime);
	void setPosition(const Vector2f& position);



protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};





























