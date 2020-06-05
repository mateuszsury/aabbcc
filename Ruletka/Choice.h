#pragma once
#include "Number.h"
#include "Color.h"
#include <vector>

using std::vector;

class Choice
{
	vector<int> numbers;
	vector<Color> colors;
	int cash;
public:
	Choice(int cash, vector<int>, vector<Color> colors);
	vector<int> getNumbers();
	vector<Color> getColors();
	int getCash();
	Choice();

};