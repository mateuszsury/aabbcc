#include "Player.h"

Choice* Player::getChoice()
{
    return choice;
}

void Player::giveCash(int amount)
{
}

void Player::takeCash(int amount)
{
}

void Player::setChoicePtr(Choice* choice)
{
    if (this->choice != nullptr) {
        delete this->choice;
    }
    this->choice = choice;
}

Player::Player()
{
    this->cash = 0; 
    this->choice = nullptr;
}

Player::~Player()
{
    if (this->choice != nullptr) {
        delete choice;
    }
}

Player::Player(std::wstring nick, int cash)
{
    this->cash = cash; 
    this->nick = nick;
    this->choice = nullptr;
}

int Player::getCash()
{
    return 0;
}
