#include "../Header Files/GameData.h"
#include "../Header Files/PauseSave.h"
#include <string.h>

bool cmpVechicle(Vehicle a, Vehicle b) {
	return a.getPosition().x < b.getPosition().x;
}

bool cmpAnimal(Animal a, Animal b) {
	return a.getPosition().x < b.getPosition().x;
}

GameData::GameData(GameTexture* texture,bool check,Max_Set& setting) : level(0) {
	gameTexture = texture;

	nam_nu=setting.nam_nu;
	music = setting.music;
	view = setting.view;
	if (!view)
		shape.setTexture(gameTexture->game);
	else
		shape.setTexture(gameTexture->game1);
	ScoreText.setPosition({ 10.f, 30.f });
	ScoreText.setFont(gameTexture->font);
	ScoreText.setCharacterSize(15);
	ScoreText.setFillColor(sf::Color(255,28,3));
	levelText.setPosition({ 10.f, 0.f });
	levelText.setFont(gameTexture->font);
	levelText.setCharacterSize(15);
	levelText.setFillColor(sf::Color(255, 28, 3));
	if(check)
		levelText.setString("Press W, A, S, D to start!");
	else
		levelText.setString("Level: " + std::to_string(level));
	if (!nam_nu)
		character = new PlayerCharacter(gameTexture->character, { 700.f, 450.f }, true,check);
	else
		character = new PlayerCharacterNu(gameTexture->characterNu, { 700.f, 450.f }, true,check);


	border = gameTexture->game.getSize();
}

GameData::~GameData() {
	delete character;
}
int GameData::getLevel()
{
	return level;
}
void GameData::moveCharacter(std::string direction, sf::RenderWindow& window) {
	if (direction == "Forward") {
		character->moveForward(forwardOffset, speed, border);
	}
	else if (direction == "Backward") {
		character->moveBackward(backwardOffset, speed, border);
	}
	else if (direction == "Left") {
		character->moveLeft(leftOffset, speed, border);
	}
	else if (direction == "Right") {
		character->moveRight(rightOffset, speed, border);
	}

	// Check whether the character has reached the top of the screen, therefore should level up
	if (character->hasReachedTheTop) {
		levelUp(window);
	}
};

void GameData::levelUp(sf::RenderWindow& window) {
	level += 1;
	character->AddScore(100);
	character->levelUp();
	UpdateScoretext();
	srand(time(NULL));
	addTruck(gameTexture->truck, 1);
	addCar(gameTexture->car, 1);
	addBird(gameTexture->bird, 1);
	addDinosaur(gameTexture->dinosaur, 1);
	current_money = 15;
	prepareMoney(gameTexture->money, current_money);
	levelText.setString("Level: " + std::to_string(level));
	if (level != 1)
	{
		window.clear();
		window.display();
	}
	Sleep(200);
}

void GameData::moveObstacles(TrafficLight& TrucksLight, TrafficLight& CarsLight) {
	for (auto& money_o : moneyObject) {
		money_o.changeAction(49);
	}
	if (!TrucksLight.checkStop()) {
		for (auto& v_truck : listTrucks) {
			v_truck.move(defaultOffset, truckSpeed, border);
		};
	}
	if (!CarsLight.checkStop()) {
		for (auto& v_car : listCars) {
			v_car.move(defaultOffset, carSpeed, border);
		};
	}
	for (auto& v_bird : listBirds) {
		v_bird.move(defaultOffset, birdSpeed, border, 133);
	};
	for (auto& v_dinosaur : listDinosaurs) {
		v_dinosaur.move(defaultOffset, dinosaurSpeed, border, 90);
	};

	TrucksLight.update();
	CarsLight.update();
}

