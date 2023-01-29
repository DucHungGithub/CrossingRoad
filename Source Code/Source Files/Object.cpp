#include "../Header Files/Object.h"

Object::Object(const sf::Texture& texture) : m_startPos({ 0.f, 0.f }) {
	shape.setTexture(texture);
	shape.scale(0.9f, 0.9f);

	// Set starting position for newly created objects
	setPosition(m_startPos);
}

Object::Object(const sf::Texture& texture, const sf::Vector2f& startPos) : m_startPos(startPos) {
	shape.setTexture(texture);
	shape.scale(0.9f, 0.9f);

	// Set starting position for newly created objects
	setPosition(m_startPos);
}

sf::Vector2f Object::getPosition() {
	return shape.getPosition();
}

void Object::setPosition(sf::Vector2f pos) {
	shape.setPosition(pos);
}

// sf::Vector2u border is used to reset the obstacle's position when it goes out of border
void Object::move(sf::Vector2f offset, float speed, sf::Vector2u border) {
	shape.move(offset * speed);

	// Border checking
	sf::Vector2f currentPos = shape.getPosition();
	sf::FloatRect boundingBox = getBoundingBox();

	// Left border
	if (currentPos.x <= 0) {
		shape.setPosition(border.x-shape.getGlobalBounds().width, currentPos.y);
		//currentPos.x = border.x - boundingBox.width;
	}
	else if (currentPos.x + boundingBox.width > border.x) {
		shape.setPosition(0, currentPos.y);
		//currentPos.x = 0;
	}

	//shape.setPosition(currentPos);
}

sf::FloatRect Object::getBoundingBox() {
	return shape.getGlobalBounds();
}

void Object::draw(sf::RenderWindow& window) {
	window.draw(shape);
}


//Person
Person::Person(const sf::Texture& texture, bool state, bool state1) : m_startPos({ 0.f, 0.f }) {
	score = 0;
	name = "player";
	shape.setTexture(texture);
	shape.scale(0.9f, 0.9f);
	this->state = state;
	hasReachedTheTop = state1;
	// Set starting position for newly created objects
	setPosition(m_startPos);
}

Person::Person(const sf::Texture& texture, const sf::Vector2f& startPos, bool state, bool state1) : m_startPos(startPos) {
	score = -100;
	name = "Player";
	shape.setTexture(texture);
	shape.scale(0.9f, 0.9f);
	this->state = state;
	hasReachedTheTop = state1;
	// Set starting position for newly created objects
	setPosition(m_startPos);
}

void Person::AddScore(int x) {
	score += x;
}

int Person::getScore() {
	return score;
}

void Person::setScore(int x) {
	score = x;
}

sf::Vector2f Person::getPosition() {
	return shape.getPosition();
}

void Person::setPosition(sf::Vector2f pos) {
	shape.setPosition(pos);
}

// sf::Vector2u border is used to reset the obstacle's position when it goes out of border
void Person::move(sf::Vector2f offset, float speed, sf::Vector2u border) {
	shape.move(offset * speed);

	// Border checking
	sf::Vector2f currentPos = getPosition();
	sf::FloatRect boundingBox = getBoundingBox();

	// Left border
	if (currentPos.x < 0) {
		currentPos.x = border.x - boundingBox.width;
	}

	// Top border
	if (currentPos.y < 0) {
		currentPos.y = border.y - boundingBox.height;
	}

	// Right border
	if (currentPos.x + boundingBox.width > border.x) {
		currentPos.x = 0;
	}
	// Bottom border
	if (currentPos.y + boundingBox.height > border.y) {
		currentPos.y = 0;
	}

	setPosition(currentPos);
}

sf::FloatRect Person::getBoundingBox() {
	return shape.getGlobalBounds();
}

void Person::draw(sf::RenderWindow& window) {
	window.draw(shape);
}

// Class Animal
Animal::Animal(const sf::Texture& texture, const sf::Vector2f& startPos, int x1, int x2, int x3, int x4) : Object(texture, startPos) {
	x = x1;
	y = x2;
	width = x3;
	height = x4;
	timechange = 0;
	shape.setTextureRect(sf::IntRect(x, y, width, height));
}

void Animal::move(sf::Vector2f offset, float speed, sf::Vector2u border, int x_pos)
{
	sf::Vector2f currentPos = getPosition();
	int xTexture = (int)currentPos.x / 20 % 4;
	xTexture = x + x_pos * xTexture;
	shape.setTextureRect(sf::IntRect(xTexture, y, width, height));
	Object::move(offset, speed, border);
}

void Animal::changeAction(int x_pos)
{
	int xTexture = timechange / 5 % 6;
	xTexture = x + x_pos * xTexture;
	shape.setTextureRect(sf::IntRect(xTexture, y, width, height));
	timechange = (timechange + 1) % 1000;
}