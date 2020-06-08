#include "Casino.h"
#include <iostream>

using std::wcout;

Casino::Casino()
{
}

Casino::~Casino()
{
    players.clear();
}

void Casino::nextRound()
{ 
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
