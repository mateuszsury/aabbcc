#include "Choice.h"

Choice::Choice(int cash, vector<int> numbers, vector<Color> colors)
{
	this->cash = cash;
	this->numbers = numbers;
	this->colors = colors;
}

vector<int> Choice::getNumbers()
{
	return numbers;
}

vector<Color> Choice::getColors()
{
	return colors;
}

int Choice::getCash()
{
	return this->cash;
}

Choice::Choice()
{
	this->cash = 0;
}
