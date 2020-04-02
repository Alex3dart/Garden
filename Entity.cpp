#include "Entity.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <time.h>


	sf::Texture textura; // Cargo la textura en RAM
	sf::Texture textura2; // Cargo la textura en RAM
	sf::Texture textura3; // Cargo la textura en RAM

	sf::Sprite player;
	sf::Sprite player2;
	sf::Sprite player3;

	sf::VideoMode mode(1000, 1000);
	sf::RenderWindow window(mode, "Garden");
	sf::Event event;


void Entity::draw() // Cargas imagen
{

	//** Imagenes 250X250px */

	textura.loadFromFile("1.png");

	player.setTexture(textura);
	player.setPosition(1, 1);

	textura2.loadFromFile("2.png");

	player2.setTexture(textura2);
	player2.setPosition(textura.getSize().x, 1);

	textura3.loadFromFile("3.png"); 

	player3.setTexture(textura3);
	player3.setPosition((textura.getSize().x + 1) * 2, 1);
}


void Entity::movement()
{
	window.setFramerateLimit(60);
	
	while (window.isOpen())
	{


		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::KeyPressed)

			{
				if (event.key.code == sf::Keyboard::S) player.move(0, 64);
				if (event.key.code == sf::Keyboard::W) player.move(0, -64);

				if (event.key.code == sf::Keyboard::Down) player2.move(0, 64);
				if (event.key.code == sf::Keyboard::Up) player2.move(0, -64);

				if (event.key.code == sf::Keyboard::Numpad2) player3.move(0, 64);
				if (event.key.code == sf::Keyboard::Numpad8) player3.move(0, -64);

			}
		}
		
		window.clear();
		window.draw(player);
		window.draw(player2);
		window.draw(player3);
		window.display();
	}	
}

