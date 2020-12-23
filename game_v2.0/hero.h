#pragma once
#include <SFML/Graphics.hpp>



using namespace sf;







class Hero : public sf::Drawable
{
private:
	Vector2f h_Position;  //// Координаты левого верхнего угла примоугольника, который описывает фигурку героя

	Texture h_Texture;

	sf::ConvexShape h_Convex;


	int h_Speed;



	// Логические переменные для отслеживания направления движения
	bool h_LeftPressed;
	bool h_RightPressed;
	bool h_TopPressed;
	bool h_BotPressed;
	bool h_GoFire;



public:

	Hero();

	// Для движения
	void moveLeft();
	void moveRight();
	void moveTop();
	void moveBot();

	// Прекращение движения
	void stopLeft();
	void stopRight();
	void stopTop();
	void stopBot();



	// Для стрельбы
	void goFire();
	void stopFire();


	void update(float elapsedTime);


protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};






























