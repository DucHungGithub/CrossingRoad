#include "../Header Files/PauseSave.h"


bool PauseSave::saveScreen(sf::Font &font, sf::Texture& Bgsave,GameData*& gameData,Max_Set& setting)
{
	
	sf::RenderWindow windowSave(sf::VideoMode(Bgsave.getSize().x, Bgsave.getSize().y), "SAVE", sf::Style::None);
	windowSave.setFramerateLimit(60);
	windowSave.setPosition({223, 100});
	sf::Sprite spriteBgSave;
	spriteBgSave.setTexture(Bgsave);

	Textbox noidungnhapKey(16, sf::Color::Red, false, font);
	noidungnhapKey.setPosition({328.f, 265.f});
	noidungnhapKey.newstring2(gameData->character->name);
	noidungnhapKey.setFont(font);
	noidungnhapKey.setLimit1(true, 12);

	Textbox noidungnhapKey1(16, sf::Color::White, false, font);
	noidungnhapKey1.setPosition({ 438.f, 215.f });
	std::string diem = std::to_string(gameData->character->getScore());
	if (diem == "-100")
		diem = "0";
	noidungnhapKey1.newstring(diem);
	noidungnhapKey1.setFont(font);
	noidungnhapKey1.setLimit1(true, 12);

	Textbox noidungnhapKey4(25, sf::Color::White, false, font);
	noidungnhapKey4.setPosition({ 243.f, 210.f });
	noidungnhapKey4.newstring("<<");
	noidungnhapKey4.setFont(font);

	while (windowSave.isOpen())
	{
		sf::Event eventSave;
		while (windowSave.pollEvent(eventSave))
		{

			if (eventSave.type == sf::Event::MouseMoved)
			{
				if (noidungnhapKey4.isMouseOver(windowSave))
				{
					noidungnhapKey4.setcolor(sf::Color::Red);
					noidungnhapKey4.setscaleAndOut(3.f, 245, 168, 154);
				}
				else
				{
					noidungnhapKey4.setcolor(sf::Color(132, 60, 12));
					noidungnhapKey4.setscaleAndOut(2.f, 238, 238, 238);
				}
			}
			else if (eventSave.type == sf::Event::TextEntered)
			{
				noidungnhapKey.typeOn(eventSave);
			}
			else if (eventSave.type == sf::Event::MouseButtonPressed)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					float mouseX = sf::Mouse::getPosition(windowSave).x;
					float mouseY = sf::Mouse::getPosition(windowSave).y;
					if (mouseX > 321 && mouseX < 656 && mouseY > 253 && mouseY < 291)
					{
						noidungnhapKey.setSelected(true);
					}
					else
						noidungnhapKey.setSelected(false);

					if (mouseX > 422 && mouseX < 489 && mouseY > 317 && mouseY < 364)
					{
						
						if (gameData->character->getScore() != -100)
						{
							gameData->character->name = noidungnhapKey.getText();
							gameData->saveGameData(setting);
						}
							
						windowSave.close();
						return false;
					}
					if (noidungnhapKey4.isKickMouse(windowSave))
						windowSave.close();
				}
			}
		}
		windowSave.clear();
		windowSave.draw(spriteBgSave);
		noidungnhapKey4.draw(windowSave);
		noidungnhapKey1.draw(windowSave);
		noidungnhapKey.draw(windowSave);
		windowSave.display();
	}
	return true;
}

void PauseSave::PauseScreen(sf::Font &font, sf::Texture& BgPause)
{
	
	sf::RenderWindow windowPause(sf::VideoMode(BgPause.getSize().x, BgPause.getSize().y), "PAUSE", sf::Style::None);
	windowPause.setFramerateLimit(60);
	windowPause.setPosition({490, 250});
	sf::Sprite spriteBgSave;
	spriteBgSave.setTexture(BgPause);

	while (windowPause.isOpen())
	{
		sf::Event eventSave;
		while (windowPause.pollEvent(eventSave))
		{
			if (eventSave.type == sf::Event::Closed)
			{
				windowPause.close();
			}
			else if (eventSave.type == sf::Event::EventType::KeyPressed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
					windowPause.close();
			}
			else if (eventSave.type == sf::Event::EventType::MouseButtonPressed)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					windowPause.close();
				}
			}
			
		}
		windowPause.clear();
		windowPause.draw(spriteBgSave);
		windowPause.display();
	}
}


