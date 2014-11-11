#include "stdafx.h"

void splashScreen::show(sf::RenderWindow & renderwindow){
	sf::Texture splashImage;
	splashImage.loadFromFile("images/splashScreen.png");
	
	sf::Sprite sprite(splashImage);

	renderwindow.draw(sprite);
	renderwindow.display();

	sf::Event event;
	while (true){
		while (renderwindow.pollEvent(event)){
			if (event.type == sf::Event::EventType::KeyPressed
				|| event.type == sf::Event::EventType::MouseButtonPressed
				|| event.type == sf::Event::EventType::Closed ) { return; }
		}
	}
}