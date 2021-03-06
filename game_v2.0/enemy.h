#pragma once
#include <SFML/Graphics.hpp>


using namespace sf;




class Enemy : public sf::Drawable
{
private:
	Vector2f e_Position;  //// ���������� ������ �������� ���� ��������������, ������� ��������� ������� �����



public:

	virtual void update(const float elapsedTime) = 0;
	virtual void setPosition(const Vector2f& position) = 0;
	virtual FloatRect getGlobalBounds() = 0;
	virtual void turnAround() = 0;


protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};








class EnemyHarmless : public Enemy
{
private:
	Texture e_Texture;
	sf::ConvexShape e_Convex;


	int e_SpeedX;
	int e_SpeedY;


public:

	EnemyHarmless();
	EnemyHarmless(const EnemyHarmless& e) = delete;


	void update(const float elapsedTime);

	void setPosition(const Vector2f& position);
	void setPosition(const float x, const float y);

	FloatRect getGlobalBounds();
	FloatRect getLocalBounds();
	void turnAround();


protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};





























