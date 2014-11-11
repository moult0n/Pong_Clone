#include "stdafx.h"

mainMenu::menuResult mainMenu::show(sf::RenderWindow& window){

	//load menu image from file
	sf::Texture texture;
	texture.loadFromFile("images/mainMenu.png");
	sf::Sprite sprite;
	sprite.setTexture(texture);

	////set up clickable regions
	//Play button
	menuItem playButton;
	playButton.rect.top = 145;
	playButton.rect.height = 235;
	playButton.rect.left = 0;
	playButton.rect.width = 1023;
	playButton.action = PLAY;

	//Exit button
	menuItem exitButton;
	exitButton.rect.top = 383;
	exitButton.rect.height = 177;
	exitButton.rect.left = 0;
	exitButton.rect.width = 1023;
	exitButton.action = EXIT;

	_menuItems.push_back(playButton);
	_menuItems.push_back(exitButton);

	window.draw(sprite);
	window.display();

	return getMenuResponse(window);
}

mainMenu::menuResult mainMenu::handleClick(int x, int y){
	std::list<menuItem>::iterator it;
	for (it = _menuItems.begin(); it != _menuItems.end(); it++){
		sf::Rect<int> menuItemRect = (*it).rect;
		if (menuItemRect.contains(sf::Vector2<int>(x, y))){ 
			return it->action; }
	}

	return NOTHING;
}

mainMenu::menuResult mainMenu::getMenuResponse(sf::RenderWindow& window){
	sf::Event menuEvent;

	while (true){
		while (window.pollEvent(menuEvent)){
			if (menuEvent.type == sf::Event::MouseButtonPressed){
				return handleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
			}
			if (menuEvent.type == sf::Event::Closed){ return EXIT; }
		}
	}
}