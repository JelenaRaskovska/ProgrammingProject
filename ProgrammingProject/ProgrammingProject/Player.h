#pragma once
#include <SFML/Graphics.hpp>
#include "Projectile.h"

class Player
{
public:
	Player(); //player constructor

	void processKeys(sf::Event& ev);
	void update(sf::Time& dt);

	sf::Sprite body;
	static const int MAX_PROJ = 10;
	Projectile projectile[MAX_PROJ];
	float speed = 100.f;

private:
	//projectile
	void shootProjectile();
	int currentProj = 0;
	sf::Texture projectileTex;
	sf::Clock reload;

	sf::Texture texUp;
	sf::Texture texRight;
	sf::Texture texDown;
	sf::Texture texLeft;
	bool up = false;
	bool right = false;
	bool down = false;
	bool left = false;
	int lastDir = 0;

};
