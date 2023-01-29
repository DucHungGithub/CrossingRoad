#include "../Header Files/LeaderBoard.h"
#include <fstream>
#include <iostream>
#include <string>
void Leaderboard::AddtoLeaderboard(std::string usn, int score) {
	bool added = false;
		for (int i = 0; i < num; i++) {
			if (score > totalscore[i]) {
				if (i < 2 && i == num) {
					if (num<3) num++;
					username[num] = usn;
				}
				else {
					for (int j = num - 1; j > i; j--) {
						username[j] = username[j - 1];
						totalscore[j] = totalscore[j - 1];
					}
					if (num < 3) num++;
				}
				totalscore[i] = score;
				username[i] = usn;
				added = true;
				break;
			}
		}
	if (num < 3 && !added) {
		username[num] = usn;
		totalscore[num] = score;
		num++;
	}
}
Leaderboard::Leaderboard() {
	num = 0;
	LoadLeaderboard();
}
void Leaderboard::LoadLeaderboard() {
	std::ifstream fin;
	fin.open(resourceDirectory + "Leaderboard.txt");
	while (!fin.eof() && num < 3) {
		getline(fin, username[num]);
		fin >> totalscore[num];
		fin.get();
		if(username[num]!="") num++;
	}
	fin.close();
}
void Leaderboard::SaveLeaderboard() {
	std::ofstream fout;
	fout.open(resourceDirectory + "Leaderboard.txt");
	for (int i = 0; i < num; i++) {
		fout << username[i] << std::endl;
		fout << totalscore[i] << std::endl;
	}
	fout.close();
}
Leaderboard::~Leaderboard() {
	SaveLeaderboard();
}
