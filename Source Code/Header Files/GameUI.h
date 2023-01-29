#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <Windows.h>

#include "../Header Files/GameTexture.h"
#include "../Header Files/GameData.h"
#include "../Header Files/MenuBox.h"
#include "../Header Files/Traffic.h"
#include "../Header Files/PauseSave.h"
#include "../Header Files/LeaderBoard.h"


class GameUI {
private:
	GameTexture* gameTexture = nullptr;
	PauseSave* ui = nullptr;
	sf::RenderWindow window;
	sf::Sound soundtrack1;
	sf::Sound soundtrack2;
	//sf::Sound soundtrack3;
	sf::SoundBuffer buffer1;
	sf::SoundBuffer buffer2;
	//sf::SoundBuffer buffer3;
public:

	GameUI();

	~GameUI();

	void mainMenuWindow(bool& active, Max_Set& setting);

	bool gameWindow(sf::RenderWindow& windowGame, GameData*& gameData, Max_Set& setting);
};