bool GameData::isCharacterCollided() {
	bool res = false;

	for (auto& v_truck : listTrucks) {
		res |= character->isCollidedWithObstacles(v_truck);

		if (res) return res;
	}

	for (auto& v_car : listCars) {
		res |= character->isCollidedWithObstacles(v_car);

		if (res) return res;
	}

	for (auto& v_bird : listBirds) {
		res |= character->isCollidedWithObstacles(v_bird);

		if (res) return res;
	}

	for (auto& v_dinosaur : listDinosaurs) {
		res |= character->isCollidedWithObstacles(v_dinosaur);

		if (res) return res;
	}
	for (int i = 0; i < moneyObject.size(); i++) {
		res |= character->isCollidedWithObstacles(moneyObject[i]);

		if (res) {
			moneyObject.erase(moneyObject.begin() + i);
			current_money--;
			character->AddScore(10);
			UpdateScoretext();
		}
		res = false;
	}

	return res;
}
void GameData::prepareMoney(sf::Texture& texture, int numadd)
{
	srand(time(NULL));
	float arrPos[] = { 50.f,160.f,290.f,380.f };
	moneyObject.clear();
	float xStartPos = float(rand() % border.x);

	for (int i = 0; i < numadd; i++)
	{
		float dist = (float)border.x / (i + numadd);
		float yStartPos = arrPos[rand() % 4];
		sf::Vector2f startPos = { xStartPos,yStartPos };
		moneyObject.push_back(Animal(texture, startPos, 15, 12, 36, 34));
		xStartPos += dist;
		xStartPos = int(xStartPos) % border.x;
	}

}

void GameData::addTruck(sf::Texture& texture, int numAdd) {
	int oldSize = listTrucks.size();
	listTrucks.clear();
	float xStartPos = float(rand() % border.x);
	float yStartPos = 50.f;
	float dist = (float)border.x / (oldSize + numAdd);
	//truckDis = dist;
	for (int i = 0; i < oldSize + numAdd; ++i) {
		sf::Vector2f startPos = { xStartPos, yStartPos };
		listTrucks.push_back(Vehicle(texture, startPos));
		xStartPos += dist;
	}
	truckDis = dist - listTrucks[0].getBoundingBox().width;
}

void GameData::addCar(sf::Texture& texture, int numAdd) {
	int oldSize = listCars.size();
	listCars.clear();

	float xStartPos = float(border.x % border.x);
	float yStartPos = 290.f;
	float dist = (float)border.x / (oldSize + numAdd);
	//carDis = dist;

	for (int i = 0; i < oldSize + numAdd; ++i) {
		sf::Vector2f startPos = { xStartPos, yStartPos };

		listCars.push_back(Vehicle(texture, startPos));
		xStartPos += dist;
	}

	carDis = dist - listCars[0].getBoundingBox().width;
}

void GameData::addBird(sf::Texture& texture, int numAdd) {
	int oldSize = listBirds.size();
	listBirds.clear();

	float xStartPos = 0.f;
	float yStartPos = 165.f;
	float dist = (float)border.x / (oldSize + numAdd);
	//birdDis = dist;

	for (int i = 0; i < oldSize + numAdd; ++i) {
		sf::Vector2f startPos = { xStartPos, yStartPos };

		listBirds.push_back(Animal(texture, startPos, 35, 33, 113, 60));
		xStartPos += dist;
	}

	birdDis = dist - listBirds[0].getBoundingBox().width;
}



void GameData::addDinosaur(sf::Texture& texture, int numAdd) {
	int oldSize = listDinosaurs.size();
	listDinosaurs.clear();

	float xStartPos = 0.f;
	float yStartPos = 380.f;
	float dist = (float)border.x / (oldSize + numAdd);
	//dinosaurDis = dist;

	for (int i = 0; i < oldSize + numAdd; ++i) {
		sf::Vector2f startPos = { xStartPos, yStartPos };

		listDinosaurs.push_back(Animal(texture, startPos, 230, 18, 72, 52));
		xStartPos += dist;
	}

	dinosaurDis = dist - listDinosaurs[0].getBoundingBox().width;
}

