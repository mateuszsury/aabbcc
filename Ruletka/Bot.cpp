#include "Bot.h"
#include <sstream>

void Bot::makeRandomChoice()
{
	int c;
	int l;
	int cash = rand() % 10 + 1;
	vector<Color> colors;
	vector<int> numbers;

	bool betColor = rand() % 2 == 1;
	bool betNumber = rand() % 2 == 1;

	if (betColor) //bot losuje tylko kolor
	{
		int c = rand() % 2 + 1;
		colors.push_back(c == 1 ? Color::Black : Color::Red);
	}

	if (betNumber) //bot losuje tylko liczbe
	{
		int l = rand() % 35 + 1;
		numbers.push_back(l);
	}

	setChoicePtr(new Choice(cash, numbers, colors));
}

Bot::Bot(int cash)
{
	std::wstringstream botNameStr;
	botNameStr << L"Bot " << rand() % 1000;
	this->nick = botNameStr.str();
	this->cash = cash;
}
