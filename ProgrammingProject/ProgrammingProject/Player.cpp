#include "Player.h"
#include <iostream>

Player::Player()
{
	texUp.loadFromFile("ASSETS/IMAGES/up.png");
	texRight.loadFromFile("ASSETS/IMAGES/right.png");
	texDown.loadFromFile("ASSETS/IMAGES/down.png");
	texLeft.loadFromFile("ASSETS/IMAGES/left.png");
	body.setTexture(texDown);
	body.setScale(3.f, 3.f);
	projectileTex.loadFromFile("ASSETS/IMAGES/arrow.png");
	for (int i = 0; i < MAX_PROJ; i++)
	{
		projectile[i].body.setTexture(projectileTex);
	}
}

void Player::processKeys(sf::Event& ev)
{
	if (ev.type == sf::Event::KeyPressed)
	{
		if (ev.key.code == sf::Keyboard::W)
		{
			body.setTexture(texUp);
			up = true;
			lastDir = 0;
		}
		if (ev.key.code == sf::Keyboard::D)
		{
			body.setTexture(texRight);
			right = true;
			lastDir = 1;
		}
		if (ev.key.code == sf::Keyboard::S)
		{
			body.setTexture(texDown);
			down = true;
			lastDir = 2;
		}
		if (ev.key.code == sf::Keyboard::A)
		{
			body.setTexture(texLeft);
			left = true;
			lastDir = 3;
		}
		if (ev.key.code == sf::Keyboard::Space)
		{
			shootProjectile();
		}
	}

	if (ev.type == sf::Event::KeyReleased)
	{
		if (ev.key.code == sf::Keyboard::W)
		{
			up = false;
		}
		if (ev.key.code == sf::Keyboard::D)
		{
			right = false;
		}
		if (ev.key.code == sf::Keyboard::S)
		{
			down = false;
		}
		if (ev.key.code == sf::Keyboard::A)
		{
			left = false;
		}
	}
}

void Player::update(sf::Time& dt)
{
	sf::Vector2f moveBy = sf::Vector2f(0,0);
	if (up)
	{
		moveBy.y = -speed * dt.asSeconds();
	}
	if (right)
	{
		moveBy.x = speed * dt.asSeconds();
	}
	if (down)
	{
		moveBy.y = speed * dt.asSeconds();
	}
	if (left)
	{
		moveBy.x = -speed * dt.asSeconds();
	}
	body.move(moveBy);

	for (int i = 0; i < MAX_PROJ; i++)
	{
		projectile[i].update(dt);
	}
}

void Player::shootProjectile()
{
	if (reload.getElapsedTime().asSeconds() > 0.5f)
	{
		if (currentProj > MAX_PROJ - 1) currentProj = 0;
		projectile[currentProj].dir = lastDir;

		projectile[currentProj].shoot(body.getPosition());
		currentProj++;
		reload.restart();
	}
}
