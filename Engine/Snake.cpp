#pragma once
#include "Snake.h"

Snake::Snake(const Location& loc)
{
	segments[0].InitHead(loc);
}

void Snake::MoveBy(const Location& deltaLoc)
{
	for (int i = nSegments - 1; i > 0; --i)
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(deltaLoc);

}

void Snake::Grow()
{
	if (nSegments < maxSnakeSize)
	{
		++nSegments;
	}
}

void Snake::Draw(Board& brd) const
{
	for (int i = 0; i < nSegments; ++i)
		segments[i].Draw(brd);
}

void Snake::Segment::InitHead(const Location& locInput)
{
	loc = locInput;
	c = Snake::headColor;
}

void Snake::Segment::InitBody()
{
	c = Snake::bodyColor;
}

void Snake::Segment::Follow(const Segment& next)
{
	loc = next.loc;
}

void Snake::Segment::MoveBy(const Location& deltaLoc)
{
	loc.Add(deltaLoc);
}

void Snake::Segment::Draw(Board& brd) const
{
	brd.DrawCell(loc, c);
}
