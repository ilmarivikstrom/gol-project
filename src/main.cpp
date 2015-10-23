#include "cell.hpp"

#include <iostream>
#include <vector>

int main()
{	
	sf::Vector2i SCREEN(500, 500);
	sf::RenderWindow window(sf::VideoMode(SCREEN.x, SCREEN.y), "Game of life v0.00");
	window.setFramerateLimit(60);
	
	int cellWidth = 10;		// Two .pngs in res/ are 10x10 pixels
	
	
	while(window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		window.clear();
		
		window.display();
	}
	
	
	
	return EXIT_SUCCESS;

/*	THIS CODE IS HERE JUST FOR REFERENCE
	sf::CircleShape triangle(120, 3);
	sf::CircleShape rectangle(120, 4);
	sf::CircleShape pentagon(120, 5);

	#ifdef TEXTUREMODE
	sf::Texture woodTexture;
	if(!woodTexture.loadFromFile("res/woodtexture.png"))
		return 1;
		
	sf::Texture rockTexture;
	if(!rockTexture.loadFromFile("res/rocktexture.png"))
		return 1;
	
	sf::Texture waterTexture;
	if(!waterTexture.loadFromFile("res/watertexture.png"))
		return 1;
	
	triangle.setTexture(&waterTexture);
	rectangle.setTexture(&rockTexture);
	pentagon.setTexture(&woodTexture);
	#endif
	
	#ifdef COLORMODE
	triangle.setFillColor(sf::Color(75, 75, 75));
	rectangle.setFillColor(sf::Color(150, 150, 150));
	pentagon.setFillColor(sf::Color(225, 225, 225));
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
		
		triangle.rotate(2);
		rectangle.rotate(-2);
		pentagon.rotate(2);
		
		
		window.clear();
		
		window.draw(triangle);
		window.draw(rectangle);
		window.draw(pentagon);
		
		window.display();
	}
	
	return EXIT_SUCCESS;
	*/
}

