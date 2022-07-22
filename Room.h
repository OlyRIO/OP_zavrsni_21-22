#pragma once
#include "Enemy.h"
#include <string>

class Room
{
private:
	std::string naziv;
	Enemy neprijatelj;
	Room* next;
public:
	Enemy getEnemy()
	{
		return neprijatelj;
	}
	void setEnemy(Enemy x)
	{
		neprijatelj = x;
	}
};