bool PauseSave::khungDia(sf::Font& font, sf::Texture& Bgsave, sf::Texture& ma)
{
	
	sf::RenderWindow windowSave(sf::VideoMode(Bgsave.getSize().x, Bgsave.getSize().y), "DIE", sf::Style::None);
	windowSave.setFramerateLimit(60);
	windowSave.setPosition({ 320, 200 });
	sf::Sprite spriteBgSave;
	spriteBgSave.setTexture(Bgsave);


	
	sf::Sprite spritema;
	spritema.setTexture(ma);
	spritema.setTextureRect(sf::IntRect(32, 7, 144, 180));
	spritema.setPosition({ 255,100 });



	Textbox noidungnhapKey(30, sf::Color::White, false, font);
	noidungnhapKey.setPosition({ 118.f, 315.f });
	noidungnhapKey.newstring("RESTART");
	noidungnhapKey.setFont(font);
	noidungnhapKey.setLimit1(true, 12);

	Textbox noidungnhapKey1(30, sf::Color::White, false, font);
	noidungnhapKey1.setPosition({ 428.f, 315.f });
	noidungnhapKey1.newstring("ENDGAME");
	noidungnhapKey1.setFont(font);
	noidungnhapKey1.setLimit1(true, 12);

	int i = 0;
	int xtextTure = 0;
	while (windowSave.isOpen())
	{
		sf::Event eventSave;
		xtextTure = i / 25 % 3;
		xtextTure = 32 + xtextTure * 168;
		spritema.setTextureRect(sf::IntRect(xtextTure, 7, 178, 180));
		i++;
		if (i == 4000) i = 0;
	
		while (windowSave.pollEvent(eventSave))
		{
			if (eventSave.type == sf::Event::Closed)
			{
				windowSave.close();
				return false;
			}
			else if (eventSave.type == sf::Event::MouseButtonPressed)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (noidungnhapKey.isKickMouse(windowSave))
					{
						return true;
					}
					if (noidungnhapKey1.isKickMouse(windowSave))
					{
						return false;
					}
				}

				
			}
			else if (eventSave.type == sf::Event::MouseMoved)
			{
				if (noidungnhapKey.isMouseOver(windowSave))
					noidungnhapKey.setcolor(sf::Color::Red);
				else
					noidungnhapKey.setcolor(sf::Color::White);
				if (noidungnhapKey1.isMouseOver(windowSave))
					noidungnhapKey1.setcolor(sf::Color::Red);
				else
					noidungnhapKey1.setcolor(sf::Color::White);
			}
		}
		windowSave.clear();
		windowSave.draw(spriteBgSave);
		//nameUser.draw(windowSave);
		noidungnhapKey1.draw(windowSave);
		noidungnhapKey.draw(windowSave);
		windowSave.draw(spritema);
		windowSave.display();
	}
	return true;
}

