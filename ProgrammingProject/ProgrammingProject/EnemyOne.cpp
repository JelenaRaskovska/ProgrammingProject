#include "EnemyOne.h"

void EnemyOne::setup()
{
	tex.loadFromFile("ASSETS/IMAGES/enemy1.png");
	body.setScale(3,3);
	body.setTexture(tex);
	body.setPosition(400,-200);
}

void EnemyOne::update(sf::Time& dt, sf::Vector2f playerPos)
{
	if (alive)
	{
		playerPos = playerPos - body.getPosition();
		sf::Vector2f direction;
		if (playerPos.x > 0)
		{
			direction += sf::Vector2f(1, 0);
		}
		if (playerPos.x < 0)
		{
			direction -= sf::Vector2f(1, 0);
		}
		if (playerPos.y > 0)
		{
			direction += sf::Vector2f(0, 1);
		}
		if (playerPos.y < 0)
		{
			direction -= sf::Vector2f(0, 1);
		}

		body.move(direction * dt.asSeconds() * speed);
	}
	else
	{
		if (aliveTimer.getElapsedTime().asSeconds() > 1)
		{
			setup();
			alive = true;
		}
	}
}

void EnemyOne::takeDamage()
{
	health -= 1;
	if (health <= 0)
	{
		health = 2;
		body.setPosition(-10000,-10000);
 		alive = false;
		aliveTimer.restart();
		increaseScore = true;
	}
}

bool EnemyOne::isColliding(sf::FloatRect otherRect)
{
	return body.getGlobalBounds().intersects(otherRect);
}
