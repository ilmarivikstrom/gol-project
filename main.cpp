// Set either COLORMODE or TEXTUREMODE
#define TEXTUREMODE

#include <SFML/Graphics.hpp>
#include <iostream>
#include <unistd.h>

int main()
{	
	int WIDTH = 800;
	int HEIGHT = 800;
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Game of life v0.00");


	// Setting up different textures for different shapes
	sf::Texture woodTexture;
	if(!woodTexture.loadFromFile("res/woodtexture.png"))
		return 1;
		
	sf::Texture rockTexture;
	if(!rockTexture.loadFromFile("res/rocktexture.png"))
		return 1;
	
	sf::Texture waterTexture;
	if(!waterTexture.loadFromFile("res/watertexture.png"))
		return 1;
	
	// Creating a triangle, a square and a pentagon
	sf::CircleShape triangle(80, 3);
	sf::CircleShape rectangle(80, 4);
	sf::CircleShape pentagon(80, 5);
	
	#ifdef TEXTUREMODE
	triangle.setTexture(&waterTexture);
	rectangle.setTexture(&rockTexture);
	pentagon.setTexture(&woodTexture);
	#endif
	
	#ifdef COLORMODE
	triangle.setFillColor(sf::Color(100, 100, 100));
	rectangle.setFillColor(sf::Color(150, 150, 150));
	pentagon.setFillColor(sf::Color(200, 200, 200));
	#endif
	
	triangle.setPosition(200, 200);
	rectangle.setPosition(400, 400);
	pentagon.setPosition(600, 600);
	
	while(window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		triangle.rotate(1);
		rectangle.rotate(-1);
		pentagon.rotate(1);
		
		
		window.clear();
		
		window.draw(triangle);
		window.draw(rectangle);
		window.draw(pentagon);
		
		window.display();
		usleep(10000);
	}
	
	return 0;
}

