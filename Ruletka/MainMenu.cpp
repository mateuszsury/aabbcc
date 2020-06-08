#include "MainMenu.h"
#include "GameFactory.h"
#include "Game.h"
#include <iostream>
using namespace std;

using std::wcout;

void MainMenu::show()
{ 
	GameFactory fucktory;

    setlocale(LC_ALL, "pl_PL");
	// wyśw. menu nowa gra, wczytaj
	int wybor;
	wcout << L"Wybierz opcję.\n1. Nowa gra\n2. Wczytaj gre" << std::endl;
	cin >> wybor;
	if (wybor == 1)
	{
		Casino* casino = fucktory.create();
		Game game(casino);
		game.start();
		fucktory.save(casino);
	}
	else if (wybor == 2)
	{

	}
}
