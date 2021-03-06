#include "Collectible.h"
#include <random>

Collectible::Collectible( Location& spawnLoc)
	:
	loc(spawnLoc)
{
}

bool Collectible::Relocate(Location& newLoc, Snake& snake,
	std::mt19937& rng,
	std::uniform_int_distribution<int>& xDist,
	std::uniform_int_distribution<int>& yDist)
{
	if (!isActive)
	{
		while (snake.CheckConflictingSnakePosition(newLoc))
			newLoc = Location{ xDist(rng), yDist(rng) };
		loc = newLoc;
		isActive = true;
		return true;
	}
	return false;
}

void Collectible::Draw(Board& brd) const
{
	if(isActive)
		brd.DrawCollectible(loc);
}

void Collectible::Collider(Snake& snake)
{
	if (loc == snake.GetSnakeHeadPos())
	{
		snake.Grow();
		snake.Score();
		isActive = false;
	}
}