void PauseSave::SettingScreen(sf::Font& font, sf::Texture& Bgsave, Max_Set& set, sf::Sound& soundtrack1)
{

	sf::RenderWindow windowSave(sf::VideoMode(Bgsave.getSize().x, Bgsave.getSize().y), "SETTING", sf::Style::None);
	windowSave.setFramerateLimit(60);
	windowSave.setPosition({ 270, 120 });
	sf::Sprite spriteBgSave;
	spriteBgSave.setTexture(Bgsave);
	
	std::string gender[] = { "boy","girl" };
	std::string view[] = { "urban" ,"rural" };
	std::string music[] = { "unmute","mute" };
	
	Textbox noidungnhapKey1(16, sf::Color::Red, false, font);
	noidungnhapKey1.setPosition({ 210.f, 200.f });
	noidungnhapKey1.newstring(gender[set.nam_nu]);
	noidungnhapKey1.setFont(font);
	


	Textbox noidungnhapKey2(16, sf::Color::Red, false, font);
	if(set.music)
		noidungnhapKey2.setPosition({ 643.f, 200.f });
	else
		noidungnhapKey2.setPosition({ 633.f, 200.f });
	noidungnhapKey2.newstring(music[set.music]);
	noidungnhapKey2.setFont(font);




	Textbox noidungnhapKey3(16, sf::Color::Red, false, font);
	noidungnhapKey3.setPosition({ 205.f, 353.f });
	noidungnhapKey3.newstring(view[set.view]);
	noidungnhapKey3.setFont(font);


	Textbox noidungnhapKey4(25, sf::Color::White, false, font);
	noidungnhapKey4.setPosition({ 613.f, 353.f });
	noidungnhapKey4.newstring("<<BACK");
	noidungnhapKey4.setFont(font);

	while (windowSave.isOpen())
	{
		sf::Event eventSave;
		while (windowSave.pollEvent(eventSave))
		{
			if (eventSave.type == sf::Event::MouseMoved)
			{
				if (noidungnhapKey4.isMouseOver(windowSave))
				{
					noidungnhapKey4.setcolor(sf::Color::Red);
					noidungnhapKey4.setscaleAndOut(3.f, 245, 168, 154);
				}
				else
				{
					noidungnhapKey4.setcolor(sf::Color(132, 60, 12));
					noidungnhapKey4.setscaleAndOut(2.f, 238, 238, 238);
				}
			}
			else if (eventSave.type == sf::Event::MouseButtonPressed)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					float mouseX = sf::Mouse::getPosition(windowSave).x;
					float mouseY = sf::Mouse::getPosition(windowSave).y;
					if (mouseX > 178 && mouseX < 272 && mouseY > 192 && mouseY < 228)
					{
						set.nam_nu ? set.nam_nu = false : set.nam_nu = true;
						noidungnhapKey1.newstring(gender[set.nam_nu]);
					}
					else if (mouseX > 618 && mouseX < 711 && mouseY > 192 && mouseY < 228)
					{
						if (set.music)
						{
							set.music = false;
							noidungnhapKey2.setPosition({ 633.f, 200.f });
							soundtrack1.play();
						}
						else
						{
							set.music = true;
							noidungnhapKey2.setPosition({ 643.f, 200.f });
							soundtrack1.stop();

						}

						noidungnhapKey2.newstring(music[set.music]);
					}
					else if (mouseX > 178 && mouseX < 272 && mouseY > 347 && mouseY < 379)
					{
						if (set.view)
						{
							set.view = false;
							noidungnhapKey3.setPosition({ 205.f, 353.f });
							
							
						}
						else
						{
							set.view = true;
							noidungnhapKey3.setPosition({ 210.f, 353.f });
							
						}
						noidungnhapKey3.newstring(view[set.view]);
					}
					else if (noidungnhapKey4.isKickMouse(windowSave))
						windowSave.close();
					
					
				}
			}
		}
		windowSave.clear();
		windowSave.draw(spriteBgSave);
		noidungnhapKey1.draw(windowSave);
		noidungnhapKey2.draw(windowSave);
		noidungnhapKey3.draw(windowSave);
		noidungnhapKey4.draw(windowSave);
		windowSave.display();
	}
}


bool PauseSave::nhapten(sf::Font& font, sf::Texture& Bgsave,std::string& tenNhanVat)
{

	sf::RenderWindow windowSave(sf::VideoMode(Bgsave.getSize().x, Bgsave.getSize().y), "SETTING", sf::Style::None);
	windowSave.setFramerateLimit(60);
	windowSave.setPosition({ 470, 320 });
	sf::Sprite spriteBgSave;
	spriteBgSave.setTexture(Bgsave);

	Textbox noidungnhapKey(20, sf::Color::Red, false, font);
	noidungnhapKey.setPosition({ 70.f, 130.f });
	noidungnhapKey.newstring(tenNhanVat);
	noidungnhapKey.setFont(font);
	noidungnhapKey.setLimit1(true, 12);

	Textbox noidungnhapKey4(25, sf::Color::White, false, font);
	noidungnhapKey4.setPosition({ 113.f, 200.f });
	noidungnhapKey4.newstring("<<BACK");
	noidungnhapKey4.setFont(font);

	Textbox noidungnhapKey5(25, sf::Color::White, false, font);
	noidungnhapKey5.setPosition({ 310.f, 200.f });
	noidungnhapKey5.newstring("NEXT>>");
	noidungnhapKey5.setFont(font);

	while (windowSave.isOpen())
	{
		sf::Event eventSave;
		while (windowSave.pollEvent(eventSave))
		{
			if (eventSave.type == sf::Event::MouseMoved)
			{
				if (noidungnhapKey4.isMouseOver(windowSave))
				{
					noidungnhapKey4.setcolor(sf::Color::Red);
					noidungnhapKey4.setscaleAndOut(3.f, 245, 168, 154);
				}
				else
				{
					noidungnhapKey4.setcolor(sf::Color(132, 60, 12));
					noidungnhapKey4.setscaleAndOut(2.f, 238, 238, 238);
				}
				if (noidungnhapKey5.isMouseOver(windowSave))
				{
					noidungnhapKey5.setcolor(sf::Color::Red);
					noidungnhapKey5.setscaleAndOut(3.f, 245, 168, 154);
				}
				else
				{
					noidungnhapKey5.setcolor(sf::Color(132, 60, 12));
					noidungnhapKey5.setscaleAndOut(2.f, 238, 238, 238);
				}
			}
			else if (eventSave.type == sf::Event::MouseButtonPressed)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					float mouseX = sf::Mouse::getPosition(windowSave).x;
					float mouseY = sf::Mouse::getPosition(windowSave).y;
					if (mouseX > 67 && mouseX < 445 && mouseY > 118 && mouseY < 167)
					{
						noidungnhapKey.clearString();
						noidungnhapKey.setSelected(true);
					}
					else
						noidungnhapKey.setSelected(false);
					if (noidungnhapKey4.isKickMouse(windowSave))
					{
						windowSave.close();
						return false;
					}
					if (noidungnhapKey5.isKickMouse(windowSave))
					{
						windowSave.close();
						tenNhanVat = noidungnhapKey.getText();
						if (tenNhanVat.empty())
							tenNhanVat = "Player";
						return true;
					}


				}
			}
			else if (eventSave.type == sf::Event::TextEntered)
			{
				noidungnhapKey.typeOn(eventSave);
			}
		}
		windowSave.clear();
		windowSave.draw(spriteBgSave);
		noidungnhapKey4.draw(windowSave);
		noidungnhapKey5.draw(windowSave);
		noidungnhapKey.draw(windowSave);
		windowSave.display();
	}
}


