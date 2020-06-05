#include "Casino.h"
#include <iostream>


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
        std::wcout << "Kasa: " << player->getChoice()->getCash() << std::endl;
        auto numbers = player->getChoice()->getNumbers();
        for (auto it = numbers.begin(); it < numbers.end(); it++) {
            std::wcout << "liczby: " << *it << std::endl;
        }
        //std::wcout << "Kolory: " << player.getChoice().getColors() << std::endl; 
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
