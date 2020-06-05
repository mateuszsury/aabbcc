#include "Game.h"
#include <iostream>
#include "Human.h"

void Game::start(Casino* casino)
{
	std::wcout << L"Rozpoczynamy grę" << std::endl; 

	auto human = new Human(L"Mateusz", 100);

	casino->addPlayer(human);

	std::wcout << L"Podaj liczbę którą obstawiasz: " << std::endl;

	//Color color = Color::Black;

	int chosenNumber;
	std::wcin >> chosenNumber;

	vector<int> nums;
	nums.push_back(chosenNumber); 

	human->setChoice(10, nums, {});

	casino->nextRound();


}
