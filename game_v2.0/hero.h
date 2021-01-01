#pragma once
#include <SFML/Graphics.hpp>
#include "laser.h"



using namespace sf;







class Hero : public Drawable
{
private:
	Vector2f h_Position;  //// ���������� ������ �������� ���� ��������������, ������� ��������� ������� �����

	Texture h_Texture;
	ConvexShape h_Convex;

	int h_Speed;

	Laser* h_LaserBuff[100];
	int h_LaserBuffSize;
	float h_LastFire;



	// ���������� ���������� ��� ������������ ����������� ��������
	bool h_LeftPressed;
	bool h_RightPressed;
	bool h_TopPressed;
	bool h_BotPressed;
	bool h_GoFire;



public:

	Hero();
	~Hero();

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


	void update(const float elapsedTime);
	void setPosition(const float x, const float y);

	FloatRect getGlobalBounds();
	FloatRect getLocalBounds();
	FloatRect getLaserGlobalBounds(const int i);

	bool deleteLaser(const int i);


protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};






























