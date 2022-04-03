// Student Name: Lena Raskovska
// Student ID: C00273875
// Date: 13/02/22
// Time taken: 
// Known Bugs: 
#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "EnemyOne.h"
#include "EnemyTwo.h"

class Game
{
public:
	Game();
	~Game();
	void run();

private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();

	void setupFontAndText();
	void setupSprite();

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_font; // font used by message
	sf::Text m_score;
	int score = 0;

	Player player; // player

	EnemyOne enemyOnes[5]; // 5 enemyOnes
	EnemyTwo enemyTwos[3]; // 3 enemyTwos

	sf::Sprite bg;
	sf::Texture bgTex;

	bool m_exitGame; // control exiting game

};

#endif // !GAME_HPP

