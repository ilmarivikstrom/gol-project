#include <SFML/Graphics.hpp>
#include <iostream>
#include <unistd.h>

int main()
{
	int WIDTH = 200;
	int HEIGHT = 200;
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Game of life v0.00");
	
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
		usleep(10000);
	}
	
	return 0;
}

