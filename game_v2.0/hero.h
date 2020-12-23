#pragma once
#include <SFML/Graphics.hpp>



using namespace sf;







class Hero : public sf::Drawable
{
private:
	Vector2f h_Position;  //// ���������� ������ �������� ���� ��������������, ������� ��������� ������� �����

	Texture h_Texture;

	sf::ConvexShape h_Convex;


	int h_Speed;



	// ���������� ���������� ��� ������������ ����������� ��������
	bool h_LeftPressed;
	bool h_RightPressed;
	bool h_TopPressed;
	bool h_BotPressed;
	bool h_GoFire;



public:

	Hero();

	// ��� ��������
	void moveLeft();
	void moveRight();
	void moveTop();
	void moveBot();

	// ����������� ��������
	void stopLeft();
	void stopRight();
	void stopTop();
	void stopBot();



	// ��� ��������
	void goFire();
	void stopFire();


	void update(float elapsedTime);


protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};






























