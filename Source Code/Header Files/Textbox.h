#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>
#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27
#define SFML_NO_DEPRECATED_WARNINGS
class Textbox {
public:
	Textbox(int size, sf::Color color, bool sel, sf::Font& font);
	void setSize(int size);
	void setcolor(sf::Color color);
	void setFont(sf::Font &font);
	void setPosition(sf::Vector2f pos);
	void setLimit(bool toF);
	void setString2(std::string t);
	void setLimit1(bool toF, int lim);
	void clearString();
	void setSelected(bool sel);
	void newstring(std::string t);
	std::string getText();
	void newstring2(std::string t);
	void draw(sf::RenderWindow &window);
	void typeOn(sf::Event input);
	void setscaleAndOut(float size, int x, int y, int z);
	bool isMouseOver(sf::RenderWindow &window);
	bool isKickMouse(sf::RenderWindow &window);

private:
	sf::Text textbox;
	std::ostringstream text;
	bool isSelected;
	bool hasLimit = false;
	int limit;

	void inputLogic(int charType);
	void inputLength(int chartype);
	void deleteChar();
};


class Button
{
public:
	Button(sf::Vector2f size, sf::Color bgColor) {
		this->shape.setSize(size);
		this->shape.setFillColor(bgColor);
		this->shape.setOutlineThickness(2.f);
		this->shape.setOutlineColor(sf::Color::Yellow);
		
	};
	
	void settextture(sf::Texture& tthinh)
	{
		this->shape.setTexture(&tthinh);
	}
	void setSizeOfButton(sf::Vector2f size)
	{
		this->shape.setSize(size);
	}

	void setTextture(sf::Texture texture)
	{
		shape.setTexture(&texture);
	}
	void setoutline(sf::Color color)
	{
		this->shape.setOutlineColor(color);
		this->shape.setOutlineThickness(1.f);
	}

	void setBgColor(sf::Color color)
	{
		this->shape.setFillColor(color);
	}


	void setPosition(sf::Vector2f pos)
	{
		this->shape.setPosition(pos);
	}


	bool isMouseOver(sf::RenderWindow& window)
	{
		float mouseX = sf::Mouse::getPosition(window).x;
		float mouseY = sf::Mouse::getPosition(window).y;

		float buttonX = shape.getPosition().x;
		float buttonY = shape.getPosition().y;


		float buttonWidth = buttonX + shape.getGlobalBounds().width;
		float buttonHeight = buttonWidth + shape.getGlobalBounds().height;

		if (mouseX<buttonWidth && mouseX>buttonX && mouseY<buttonHeight && mouseY>buttonY)
			return true;
		return false;

	}
	bool isKickMouse(sf::RenderWindow& window)
	{
		float mouseX = sf::Mouse::getPosition(window).x;
		float mouseY = sf::Mouse::getPosition(window).y;

		float buttonX = shape.getPosition().x;
		float buttonY = shape.getPosition().y;

		float buttonWidth = buttonX + shape.getGlobalBounds().width;
		float buttonHeight = buttonY + shape.getGlobalBounds().height;

		if (mouseX<buttonWidth && mouseX>buttonX && mouseY<buttonHeight && mouseY>buttonY)
			return true;
		return false;

	}
	void draw(sf::RenderWindow& window)
	{
		window.draw(shape);
	}
private:
	sf::RectangleShape shape;
};