#pragma once

#include <SFML/Graphics.hpp>

class Object {
protected:
	sf::Sprite shape;
	sf::Vector2f m_startPos;
public:

	Object(const sf::Texture& texture);

	Object(const sf::Texture& texture, const sf::Vector2f& startPos);

	sf::Vector2f getPosition();

	void setPosition(sf::Vector2f pos);

	// sf::Vector2u border is used to reset the obstacle's position when it goes out of border
	virtual void move(sf::Vector2f offset, float speed, sf::Vector2u border);

	sf::FloatRect getBoundingBox();

	void draw(sf::RenderWindow& window);
};

class Person {
protected:
	sf::Sprite shape;
	sf::Vector2f m_startPos;
	int score;
public:
	bool hasReachedTheTop = true;
	bool state;
	std::string name;

	Person(const sf::Texture& texture, bool state, bool state1);

	Person(const sf::Texture& texture, const sf::Vector2f& startPos, bool state, bool state1);

	void AddScore(int x);

	int getScore();

	void setScore(int x);

	sf::Vector2f getPosition();

	void setPosition(sf::Vector2f pos);

	// sf::Vector2u border is used to reset the obstacle's position when it goes out of border
	virtual void move(sf::Vector2f offset, float speed, sf::Vector2u border);

	virtual void moveForward(sf::Vector2f& offset, float& speed, sf::Vector2u& border) = 0;

	virtual void moveBackward(sf::Vector2f& offset, float& speed, sf::Vector2u& border) = 0;

	virtual void moveLeft(sf::Vector2f& offset, float& speed, sf::Vector2u& border) = 0;

	virtual void moveRight(sf::Vector2f& offset, float& speed, sf::Vector2u& border) = 0;

	virtual bool isCollidedWithObstacles(Object& obstacle) = 0;

	virtual void levelUp() = 0;

	sf::FloatRect getBoundingBox();

	void draw(sf::RenderWindow& window);
};

class Vehicle : public Object {
public:
	Vehicle(const sf::Texture& texture, const sf::Vector2f& startPos) : Object(texture, startPos) {}
};

class Animal : public Object {
private:
	int x;
	int y;
	int width;
	int height;
	int timechange;
public:
	Animal(const sf::Texture& texture, const sf::Vector2f& startPos, int x1, int x2, int x3, int x4);

	void move(sf::Vector2f offset, float speed, sf::Vector2u border, int x_pos);

	void changeAction(int x_pos);
};