void PauseSave::thanhtichScreen(sf::Font& font, sf::Texture& Bgsave)
{

	sf::RenderWindow windowSave(sf::VideoMode(Bgsave.getSize().x, Bgsave.getSize().y), "ACHIEVEMENTS", sf::Style::None);
	windowSave.setFramerateLimit(60);
	windowSave.setPosition({ 270, 220 });
	sf::Sprite spriteBgSave;
	spriteBgSave.setTexture(Bgsave);

	Leaderboard* thanhtich = new Leaderboard;
	std::string padding1(12 - thanhtich->username[0].length(), '-');
	Textbox noidungnhapKey1(18, sf::Color::White, false, font);
	noidungnhapKey1.setPosition({ 320.f, 90.f });
	noidungnhapKey1.newstring(thanhtich->username[0]+padding1);
	noidungnhapKey1.setFont(font);
	Textbox noidungnhapKey11(18, sf::Color(255, 51, 0), false, font);
	noidungnhapKey11.setPosition({ 360.f, 110.f });
	noidungnhapKey11.newstring(std::to_string(thanhtich->totalscore[0]));
	noidungnhapKey11.setFont(font);
	noidungnhapKey11.setscaleAndOut(1.f, 0, 0, 0);

	std::string padding2(12 - thanhtich->username[1].length(), '-');
	Textbox noidungnhapKey2(18, sf::Color::White, false, font);
	noidungnhapKey2.setPosition({ 200.f, 130.f });
	noidungnhapKey2.newstring(thanhtich->username[1]+padding2);
	noidungnhapKey2.setFont(font);
	Textbox noidungnhapKey21(18, sf::Color(255, 51, 0), false, font);
	noidungnhapKey21.setPosition({ 240.f, 150.f });
	noidungnhapKey21.newstring(std::to_string(thanhtich->totalscore[1]));
	noidungnhapKey21.setFont(font);
	noidungnhapKey21.setscaleAndOut(1.f, 0, 0, 0);

	std::string padding3(12 - thanhtich->username[2].length(), '-');
	Textbox noidungnhapKey3(18, sf::Color::White, false, font);
	noidungnhapKey3.setPosition({ 450.f, 162.f });
	noidungnhapKey3.newstring(thanhtich->username[2]+padding3);
	noidungnhapKey3.setFont(font);
	Textbox noidungnhapKey31(18, sf::Color(255,51,0), false, font);
	noidungnhapKey31.setPosition({ 490.f, 182.f });
	noidungnhapKey31.newstring(std::to_string(thanhtich->totalscore[2]));
	noidungnhapKey31.setFont(font);
	noidungnhapKey31.setscaleAndOut(1.f, 0, 0, 0);


	Textbox noidungnhapKey4(25, sf::Color::White, false, font);
	noidungnhapKey4.setPosition({ 613.f, 353.f });
	noidungnhapKey4.newstring("<<BACK");
	noidungnhapKey4.setFont(font);

	while (windowSave.isOpen())
	{
		sf::Event eventSave;
		while (windowSave.pollEvent(eventSave))
		{
			if (eventSave.type == sf::Event::MouseMoved)
			{
				if (noidungnhapKey4.isMouseOver(windowSave))
				{
					noidungnhapKey4.setcolor(sf::Color::Red);
					noidungnhapKey4.setscaleAndOut(3.f, 245, 168, 154);
				}
				else
				{
					noidungnhapKey4.setcolor(sf::Color(132, 60, 12));
					noidungnhapKey4.setscaleAndOut(2.f, 238, 238, 238);
				}
			}
			else if (eventSave.type == sf::Event::MouseButtonPressed)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (noidungnhapKey4.isKickMouse(windowSave))
						windowSave.close();


				}
			}
		}
		windowSave.clear();
		windowSave.draw(spriteBgSave);
		noidungnhapKey1.draw(windowSave);
		noidungnhapKey11.draw(windowSave);
		noidungnhapKey2.draw(windowSave);
		noidungnhapKey21.draw(windowSave);

		noidungnhapKey3.draw(windowSave);
		noidungnhapKey31.draw(windowSave);
		noidungnhapKey4.draw(windowSave);
		windowSave.display();
	}
}



