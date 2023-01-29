#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

#include "../Header Files/Object.h"

class PlayerCharacter : public Person {
public:
	PlayerCharacter(const sf::Texture& texture, bool state, bool state1);

	PlayerCharacter(const sf::Texture& texture, const sf::Vector2f& startPos, bool state, bool state1);

	~PlayerCharacter();

	// sf::Vector2u border is used to reset the obstacle's position when it goes out of border
	void move(sf::Vector2f& offset, float& speed, sf::Vector2u& border) {
		shape.move(offset * speed);

		// Border checking
		sf::Vector2f currentPos = getPosition();
		sf::FloatRect boundingBox = getBoundingBox();

		// Left border
		if (currentPos.x < 0) {
			currentPos.x = 0;
		}

		// Top border
		if (currentPos.y < 0) {
			hasReachedTheTop = true;
		}

		// Right border
		if (currentPos.x + boundingBox.width > border.x) {
			currentPos.x = border.x - boundingBox.width;
		}
		// Bottom border
		if (currentPos.y + boundingBox.height > border.y) {
			currentPos.y = border.y - boundingBox.height;
		}

		setPosition(currentPos);
	}

	void moveForward(sf::Vector2f& offset, float& speed, sf::Vector2u& border) {
		int xTexture = 0;
		xTexture = (int)getPosition().y / 10 % 3;
		xTexture = 8 + xTexture * 47;
		shape.setTextureRect(sf::IntRect(xTexture, 147, 32, 45));

		move(offset, speed, border);
	}

	void moveBackward(sf::Vector2f& offset, float& speed, sf::Vector2u& border) {
		int xTexture = 0;
		xTexture = (int)getPosition().y / 10 % 3;
		xTexture = 8 + xTexture * 47;
		shape.setTextureRect(sf::IntRect(xTexture, 5, 32, 45));

		move(offset, speed, border);
	}

	void moveLeft(sf::Vector2f& offset, float& speed, sf::Vector2u& border) {
		int xTexture = 0;
		xTexture = (int)getPosition().x / 10 % 3;
		xTexture = 8 + xTexture * 47;
		shape.setTextureRect(sf::IntRect(xTexture, 52, 32, 45));

		move(offset, speed, border);
	}

	void moveRight(sf::Vector2f& offset, float& speed, sf::Vector2u& border) {
		int xTexture = 0;
		xTexture = (int)shape.getPosition().x / 10 % 3;
		xTexture = 8 + xTexture * 47;
		shape.setTextureRect(sf::IntRect(xTexture, 100, 32, 45));

		move(offset, speed, border);
	}

	sf::FloatRect getBoundingBox() {
		return shape.getGlobalBounds();
	}

	bool isCollidedWithObstacles(Object& obstacle) {
		return this->getBoundingBox().intersects(obstacle.getBoundingBox());
	}

	void levelUp() {
		setPosition(m_startPos);
		hasReachedTheTop = false;
	}
};

class PlayerCharacterNu : public Person {
public:

	PlayerCharacterNu(const sf::Texture& texture,bool state,bool state1) : Person(texture,state,state1) {
		shape.setTextureRect(sf::IntRect(13, 2, 30, 45));
	}

	PlayerCharacterNu(const sf::Texture& texture, const sf::Vector2f& startPos,bool state,bool state1) : Person(texture, startPos,state,state1) {
		shape.setTextureRect(sf::IntRect(13, 2, 30, 45));
	}

	~PlayerCharacterNu() {
		std::cout << "Die" << std::endl;
	}

	// sf::Vector2u border is used to reset the obstacle's position when it goes out of border
	void move(sf::Vector2f& offset, float& speed, sf::Vector2u& border) {
		shape.move(offset * speed);

		// Border checking
		sf::Vector2f currentPos = getPosition();
		sf::FloatRect boundingBox = getBoundingBox();

		// Left border
		if (currentPos.x < 0) {
			currentPos.x = 0;
		}

		// Top border
		if (currentPos.y < 0) {
			hasReachedTheTop = true;
		}

		// Right border
		if (currentPos.x + boundingBox.width > border.x) {
			currentPos.x = border.x - boundingBox.width;
		}
		// Bottom border
		if (currentPos.y + boundingBox.height > border.y) {
			currentPos.y = border.y - boundingBox.height;
		}

		setPosition(currentPos);
	}

	void moveForward(sf::Vector2f& offset, float& speed, sf::Vector2u& border) {
		int xTexture = 0;
		xTexture = (int)getPosition().y / 10 % 3;
		xTexture = 13 + xTexture * 47;
		shape.setTextureRect(sf::IntRect(xTexture, 144, 30, 45));

		move(offset, speed, border);
	}

	void moveBackward(sf::Vector2f& offset, float& speed, sf::Vector2u& border) {
		int xTexture = 0;
		xTexture = (int)getPosition().y / 10 % 3;
		xTexture = 13 + xTexture * 47;
		shape.setTextureRect(sf::IntRect(xTexture, 2, 30, 45));

		move(offset, speed, border);
	}

	void moveLeft(sf::Vector2f& offset, float& speed, sf::Vector2u& border) {
		int xTexture = 0;
		xTexture = (int)getPosition().x / 10 % 3;
		xTexture = 13 + xTexture * 47;
		shape.setTextureRect(sf::IntRect(xTexture, 50, 30, 45));

		move(offset, speed, border);
	}

	void moveRight(sf::Vector2f& offset, float& speed, sf::Vector2u& border) {
		int xTexture = 0;
		xTexture = (int)shape.getPosition().x / 10 % 3;
		xTexture = 13 + xTexture * 47;
		shape.setTextureRect(sf::IntRect(xTexture, 96, 30, 45));

		move(offset, speed, border);
	}

	sf::FloatRect getBoundingBox() {
		return shape.getGlobalBounds();
	}

	bool isCollidedWithObstacles(Object& obstacle) {
		return this->getBoundingBox().intersects(obstacle.getBoundingBox());
	}

	void levelUp() {
		setPosition(m_startPos);
		hasReachedTheTop = false;
	}
};

