#pragma once
#include <string>
#include "Choice.h"

using std::wstring;

class Player
{

private:
	Choice* choice;
protected:
	int cash;
	std::wstring nick;
	void setChoicePtr(Choice* choice);
	Player(); 

public:
	~Player();
	Choice* getChoice();
	void giveCash(int amount);
	void takeCash(int amount);
	Player(std::wstring nick, int cash);
	int getCash();
};