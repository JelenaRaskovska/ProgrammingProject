#include "Projectile.h"

void Projectile::update(sf::Time& dt)
{
	sf::Vector2f moveBy = sf::Vector2f(0, 0);
	if (dir == 0)
	{
		moveBy.y = -speed * dt.asSeconds();
	}
	if (dir == 1)
	{
		moveBy.x = speed * dt.asSeconds();
	}
	if (dir == 2)
	{
		moveBy.y = speed * dt.asSeconds();
	}
	if (dir == 3)
	{
		moveBy.x = -speed * dt.asSeconds();
	}
	body.move(moveBy);
}

void Projectile::shoot(sf::Vector2f pos)
{
	body.setPosition(pos);
	if (dir == 0)
	{
		body.setRotation(-90);
	}
	if (dir == 1)
	{
		body.setRotation(0);
	}
	if (dir == 2)
	{
		body.setRotation(90);
	}
	if (dir == 3)
	{
		body.setRotation(180);
	}
}

bool Projectile::isColliding(sf::FloatRect otherRect)
{
	return body.getGlobalBounds().intersects(otherRect);
}
