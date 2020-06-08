#include "Game.h"
#include <iostream>
#include <tuple>
#include "Human.h"
#include "Bot.h"

using std::wcout;
using std::wcin;
using std::endl;
using std::pair;

void Game::start()
{
	srand(time(NULL));
	wcout << L"Rozpoczynamy grę" << std::endl;

	// funkcja dodająca gracza ludzkiego i n botów do kasyna. Zwraca utworzone obiekty w kontenerze "pair"
	pair<vector<Bot*>, Human*> players = addPlayers(L"Mateusz", 10);

	// wyświetlanie wyniku losowania - do wyszukania w google "C++ lambdas".
	casino->randomizeFinishHandler = [this](int n, Color c) { this->randomizeFinishHandler(n, c); };

	// Wyświetlanie stanu portfeli graczy
	status();

	bool play = true;
	while (play) {
		
		round(players);

		status();

		play = checkContinuePlaying(players.second);
	}
}

void Game::status()
{
	auto players = casino->getPlayers();
	for (auto i = players.begin(); i < players.end(); i++) {
		wcout << L"Gracz " << (*i)->nick << ": " << (*i)->getCash() << " PLN";
		wcout << endl;
	}
}

pair<vector<Bot*>, Human*> Game::addPlayers(wstring humanName, int botCount)
{
	auto human = new Human(humanName, 100);
	casino->addPlayer(human);
	vector<Bot*> bots;
	for (int i = 1; i <= 10; i++) {
		auto bot = new Bot(100);
		bots.push_back(bot);
		casino->addPlayer(bot);
	}
	return std::make_pair(bots, human);
}

Choice Game::makeChoice()
{
	wcout << L"Podaj kolor - 0 żaden 1 czarny 2 czerwony: " << std::endl;
	int colorNum = 0;
	wcin >> colorNum;

	vector<Color> colors;

	if (colorNum == 1) {
		colors.push_back(Color::Black);
	}
	else if (colorNum == 2) {
		colors.push_back(Color::Red);
	}

	vector<int> nums;
	bool choosing = true;
	while (choosing) {
		wcout << L"Podaj liczbę którą obstawiasz (0 - koniec): " << std::endl; 
		int chosenNumber; 
		wcin >> chosenNumber; 
		if (chosenNumber > 0) { 
			nums.push_back(chosenNumber);
		}
		else {
			choosing = false;
		}
	}
	wcout << L"Podaj ile kasy obstawiasz: " << std::endl; 
	int cash;
	wcin >> cash;

	return Choice(cash, nums, colors);
}

void Game::randomizeFinishHandler(int winNumber, Color winColor)
{ 
	wcout << L"======================" << endl;
    wcout << L"Wygrywająca liczba: " << winNumber << endl;
    wcout << L"Wygrywający kolor: " << (winColor == Color::Black ? "czarny" : "czerwony") << endl;
	wcout << L"======================" << endl;
}

Game::Game(Casino* casino)
{
	this->casino = casino;
}

bool Game::checkContinuePlaying(Player* player)
{
	bool play;
	if (player->getCash() <= 0) {
		wcout << L"Przegrałeś, nie masz już kasy!" << endl;
		play = false;
	}
	else {
		wcout << L"Czy chcesz grać dalej? (1 - tak, 0 - nie) ";
		int continuePlaying;
		wcin >> continuePlaying;
		play = continuePlaying == 1;
	}
	return play;
}

void Game::round(pair<vector<Bot*>, Human*> players)
{
	bool choosing = true; 
	while (choosing) {
		Choice choice = makeChoice(); 
		try {
			players.second->setChoice(choice.getCash(), choice.getNumbers(), choice.getColors());
			choosing = false;
		}
		catch (int errCode) {
			if (errCode == Player::NOT_ENOUGH_CASH) {
				wcout << L"Za mało pieniędzy!" << endl;
			}
		}
	}
	for (auto bot = players.first.begin(); bot < players.first.end(); bot++) {
		(*bot)->makeRandomChoice();
	}

	casino->nextRound();
}

