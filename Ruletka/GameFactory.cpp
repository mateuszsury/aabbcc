#include "GameFactory.h"

void GameFactory::save(Casino* casssino)
{
}

Casino* GameFactory::load()
{
    return nullptr;
}

Casino* GameFactory::create()
{
    return new Casino();
}
