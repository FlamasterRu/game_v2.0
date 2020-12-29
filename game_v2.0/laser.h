#pragma once
#include <SFML/Graphics.hpp>


using namespace sf;









class Laser : public Drawable
{
private:

	Texture l_Texture;
	ConvexShape l_Convex;

	int l_SpeedX;
	int l_SpeedY;






public:

	Laser(const Vector2f& position, const Color color);
	Laser(const Vector2f& position);

	void update(const float elapsedTime);


	void setPosition(const Vector2f& position);
	void setPosition(const float x, const float y);

	FloatRect getGlobalBounds();
	FloatRect getLocalBounds();










protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
































