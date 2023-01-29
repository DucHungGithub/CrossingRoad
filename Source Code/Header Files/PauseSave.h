#pragma once

#include <iostream>
#include <string>

#include <SFML/Audio.hpp>
#include <Windows.h>

#include "../Header Files/GameData.h"
#include "../Header Files/MenuBox.h"
#include "../Header Files/Object.h"
#include "../Header Files/Traffic.h"
#include "../Header Files/LeaderBoard.h"


class PauseSave {
public:
	bool saveScreen(sf::Font& font, sf::Texture& Bgsave, GameData*& gameData, Max_Set& setting);
	void PauseScreen(sf::Font& font, sf::Texture& BgPause);
	//void playGameConsole(GameData &gameData, sf::Sound &music, sf::Font &font, sf::Texture &truck, sf::Texture &car, sf::Texture &bird, sf::Texture &dinosaur);
	//void gameDataScreen(sf::RenderWindow &window, sf::Font &font, Menu &mainMenu, sf::Texture &truck, sf::Texture &car, sf::Texture &bird, sf::Texture &dinosaur);
	bool khungDia(sf::Font& font, sf::Texture& Bgsave, sf::Texture& ma);
	void SettingScreen(sf::Font& font, sf::Texture& Bgsave, Max_Set& set, sf::Sound& soundtrack1);
	bool nhapten(sf::Font& font, sf::Texture& Bgsave, std::string& tenNhanVat);
	void thanhtichScreen(sf::Font& font, sf::Texture& Bgsave);
	bool huongdan(sf::Font& font, sf::Texture& Bgsave);
	void wingame(sf::Font& font, sf::Texture& Bgsave);
};
//bool saveScreen(sf::Font& font, sf::Texture& Bgsave, GameData*& gameData,Max_Set& setting);
//void PauseScreen(sf::Font& font, sf::Texture& BgPause);
////void playGameConsole(GameData &gameData, sf::Sound &music, sf::Font &font, sf::Texture &truck, sf::Texture &car, sf::Texture &bird, sf::Texture &dinosaur);
////void gameDataScreen(sf::RenderWindow &window, sf::Font &font, Menu &mainMenu, sf::Texture &truck, sf::Texture &car, sf::Texture &bird, sf::Texture &dinosaur);
//bool khungDia(sf::Font& font, sf::Texture& Bgsave, sf::Texture& ma);
//void SettingScreen(sf::Font& font, sf::Texture& Bgsave,Max_Set& set, sf::Sound& soundtrack1);
//bool nhapten(sf::Font& font, sf::Texture& Bgsave, std::string& tenNhanVat);
//void thanhtichScreen(sf::Font& font, sf::Texture& Bgsave);
//bool huongdan(sf::Font& font, sf::Texture& Bgsave);
