#pragma once
#include "Location.h"
#include "Board.h"
#include "Snake.h"
#include <random>

class Collectible
{
public:
	Collectible( Location& spawnLoc);
	bool Relocate(Location& newLoc , Snake& snake,
		std::mt19937& rng,
		std::uniform_int_distribution<int>& xDist,
		std::uniform_int_distribution<int>& yDist);
	void Draw(Board& brd) const;
	void Collider(Snake& snake);
private:
	Location loc;
	bool isActive = true;
};