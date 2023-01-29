#include "../Header Files/MenuBox.h"
Menu::Menu(sf::Texture &texture, sf::Vector2f pos, sf::Font &font)
{
	_texture = texture;
	_screen.setTexture(texture);
	_screen.setPosition(pos);
	_font = font;
	_menuChoose.push_back(Textbox(30, sf::Color(132, 60, 12), false, _font));
	_menuChoose.push_back(Textbox(30, sf::Color(132, 60, 12), false, _font));
	_menuChoose.push_back(Textbox(30, sf::Color(132, 60, 12), false, _font));
	_menuChoose.push_back(Textbox(30, sf::Color(132, 60, 12), false, _font));
	_menuChoose.push_back(Textbox(30, sf::Color(132, 60, 12), false, _font));
	_menuChoose[0].newstring("PLAY");
	_menuChoose[1].newstring("LOAD");
	_menuChoose[2].newstring("CONF");
	_menuChoose[3].newstring("ACHI");
	_menuChoose[4].newstring("EXIT");
	_menuChoose[0].setPosition({700.f, 150.f});
	_menuChoose[1].setPosition({720.f, 200.f});
	_menuChoose[2].setPosition({740.f, 250.f});
	_menuChoose[3].setPosition({760.f, 300.f});
	_menuChoose[4].setPosition({780.f, 350.f});

	_menuChoose[0].setscaleAndOut(2.f, 238, 238, 238);
	_menuChoose[1].setscaleAndOut(2.f, 238, 238, 238);
	_menuChoose[2].setscaleAndOut(2.f, 238, 238, 238);
	_menuChoose[3].setscaleAndOut(2.f, 238, 238, 238);
	_menuChoose[4].setscaleAndOut(2.f, 238, 238, 238);
}

Menu::~Menu()
{
	std::cout << "Menu Close..." << std::endl;
}