#pragma once
#include "Snake.h"

Snake::Snake(const Location& loc)
{
	segments[0].InitHead(loc);
	for (int i = 1; i < maxSnakeSize; i++)
		segments[i].InitBody(loc, i);
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
		Location lastBlockPos = segments[nSegments - 1].GetPos();
		Location direction = segments[nSegments - 1].GetPos() - segments[nSegments - 2].GetPos();;
		segments[nSegments++].SetPos(lastBlockPos + direction);
	}
}

void Snake::Draw(Board& brd) const
{
	if(isAlive)
		for (int i = 0; i < nSegments; ++i)
			segments[i].Draw(brd);
}

Location& Snake::GetSnakeHeadPos()
{
	return segments[0].GetPos();
}

void Snake::CheckHeadInBoard(const Board& brd)
{
	Location center = brd.GetBoardCenter();
	int halfWidth = brd.GetBoardWidth() / 2;
	int halfHeight = brd.GetBoardHeight() / 2;
	Location headPos = GetSnakeHeadPos();
	isAlive = headPos.x > center.x - halfWidth &&
		headPos.x < center.x + halfWidth &&
		headPos.y > center.y - halfHeight &&
		headPos.y < center.y + halfHeight;
}

void Snake::Segment::InitHead(const Location& locInput)
{
	loc = locInput;
	c = Snake::headColor;
}

void Snake::Segment::InitBody(const Location& locInput, int i)
{
	Location locHead = locInput;
	c = Snake::bodyColor;
	locHead+=(Location{ i,0 });
	loc = locHead;
}

void Snake::Segment::Follow(const Segment& next)
{
	loc = next.loc;
}

void Snake::Segment::MoveBy(const Location& deltaLoc)
{
	loc+=(deltaLoc);
}

void Snake::Segment::Draw(Board& brd) const
{
	brd.DrawCell(loc, c);
}

Location& Snake::Segment::GetPos()
{
	return loc;
}

void Snake::Segment::SetPos(const Location& newLoc)
{
	loc = newLoc;
}
