#pragma once
#include "Location.h"
#include "Board.h"
#include "Snake.h"

class Collectible
{
public:
	Collectible( Location& spawnLoc);
	void Relocate(Location& newLoc);
	void Draw(Board& brd) const;
	void Collider(Snake& snake);
private:
	Location loc;
	bool isActive = true;
};