#include "Collectible.h"

Collectible::Collectible( Location& spawnLoc)
	:
	loc(spawnLoc)
{
}

void Collectible::Relocate(Location& newLoc)
{
	if (!isActive)
	{
		loc = newLoc;
		isActive = true;
	}
}

void Collectible::Draw(Board& brd) const
{
	if(isActive)
		brd.DrawCell(loc, Color(255, 255, 255));
}

void Collectible::Collider(Snake& snake)
{
	if (loc == snake.GetSnakeHeadPos())
	{
		snake.Grow();
		isActive = false;
	}
}
