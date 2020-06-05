#pragma once
#include "Player.h"
#include <vector>

using std::vector;

class Casino
{
private:
	vector<Player*> players;
public:
	Casino();
	~Casino();

	void nextRound();
	vector<Player*> getPlayers();
	void addPlayer(Player* player);
	void removePlayer();
};