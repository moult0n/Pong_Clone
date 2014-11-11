#pragma once
#include "stdafx.h"

class game{
public:
	static void start();

private:
	static bool isExiting();
	static void gameLoop();

	static void showSplashScreen();
	static void showMenu();

	enum gameState{ UNINITIIALIZED, SHOWINGSPLASH, PAUSED, SHOWINGMENU, PLAYING, EXITING };

	static gameState _gameState;
	static sf::RenderWindow _mainWindow;
};