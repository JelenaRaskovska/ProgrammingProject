#pragma once
#include <SFML/Graphics.hpp>

class EnemyOne
{
public:
	void setup();
	void update(sf::Time& dt, sf::Vector2f playerPos);
	void takeDamage();
	bool isColliding(sf::FloatRect otherRect);
	float speed = 50.f;
	sf::Sprite body;
	sf::Texture tex;
	bool alive = false;
	bool increaseScore = false;

private:
	sf::Clock aliveTimer;
	int health = 2;
};

