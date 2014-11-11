#include "stdafx.h"

void game::start(void){
	if (_gameState != UNINITIIALIZED){ return; }
	_mainWindow.create(sf::VideoMode(1024, 768, 32), "Pong Clone!!!!");
	_gameState = game::SHOWINGSPLASH;

	while (!isExiting()){
		gameLoop();
	}

	_mainWindow.close();
}

bool game::isExiting(){
	if (_gameState == game::EXITING){ return true; }
	else { return false; }
}

void game::gameLoop(){
	sf::Event currentEvent;
	while (_mainWindow.pollEvent(currentEvent)){
		switch (_gameState){
		case game::SHOWINGSPLASH:
			showSplashScreen();
			break;
		case game::SHOWINGMENU:
			showMenu();
			break;
		case game::PLAYING:
			sf::Event currentEvent;
			while (_mainWindow.pollEvent(currentEvent)){
				_mainWindow.clear(sf::Color(0, 255, 0));
				_mainWindow.display();

				/*if (currentEvent.type == sf::Event::Closed){ 
					_gameState = game::EXITING; }

				if (currentEvent.type == sf::Event::KeyPressed){
					if (currentEvent.key.code == sf::Keyboard::Escape){ 
						showMenu(); }
				*/

				switch (currentEvent.type){
				case sf::Event::KeyPressed:
					if (currentEvent.key.code == sf::Keyboard::Escape){
						showMenu();
					}
					break;
				case sf::Event::Closed:
					_gameState = game::EXITING;
					break;
				}
			}
			break;
		}
	}
}

void game::showSplashScreen(){
	splashScreen splashScreen;
	splashScreen.show(_mainWindow);
	_gameState = game::SHOWINGMENU;
}

void game::showMenu(){
	mainMenu mainMenu;
	mainMenu::menuResult result = mainMenu.show(_mainWindow);
	switch (result){
	case mainMenu::EXIT:
		_gameState = game::EXITING;
		break;
	case mainMenu::PLAY:
		_gameState = game::PLAYING;
		break;
	}
}

game::gameState game::_gameState = UNINITIIALIZED;
sf::RenderWindow game::_mainWindow;
