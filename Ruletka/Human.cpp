#include "Human.h"

using std::vector;

Human::Human(std::wstring nick, int cash)
{
	this->nick = nick;
	this->cash = cash; 
}

void Human::setChoice(int cash, vector<int> numbers, vector<Color> colors)
{
 	setChoicePtr(new Choice(cash, numbers, colors));
}
