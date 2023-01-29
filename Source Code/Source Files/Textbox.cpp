#include "../Header Files/Textbox.h"
Textbox::Textbox(int size, sf::Color color, bool sel, sf::Font& font) {
	textbox.setCharacterSize(size);
	textbox.setFillColor(color);
	textbox.setFont(font);
	isSelected = sel;
	if (sel)
	{
		textbox.setString("_");
	}
	else
	{
		textbox.setString("");
	}
}
void Textbox::setSize(int size)
{
	textbox.setCharacterSize(size);
}
void Textbox::setcolor(sf::Color color)
{
	textbox.setFillColor(color);
}
void Textbox::setFont(sf::Font &font)
{
	textbox.setFont(font);
}

void Textbox::setPosition(sf::Vector2f pos)
{
	textbox.setPosition(pos);
}

void Textbox::setLimit(bool toF)
{
	hasLimit = toF;
}

void Textbox::setString2(std::string t)
{
	text << t;
}

void Textbox::setLimit1(bool toF, int lim)
{
	hasLimit = toF;
	limit = lim - 1;
}
void Textbox::clearString()
{
	textbox.setString("");
	text.str("");
	isSelected = false;
}
void Textbox::setSelected(bool sel)
{
	isSelected = sel;
	if (!sel)
	{
		std::string t = text.str();
		std::string newT = "";
		if (text.str().length() <= limit)
		{
			for (int i = 0; i < t.length(); i++)
			{
				newT += t[i];
			}
			textbox.setString(newT);
		}
		else
		{
			for (int i = 0; i <= limit; i++)
			{
				newT += t[i];
			}
			textbox.setString(newT);
		}
	}
}
void Textbox::newstring(std::string t)
{
	textbox.setString(t);
}
std::string Textbox::getText()
{
	std::string t = text.str();
	return t;
}
void Textbox::newstring2(std::string t)
{
	textbox.setString(t);
	text.str("");
	text << t;
}
void Textbox::draw(sf::RenderWindow &window)
{
	window.draw(textbox);
}
void Textbox::typeOn(sf::Event input)
{
	if (isSelected)
	{
		int chartype = input.text.unicode;
		if (chartype < 128)
		{
			if (hasLimit)
			{
				if (text.str().length() <= limit)
				{
					inputLogic(chartype);
				}
				else if (text.str().length() > limit && chartype == DELETE_KEY)
				{
					deleteChar();
				}
			}
			else
			{
				if (text.str().length() <= limit)
				{
					inputLogic(chartype);
				}
				else if (textbox.getGlobalBounds().width > limit)
				{
					inputLength(chartype);
				}
			}
		}
	}
}
void Textbox::setscaleAndOut(float size, int x, int y, int z)
{
	textbox.setOutlineColor(sf::Color(x, y, z));
	textbox.setOutlineThickness(size);
}
bool Textbox::isMouseOver(sf::RenderWindow &window)
{
	float mouseX = sf::Mouse::getPosition(window).x;
	float mouseY = sf::Mouse::getPosition(window).y;

	float buttonX = textbox.getPosition().x;
	float buttonY = textbox.getPosition().y;

	float buttonWidth = textbox.getPosition().x + textbox.getGlobalBounds().width;
	float buttonHeight = textbox.getPosition().y + textbox.getGlobalBounds().height;

	if (mouseX < buttonWidth && mouseX > buttonX && mouseY < buttonHeight && mouseY > buttonY)
		return true;
	return false;
}
bool Textbox::isKickMouse(sf::RenderWindow &window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		float mouseX = sf::Mouse::getPosition(window).x;
		float mouseY = sf::Mouse::getPosition(window).y;

		float buttonX = textbox.getPosition().x;
		float buttonY = textbox.getPosition().y;

		float buttonWidth = textbox.getPosition().x + textbox.getGlobalBounds().width;
		float buttonHeight = textbox.getPosition().y + textbox.getGlobalBounds().height;

		if (mouseX < buttonWidth && mouseX > buttonX && mouseY < buttonHeight && mouseY > buttonY)
			return true;
		return false;
	}
}
void Textbox::inputLogic(int charType)
{
	if (charType != DELETE_KEY && charType != ENTER_KEY && charType != ESCAPE_KEY)
	{
		text << static_cast<char>(charType);
	}
	else if (charType == DELETE_KEY)
	{
		if (text.str().length() > 0)
		{
			deleteChar();
		}
	}
	textbox.setString(text.str() + "_");
}
void Textbox::inputLength(int chartype)
{
	int z = text.str().length() - limit;
	if (chartype != DELETE_KEY && chartype != ENTER_KEY && chartype != ESCAPE_KEY)
	{
		text << static_cast<char>(chartype);
	}
	else if (chartype == DELETE_KEY)
	{
		if (text.str().length() > 0)
		{
			deleteChar();
		}
	}
	std::string t = text.str();
	std::string newT = "";
	for (int i = 0 + z; i < t.length(); i++)
	{
		newT += t[i];
	}
	textbox.setString(newT + "_");
}
void Textbox::deleteChar()
{
	std::string t = text.str();
	std::string newT = "";
	for (int i = 0; i < t.length() - 1; i++)
	{
		newT += t[i];
	}
	text.str("");
	text << newT;
	textbox.setString(text.str());
}