#include "MainMenu.h"
#include "GameFactory.h"
#include "Game.h"
#include <iostream>

using std::wcout;

void MainMenu::show()
{ 
	GameFactory fucktory;

    setlocale(LC_ALL, "pl_PL");
	// wyśw. menu nowa gra, wczytaj

	wcout << L"Wybierz opcję." << std::endl;
	Casino* casino = fucktory.create(); 
	Game game;
	game.start(casino);


	fucktory.save(casino);
}
