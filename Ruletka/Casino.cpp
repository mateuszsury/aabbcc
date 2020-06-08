#include "Casino.h"
#include <iostream>

using std::wcout;
using std::endl;

Casino::Casino()
{
}

Casino::~Casino()
{
    for (auto p = players.begin(); p < players.end(); p++)
    {
        delete* p;
    }
    players.clear();
}

void Casino::nextRound()
{ 
    /*
    for (auto i = players.begin(); i < players.end(); i++) {
        Player* player = *i;
        wcout << "Gracz " << player->nick << std::endl;
        
        wcout << "Kasa: " << player->getChoice()->getCash() << std::endl;
        auto numbers = player->getChoice()->getNumbers();
        wcout << "liczby: ";
        for (auto it = numbers.begin(); it < numbers.end(); it++) {
            wcout << *it << std::endl;
        }
        auto colors = player->getChoice()->getColors();
        for (auto it = colors.begin(); it < colors.end(); it++) {
            wstring col = *it == Color::Black ? L"czarny" : L"czerwony";
            wcout << "kolor: " << col << std::endl;
        }
        wcout << std::endl;
    }
*/
    /*
    1. Gracz obstawił x na kolor
       0) traci x
       1) dostaje x
    2. Gracz obstawił x na liczbę
       0) traci x
       1) dostaje 34x
   */

    int winNumber = rand() % 35 + 1;
    Color winColor = winNumber % 2 ? Color::Black : Color::Red;

    if (randomizeFinishHandler) {
        randomizeFinishHandler(winNumber, winColor);
    }

	for (auto i = players.begin(); i < players.end(); i++) {
		Player* player = *i;
		Choice* choice = player->getChoice();
        if (choice == nullptr) {
            continue;
        }
        int cash = choice->getCash();

		if (!choice->getColors().empty()) {
            bool success = choice->getColors()[0] == winColor;
			if (success) {
				player->giveCash(cash);
			}
			else {
				player->takeCash(cash);
			}
		}

        auto numbers = choice->getNumbers();

		for (auto n = numbers.begin(); n < numbers.end(); n++) {
			if (*n == winNumber) {
                int win = 34 * cash;
				player->giveCash(win);
			}
			else {
                int loss = cash;
				player->takeCash(loss);
			}
		}
	}
}

vector<Player*> Casino::getPlayers()
{
    return this->players;
}

void Casino::addPlayer(Player* player)
{
    players.push_back(player);
}

void Casino::removePlayer()
{
}
