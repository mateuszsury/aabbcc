#include "Bot.h"


void Bot::makeRandomChoice()
{
	srand(time(NULL));
	int x = rand() % 4 + 1;

	if (x = 1) //bot losuje tylko kolor
	{
		srand(time(NULL));
		int c = rand() % 2 + 1;
	}
	else if (x = 2) //bot losuje tylko liczbe
	{
		srand(time(NULL));
		int l = rand() % 35 + 1;
	}
	else //bot losuje i kolor i liczbe
	{
		srand(time(NULL));
		int c = rand() % 2 + 1; //losowanie koloru

		srand(time(NULL));
		int l = rand() % 35 + 1; //losowanie liczby
	}

}

Bot::Bot()
{
}
