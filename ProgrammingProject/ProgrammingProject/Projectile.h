#pragma once
#include <SFML/Graphics.hpp>

class Projectile
{
public:
	void update(sf::Time& dt);
	void shoot(sf::Vector2f pos);
	bool isColliding(sf::FloatRect otherRect);
	int dir = 0; // 0=up, 1=right, 2=down, 3=left
	float speed = 200.f;
	sf::Sprite body;
};

