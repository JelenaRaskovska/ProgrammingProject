// Student Name: Lena Raskovska
// Student ID: C00273875
// Date: 13/02/22
// Time taken:
// Known Bugs: first 2 enemies are invincible for some time

#include "Game.h"
#include <iostream>
const int HEIGHT = 600;
const int WIDTH = 800;


/// <summary>
/// default constructor
/// setup the window properties
/// load and setup the text 
/// load and setup thne image
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ WIDTH, HEIGHT, 32U }, "Programming Project" },
	m_exitGame{ false } //when true game will exit
{
	setupFontAndText(); // load font 
	setupSprite(); // load texture
}

/// <summary>
/// default destructor we didn't dynamically allocate anything
/// so we don't need to free it, but mthod needs to be here
/// </summary>
Game::~Game()
{
}


/// <summary>
/// main game loop
/// update 60 times per second,
/// process update as often as possible and at least 60 times per second
/// draw as often as possible but only updates are on time
/// if updates run slow then don't render frames
/// </summary>
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}

		render(); // as many as possible

	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if (sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}

		player.processKeys(newEvent);

	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}
	player.update(t_deltaTime);
	for (int i = 0; i < 5; i++)
	{
		enemyOnes[i].update(t_deltaTime, player.body.getPosition());
		if (enemyOnes[i].increaseScore)
		{
			score++;
			enemyOnes[i].increaseScore = false;
			m_score.setString("Score: " + std::to_string(score));
		}
		for (int x = 0; x < player.MAX_PROJ; x++)
		{
			if (enemyOnes[i].isColliding(player.projectile[x].body.getGlobalBounds()))
			{
				player.projectile[x].body.setPosition(-10000,-10000);
				enemyOnes[i].takeDamage();
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		enemyTwos[i].update(t_deltaTime, sf::Vector2f(400,600));
		if (enemyTwos[i].increaseScore)
		{
			score++;
			enemyTwos[i].increaseScore = false;
			m_score.setString("Score: " + std::to_string(score));
		}
		for (int x = 0; x < player.MAX_PROJ; x++)
		{
			if (enemyTwos[i].isColliding(player.projectile[x].body.getGlobalBounds()))
			{
				player.projectile[x].body.setPosition(-10000, -10000);
				enemyTwos[i].takeDamage();
			}
		}
	}
}

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::White);
	m_window.draw(bg);

	m_window.draw(player.body);
	for (int i = 0; i < 5; i++)
	{
		if (enemyOnes[i].alive) m_window.draw(enemyOnes[i].body);
	}
	for (int i = 0; i < 3; i++)
	{
		if (enemyTwos[i].alive) m_window.draw(enemyTwos[i].body);
	}

	for (int i = 0; i < player.MAX_PROJ; i++)
	{
		m_window.draw(player.projectile[i].body);
	}

	m_window.draw(m_score);

	m_window.display();
}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupFontAndText()
{
	if (!m_font.loadFromFile("ASSETS/FONTS/rainyhearts.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
	m_score.setFont(m_font);
	m_score.setString("Score: 0");
	m_score.setFillColor(sf::Color::Black);
	m_score.setCharacterSize(48);
}

/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Game::setupSprite()
{
	bgTex.loadFromFile("ASSETS/IMAGES/background.png");
	bg.setTexture(bgTex);
	player.body.setPosition(200,200);
	for (int i = 0; i < 5; i++)
	{
		enemyOnes[i].setup();
		enemyOnes[i].body.setPosition(enemyOnes[i].body.getPosition() - sf::Vector2f(0,100 * i));
	}
	for (int i = 0; i < 3; i++)
	{
		enemyTwos[i].setup();
		enemyTwos[i].body.setPosition(enemyTwos[i].body.getPosition() - sf::Vector2f(300, 100 * i));
	}
}


