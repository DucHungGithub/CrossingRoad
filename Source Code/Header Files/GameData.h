#pragma once

#include <SFML/Graphics.hpp>

#include <fstream>
#include <vector>
#include <cstdlib>

#include "../Header Files/GameTexture.h"
#include "../Header Files/PlayerCharacter.h"
#include "../Header Files/Object.h"
#include "../Header Files/Traffic.h"
#include <Windows.h>



class Max_Set
{
public:
	int music=0;
	int nam_nu=0;
	int view=0;
	static Max_Set& getmaxset()
	{
		static Max_Set maxset;
		return maxset;
	}
private:
	Max_Set()
	{
		music = 0;
		nam_nu = 0;
		view = 0;
	}
	
};

class GameData {
private:
	sf::Sprite shape;
	
	GameTexture* gameTexture = nullptr;

	// Screen width and height
	sf::Vector2u border;

	// Level text
	sf::Text levelText;

	sf::Text ScoreText;
	int level;

	// Attributes for objects' movement
	sf::Vector2f defaultOffset = { 5.0f, 0.0f };

	sf::Vector2f forwardOffset = { 0.0f, -15.0f };
	sf::Vector2f backwardOffset = { 0.0f, 15.0f };
	sf::Vector2f leftOffset = { -15.0f, 0.0f };
	sf::Vector2f rightOffset = { 15.0f, 0.0f };

	float speed = 1.0f;
	float truckSpeed = -0.5f;
	float birdSpeed = 0.5f;
	float carSpeed = -0.5f;
	float dinosaurSpeed = 0.5f;
	float truckDis = -1.f, birdDis = -1.f, carDis = -1.f, dinosaurDis = -1.f;
	bool hideTruck = false, hideCar = false, hideBird = false, hideDinosaur = false;

	
	int current_money = 15;
	bool nam_nu;
	bool view;
	bool music;

	std::vector<Vehicle> listTrucks;
	std::vector<Vehicle> listCars;
	std::vector<Animal> listBirds;
	std::vector<Animal> listDinosaurs;
	std::vector<Animal> moneyObject;
	

public:
	Person* character = nullptr;

	GameData(GameTexture* texture,bool check,Max_Set& setting);

	~GameData();
	int getLevel();

	void moveObstacles(TrafficLight& TrucksLight, TrafficLight& CarsLight);

	void moveCharacter(std::string direction, sf::RenderWindow& window);

	void levelUp(sf::RenderWindow& window);

	bool isCharacterCollided();

	void prepareMoney(sf::Texture& texture, int numAdd);

	void addTruck(sf::Texture& texture, int numAdd);


	void addBird(sf::Texture& texture, int numAdd);

	void addCar(sf::Texture& texture, int numAdd);

	void addDinosaur(sf::Texture& texture, int numAdd);

	void draw(sf::RenderWindow& window, TrafficLight& TrucksLight, TrafficLight& CarsLight);

	void UpdateScoretext();


	void setSpeed(float x);

	void saveGameData(Max_Set& set);

	bool loadGameData(Max_Set& set,std::ifstream& fin);

	/*void setSpeed(float x);*/
};
