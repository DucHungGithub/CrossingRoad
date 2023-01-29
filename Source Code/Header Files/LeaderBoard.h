#pragma once
#include <iostream>
#include <string.h>
#include "../Header Files/GameTexture.h"
class Leaderboard {
public:
	int num;
	std::string username[3];
	int totalscore[3];
	Leaderboard();
	void LoadLeaderboard();
	void AddtoLeaderboard(std::string usn, int score);
	void SaveLeaderboard();
	~Leaderboard();
};

