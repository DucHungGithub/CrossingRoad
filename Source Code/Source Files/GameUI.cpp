#include "../Header Files/GameUI.h"

	GameUI::GameUI() 
	{
		gameTexture = new GameTexture();
		

		// Set up the soundtracks

		if (buffer1.loadFromFile(audioDirectory + "music_main_menu.wav")) {
			soundtrack1.setBuffer(buffer1);
		}
		soundtrack1.setVolume(10.f);
		soundtrack1.setLoop(true);

		if (buffer2.loadFromFile(audioDirectory + "music_game.wav")) {
			soundtrack2.setBuffer(buffer2);
		}
		soundtrack2.setVolume(15.f);
		soundtrack2.setLoop(true);

		/*if (buffer3.loadFromFile(audioDirectory + "nutdichuyen.wav")) {
			soundtrack3.setBuffer(buffer3);
		}
		soundtrack3.setVolume(40.f);
		soundtrack3.setLoop(true);*/

		ui = new PauseSave();
	}

    GameUI::~GameUI()
    {
        delete gameTexture;
        delete ui;
    }
    
    void GameUI::mainMenuWindow(bool& active,Max_Set& setting) {
		window.create(sf::VideoMode(893, 504), "Crossing Road", sf::Style::None);
		window.setFramerateLimit(60);
		
		Menu mainMenu(gameTexture->mainMenu, sf::Vector2f(0.f, 0.f), gameTexture->font);
		while (window.isOpen()) {
			if ((soundtrack1.getStatus() == sf::SoundSource::Status::Stopped) && setting.music == 0) {
				soundtrack1.play();
			}
			sf::Event event;

			while (window.pollEvent(event)) {
				if (event.type == sf::Event::EventType::Closed) {
					window.close();
					active = false;
				}
				else if (event.type == sf::Event::EventType::MouseMoved) {
					for (int i = 0; i < 5; i++) {
						if (mainMenu._menuChoose[i].isMouseOver(window)) {
							mainMenu._menuChoose[i].setcolor(sf::Color::Red);
							mainMenu._menuChoose[i].setscaleAndOut(3.f, 245, 168, 154);
						}
						else {
							mainMenu._menuChoose[i].setcolor(sf::Color(132, 60, 12));
							mainMenu._menuChoose[i].setscaleAndOut(2.f, 238, 238, 238);
						}
					}
				}
				else if (event.type == sf::Event::EventType::MouseButtonPressed) {
					// Navigate to game window
					if (mainMenu._menuChoose[0].isKickMouse(window)) {
						soundtrack1.stop();
						bool check = true;
						do
						{
							GameData* gameData = new GameData(gameTexture,true,setting);
							gameData = new GameData(gameTexture, true, setting);
							bool checkStart = ui->nhapten(gameTexture->font, gameTexture->khungnhapten, gameData->character->name);
							if (!checkStart)
							{
								delete gameData;
								gameData = nullptr;
								break;
							}
							checkStart = ui->huongdan(gameTexture->font, gameTexture->instruction);
							if (!checkStart)
							{
								delete gameData;
								gameData = nullptr;
								break;
							}
							sf::RenderWindow windowGame;
							check=gameWindow(windowGame,gameData,setting);
						} while (check);
					}
					else if (mainMenu._menuChoose[1].isKickMouse(window)) {
						soundtrack1.stop();
						bool check = true;
						do
						{
							bool isGameSaveValid;
							std::ifstream fin(resourceDirectory + "game_data.txt");
							if (!fin.is_open())
								isGameSaveValid = false;
							fin >> isGameSaveValid;
							GameData* gameData = nullptr;
		
							if (!isGameSaveValid)
							{
								fin.close();
								gameData = new GameData(gameTexture, true, setting);
								bool checkStart = ui->nhapten(gameTexture->font, gameTexture->khungnhapten, gameData->character->name);
								if (!checkStart)
								{
									delete gameData;
									gameData = nullptr;
									break;
								}
								checkStart = ui->huongdan(gameTexture->font, gameTexture->instruction);
								if (!checkStart)
								{
									delete gameData;
									gameData = nullptr;
									break;
								}
							}
							else
							{
								fin >> setting.music;
								fin >> setting.nam_nu;
								fin >> setting.view;
								gameData = new GameData(gameTexture, false,setting);
								gameData->loadGameData(setting,fin);
							}
							
							sf::RenderWindow windowGame;
							check = gameWindow(windowGame, gameData, setting);
							
						} while (check);
					}
					else if (mainMenu._menuChoose[2].isKickMouse(window))
					{
						window.close();
						ui->SettingScreen(gameTexture->font, gameTexture->setting,setting, soundtrack1);
					}
					else if (mainMenu._menuChoose[3].isKickMouse(window))
					{
						window.close();
						ui->thanhtichScreen(gameTexture->font, gameTexture->thanhtich);
					}
					else if (mainMenu._menuChoose[4].isKickMouse(window)) {
						window.close();
						active = false;
					}
				}
			}

			window.clear();

			window.draw(mainMenu._screen);
			for (int i = 0; i < 5; i++)
				mainMenu._menuChoose[i].draw(window);
			window.display();
		}
	}

    bool GameUI::gameWindow(sf::RenderWindow &windowGame, GameData *&gameData, Max_Set &setting)
    {

        windowGame.create(sf::VideoMode(916, 505), "Crossing Road", sf::Style::None);
        windowGame.setFramerateLimit(60);

        TrafficLight TrucksLight(gameTexture->dendo, gameTexture->denxanh, 574.f, 10.f);
        TrafficLight CarsLight(gameTexture->dendo, gameTexture->denxanh, 235.f, 230.f);

        while (windowGame.isOpen() && gameData->character->state)
        {
			if (gameData->getLevel() == 6)
			{
				Leaderboard* bangxephang = new Leaderboard;
				bangxephang->LoadLeaderboard();
				bangxephang->AddtoLeaderboard(gameData->character->name, gameData->character->getScore());
				bangxephang->SaveLeaderboard();
				delete bangxephang;
				ui->wingame(gameTexture->font, gameTexture->wingame);
				soundtrack2.stop();
				delete gameData;
				gameData = nullptr;
				return false;
			}
            if ((soundtrack2.getStatus() == sf::SoundSource::Status::Stopped) && setting.music == 0)
            {
                soundtrack2.play();
            }
            sf::Event eventPlay;
            while (windowGame.pollEvent(eventPlay))
            {
                if (eventPlay.type == sf::Event::EventType::KeyPressed)
                {
                    // Handle the character's movement
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                    {
                        gameData->moveCharacter("Forward", windowGame);
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                    {
                        gameData->moveCharacter("Backward", windowGame);
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                    {
                        gameData->moveCharacter("Left", windowGame);
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                    {
                        gameData->moveCharacter("Right", windowGame);
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
                    {
                        ui->PauseScreen(gameTexture->font, gameTexture->BgPause);
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
                    {
                        soundtrack2.stop();
                        bool checkSave = ui->saveScreen(gameTexture->font, gameTexture->Bgsave, gameData, setting);
                        if (!checkSave)
                        {
                            windowGame.close();
                            delete gameData;
                            gameData = nullptr;
                            soundtrack2.stop();
                            return false;
                        }
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    {
                        gameData->saveGameData(setting);
                        windowGame.close();
                        delete gameData;
                        gameData = nullptr;
                        soundtrack2.stop();
                        return false;
                    }
                }
            }
            // Handle the obstacles' movement
            gameData->moveObstacles(TrucksLight, CarsLight);

            // Collision detection
            bool playerHit = gameData->isCharacterCollided();
            if (playerHit)
            {
                Leaderboard *bangxephang = new Leaderboard;
                bangxephang->LoadLeaderboard();
                bangxephang->AddtoLeaderboard(gameData->character->name, gameData->character->getScore());
                bangxephang->SaveLeaderboard();
                delete bangxephang;
                soundtrack2.stop();
                bool check = ui->khungDia(gameTexture->font, gameTexture->Bgdie, gameTexture->ma);
                if (check)
                {
                    delete gameData;
                    gameData = nullptr;
                    return true;
                }
                else
                {
                    delete gameData;
                    gameData = nullptr;
                    return false;
                }
            }

            // Clear, draw and update the window
            windowGame.clear();

            gameData->draw(windowGame, TrucksLight, CarsLight);

            windowGame.display();
        }
    }