bool PauseSave::huongdan(sf::Font& font, sf::Texture& Bgsave)
{

	sf::RenderWindow windowSave(sf::VideoMode(Bgsave.getSize().x, Bgsave.getSize().y), "SETTING", sf::Style::None);
	windowSave.setFramerateLimit(60);
	windowSave.setPosition({ 470, 320 });
	sf::Sprite spriteBgSave;
	spriteBgSave.setTexture(Bgsave);



	Textbox noidungnhapKey4(25, sf::Color::White, false, font);
	noidungnhapKey4.setPosition({ 113.f, 200.f });
	noidungnhapKey4.newstring("<<EXIT");
	noidungnhapKey4.setFont(font);

	Textbox noidungnhapKey5(25, sf::Color::White, false, font);
	noidungnhapKey5.setPosition({ 310.f, 200.f });
	noidungnhapKey5.newstring("START>>");
	noidungnhapKey5.setFont(font);

	while (windowSave.isOpen())
	{
		sf::Event eventSave;
		while (windowSave.pollEvent(eventSave))
		{
			if (eventSave.type == sf::Event::MouseMoved)
			{
				if (noidungnhapKey4.isMouseOver(windowSave))
				{
					noidungnhapKey4.setcolor(sf::Color::Red);
					noidungnhapKey4.setscaleAndOut(3.f, 245, 168, 154);
				}
				else
				{
					noidungnhapKey4.setcolor(sf::Color(132, 60, 12));
					noidungnhapKey4.setscaleAndOut(2.f, 238, 238, 238);
				}
				if (noidungnhapKey5.isMouseOver(windowSave))
				{
					noidungnhapKey5.setcolor(sf::Color::Red);
					noidungnhapKey5.setscaleAndOut(3.f, 245, 168, 154);
				}
				else
				{
					noidungnhapKey5.setcolor(sf::Color(132, 60, 12));
					noidungnhapKey5.setscaleAndOut(2.f, 238, 238, 238);
				}
			}
			else if (eventSave.type == sf::Event::MouseButtonPressed)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					
	
					if (noidungnhapKey4.isKickMouse(windowSave))
					{
						windowSave.close();
						return false;
					}
					if (noidungnhapKey5.isKickMouse(windowSave))
					{
						windowSave.close();
						return true;
					}


				}
			}
		}
		windowSave.clear();
		windowSave.draw(spriteBgSave);
		noidungnhapKey4.draw(windowSave);
		noidungnhapKey5.draw(windowSave);
		windowSave.display();
	}
}

void PauseSave::wingame(sf::Font& font, sf::Texture& Bgsave)
{
	sf::RenderWindow windowPause(sf::VideoMode(Bgsave.getSize().x, Bgsave.getSize().y), "WIN", sf::Style::None);
	windowPause.setFramerateLimit(60);
	windowPause.setPosition({ 490, 150 });
	sf::Sprite spriteBgSave;
	spriteBgSave.setTexture(Bgsave);

	while (windowPause.isOpen())
	{
		sf::Event eventSave;
		while (windowPause.pollEvent(eventSave))
		{
			if (eventSave.type == sf::Event::Closed)
			{
				windowPause.close();
			}
			else if (eventSave.type == sf::Event::EventType::KeyPressed)
			{
				windowPause.close();
			}
			else if (eventSave.type == sf::Event::EventType::MouseButtonPressed)
			{
				windowPause.close();
			}

		}
		windowPause.clear();
		windowPause.draw(spriteBgSave);
		windowPause.display();
	}
}