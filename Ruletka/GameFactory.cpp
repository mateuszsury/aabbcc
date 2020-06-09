#include "GameFactory.h"
#include "Bot.h"
#include "Human.h"

#include <fstream>
#include <sstream>

using std::endl;

void GameFactory::save(Casino* casino)
{
    auto players = casino->getPlayers();
    std::wofstream myfile;
	myfile.open("save.txt");
    myfile << players.size() << '|';
    for (auto p = players.begin(); p < players.end(); p++)
    {
        Player* player = *p;
        bool isBot = player->isBot(); 

        myfile << player->nick << '|';
        myfile << (isBot ? 1 : 0) << '|';
        myfile << player->getCash() << '|';
    }
	myfile.close();
}
// 2|nick|0|123|nick|0|123


Casino* GameFactory::load()
{
    auto casino = new Casino();
    
    std::wifstream myfile;
	myfile.open("save.txt");
    int playerCount;
    wstring separator;
    myfile >> playerCount;
	myfile.get();
    
    for (int i = 0; i < playerCount; i++) 
    {
        wstring nick;
        int isBotInt;
        int cash;

        //std::wstringstream str;
        //wstring line;
        //myfile.getline(line.c_str, 100);
        //str << line;
        //str >> isBotInt;

        myfile >> nick;
        myfile.get();
        myfile >> isBotInt;
		myfile.get();
        myfile >> cash;
		myfile.get();

        bool isBot = isBotInt == 1;
        Player* p;
        if (isBot) {
            p = new Bot(nick, cash);
        }
        else {
            p = new Human(nick, cash);
        }

        casino->addPlayer(p);
    }
	myfile.close();

    return casino;

}

Casino* GameFactory::create()
{
    return new Casino();
}
