#pragma once

#include <SFML/Graphics.hpp>

extern const std::string resourceDirectory;
extern const std::string audioDirectory;
extern const std::string textureDirectory;

class GameTexture {
public:
	sf::Texture mainMenu;
	sf::Texture game;
	sf::Texture game1;
	
	sf::Texture Bgdie;
	sf::Texture ma;
	sf::Texture BgPause;
	sf::Texture Bgsave;
	sf::Texture money;
	sf::Texture setting;
	sf::Texture khungnhapten;
	sf::Texture instruction;

	sf::Texture dendo;
	sf::Texture denxanh;

	sf::Texture character;
	sf::Texture characterNu;
	sf::Texture truck;
	sf::Texture car;
	sf::Texture bird;
	sf::Texture dinosaur;
	sf::Font font;
	sf::Texture thanhtich;
	sf::Texture wingame;

	

	GameTexture() {
		mainMenu.loadFromFile(textureDirectory + "main_menu.png");
		game.loadFromFile(textureDirectory + "game.png");
		game1.loadFromFile(textureDirectory + "view2.png");

		Bgdie.loadFromFile(textureDirectory + "khungdie.png");
		ma.loadFromFile(textureDirectory + "ma1.jpg");
		BgPause.loadFromFile(textureDirectory + "pause_menu1.png");
		Bgsave.loadFromFile(textureDirectory + "save_menu.png");
		money.loadFromFile(textureDirectory + "tien.png");
		dendo.loadFromFile(textureDirectory + "dendo.png");
		denxanh.loadFromFile(textureDirectory + "denxanh.png");
		setting.loadFromFile(textureDirectory + "setting.png");
		khungnhapten.loadFromFile(textureDirectory + "khungten.png");
		thanhtich.loadFromFile(textureDirectory + "thanhtich.jpg");
		instruction.loadFromFile(textureDirectory + "instruction.png");

		character.loadFromFile(textureDirectory + "copy2.png");
		characterNu.loadFromFile(textureDirectory + "nu.png");
		truck.loadFromFile(textureDirectory + "truck1.png");
		car.loadFromFile(textureDirectory + "car1.png");
		bird.loadFromFile(textureDirectory + "chim1.png");
		dinosaur.loadFromFile(textureDirectory + "khunglong.png");

		font.loadFromFile(resourceDirectory + "font.ttf");
		
		wingame.loadFromFile(textureDirectory + "wingame.jpg");
		
	}
};