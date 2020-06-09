#pragma once
#include "Casino.h"
#include "Bot.h"
#include "Human.h"
using std::pair;

class Game
{
	Casino* casino;

	void status();
	bool checkContinuePlaying(Player* player);
	void round(pair<vector<Bot*>, Human*> players);
	pair<vector<Bot*>, Human*> addPlayers();
	Choice makeChoice();
	void randomizeFinishHandler(int number, Color color);
public:
	void start();
	Game(Casino* casino);
};