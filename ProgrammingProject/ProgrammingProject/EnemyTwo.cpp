#include "EnemyTwo.h"

void EnemyTwo::setup()
{
	tex.loadFromFile("ASSETS/IMAGES/enemy2.png");
	body.setScale(2, 2);

	projectileTex.loadFromFile("ASSETS/IMAGES/arrow.png");
	for (int i = 0; i < MAX_PROJ; i++)
	{
		projectile[i].body.setTexture(projectileTex);
	}

	body.setTexture(tex);
	body.setPosition(100, -200);
}

void EnemyTwo::update(sf::Time& dt, sf::Vector2f playerPos)
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

		for (int i = 0; i < MAX_PROJ; i++)
		{
			projectile[i].update(dt);
		}

		if (reload.getElapsedTime().asSeconds() > 2.5f)
		{
			shootProjectile();
		}
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

void EnemyTwo::takeDamage()
{
	health -= 1;
	if (health <= 0)
	{
		health = 1;
		body.setPosition(-10000, -10000);
		alive = false;
		aliveTimer.restart();
		increaseScore = true;
	}
}

bool EnemyTwo::isColliding(sf::FloatRect otherRect)
{
	return body.getGlobalBounds().intersects(otherRect);
}

void EnemyTwo::shootProjectile()
{
	if (currentProj > MAX_PROJ - 1) currentProj = 0;
	projectile[currentProj].dir = 3;

	projectile[currentProj].shoot(body.getPosition());
	currentProj++;
	reload.restart();
}
