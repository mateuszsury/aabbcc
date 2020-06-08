#include "Game.h"
#include <iostream>
#include "Human.h"
#include "Bot.h"

using std::wcout;
using std::wcin;

void Game::start(Casino* casino)
{
	srand(time(NULL));
	wcout << L"Rozpoczynamy grę" << std::endl;

	auto human = new Human(L"Mateusz", 100);
	vector<Bot*> bots;
	for (int i = 1; i <= 10; i++) {
		auto bot = new Bot();
		bots.push_back(bot);
		casino->addPlayer(bot);
	}

	casino->addPlayer(human);

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

	human->setChoice(10, nums, colors);

	for (auto b = bots.begin(); b < bots.end(); b++) {
		(*b)->makeRandomChoice();
	}
	casino->nextRound();
}
