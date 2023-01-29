#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>
#include "Textbox.h"
#include <iostream>
class Menu
{
public:
	sf::Sprite _screen;
	sf::Font _font;
	sf::Texture _texture;
	std::vector<Textbox> _menuChoose;
	Menu(sf::Texture &texture, sf::Vector2f pos, sf::Font &font);
	~Menu();
};
