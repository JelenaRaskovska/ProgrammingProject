#pragma once
#include <SFML/Graphics.hpp>
#include "Projectile.h"

class EnemyTwo
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

	//projectile
	static const int MAX_PROJ = 10;
	Projectile projectile[MAX_PROJ];
	
	void shootProjectile();
	int currentProj = 0;
	sf::Texture projectileTex;
	sf::Clock reload;
private:
	sf::Clock aliveTimer;
	int health = 1;
};

