#pragma once
#include "Casino.h"

class GameFactory
{
public:
	void save(Casino* casssino);
	Casino* load();
	Casino* create();
};