void GameData::draw(sf::RenderWindow& window, TrafficLight& TrucksLight, TrafficLight& CarsLight) {
	window.draw(shape);

	window.draw(levelText);
	window.draw(ScoreText);
	TrucksLight.draw(window);
	CarsLight.draw(window);

	for (auto money_o : moneyObject) {
		money_o.draw(window);
	}

	character->draw(window);
	sort(listBirds.begin(), listBirds.end(), cmpAnimal);
	sort(listDinosaurs.begin(), listDinosaurs.end(), cmpAnimal);
	sort(listCars.begin(), listCars.end(), cmpVechicle);
	sort(listTrucks.begin(), listTrucks.end(), cmpVechicle);

	for (auto v_truck : listTrucks) {
		v_truck.draw(window);
	}

	for (auto v_car : listCars) {
		v_car.draw(window);
	}

	/*for (auto v_bird : listBirds) {
		v_bird.draw(window);
	}

	for (auto v_dinosaur : listDinosaurs) {
		v_dinosaur.draw(window);
	}*/

	if (listBirds.size() <= 1) {
		for (auto v_bird : listBirds) {
			v_bird.draw(window);
		}
	}
	else {
		if (listBirds[1].getPosition().x - listBirds[0].getPosition().x >= birdDis) {
			listBirds[0].draw(window);
		}
		else {
			hideBird = true;
		}

		for (int i = 1; i < listBirds.size(); ++i)
			listBirds[i].draw(window);
	}

	if (listDinosaurs.size() <= 1) {
		for (auto v_dinosaur : listDinosaurs) {
			v_dinosaur.draw(window);
		}
	}
	else {
		if (listDinosaurs[1].getPosition().x - listDinosaurs[0].getPosition().x >= dinosaurDis) {
			listDinosaurs[0].draw(window);
		}
		else {
			hideDinosaur = true;
		}

		for (int i = 1; i < listDinosaurs.size(); ++i)
			listDinosaurs[i].draw(window);
	}

}

void GameData::setSpeed(float x) {
	truckSpeed = carSpeed = -x;
	birdSpeed = dinosaurSpeed = x;
	return;
}

void GameData::saveGameData(Max_Set& set) {
	std::ofstream fout(resourceDirectory + "game_data.txt");

	// 1 signifies the game save is valid, 0 is invalid
	fout << 1 << std::endl;
	fout<< set.music <<std::endl;
	fout<< set.nam_nu <<std::endl;
	fout<< set.view <<std::endl;
	fout<< level << std::endl;
	fout<< current_money<< std::endl;
	fout<< character->getScore()<<std::endl;
	fout<< listTrucks.size() << std::endl;
	fout<< listBirds.size() << std::endl;
	fout<< listCars.size() << std::endl;
	fout<< listDinosaurs.size() << std::endl;
	fout<< truckSpeed << std::endl;
	fout<< birdSpeed << std::endl;
	fout<< carSpeed << std::endl;
	fout << dinosaurSpeed <<std::endl;
	fout << character->name << std::endl;

	fout.close();
}
void GameData::UpdateScoretext() {
	ScoreText.setString("Score: " + std::to_string(character->getScore()));
}
bool GameData::loadGameData(Max_Set& set, std::ifstream& fin) {
	// Load the game save and set appropriate attributes
	int numTrucks, numBirds, numCars, numDinosaurs, score;
	fin >> level;
	fin >> current_money;
	fin >> score;
	fin >> numTrucks;
	fin >> numBirds;
	fin >> numCars;
	fin >> numDinosaurs;
	fin >> truckSpeed;
	fin >> birdSpeed;
	fin >> carSpeed;
	fin >> dinosaurSpeed;
	fin.ignore();
	std::getline(fin, character->name, '\n');


	addTruck(gameTexture->truck, numTrucks);
	addBird(gameTexture->bird, numBirds);
	addCar(gameTexture->car, numCars);
	addDinosaur(gameTexture->dinosaur, numDinosaurs);
	character->setScore(score);
	UpdateScoretext();
	levelText.setString("Level: " + std::to_string(level));
	prepareMoney(gameTexture->money, current_money);
	fin.close();

	// Reset the state of the game save
	std::ofstream fout(resourceDirectory + "game_data.txt");
	fout << 0;
	fout.close();
	return 1;
}
