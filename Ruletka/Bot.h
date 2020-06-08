#pragma once
#include "Player.h"
#include <time.h>

class Bot : public Player
{
public:
	void makeRandomChoice();
	Bot();
};