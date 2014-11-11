#pragma once
#include "stdafx.h"

class mainMenu{
public:
	enum menuResult{ NOTHING, EXIT, PLAY };

	struct menuItem{
	public: 
		sf::Rect<int> rect;
		menuResult action;
	};

	menuResult show(sf::RenderWindow& window);

private:
	menuResult getMenuResponse(sf::RenderWindow& window);
	menuResult handleClick(int x, int y);
	std::list<menuItem> _menuItems;
};