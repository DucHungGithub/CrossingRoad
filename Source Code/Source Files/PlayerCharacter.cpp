#include "../Header Files/PlayerCharacter.h"
#include "../Header Files/GameData.h"

PlayerCharacter::PlayerCharacter(const sf::Texture& texture, bool state, bool state1) : Person(texture, state, state1) {
	shape.setTextureRect(sf::IntRect(8, 100, 32, 45));
}

PlayerCharacter::PlayerCharacter(const sf::Texture& texture, const sf::Vector2f& startPos, bool state, bool state1) : Person(texture, startPos, state, state1) {
	shape.setTextureRect(sf::IntRect(8, 100, 32, 45));
}

PlayerCharacter::~PlayerCharacter() {
	std::cout << "Die" << std::endl;
}