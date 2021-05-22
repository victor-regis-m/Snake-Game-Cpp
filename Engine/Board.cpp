#pragma once
#include "Graphics.h"
#include "Board.h"

Board::Board(Graphics& gfx)
	:
	gfx(gfx)
{

}

void Board::DrawFullCell(const Location& loc, Color c)
{
	gfx.DrawRectDim(loc.x * dimension, loc.y * dimension, dimension, dimension, c);
}

void Board::DrawOutlinedCell(const Location& loc, Color c)
{
	gfx.DrawRectDim(loc.x * dimension+1, loc.y * dimension+1, dimension-1, dimension-1, c);
}

void Board::DrawTitle(const Location& loc)
{	
}

void Board::DrawBoardEdges()
{
	for (int i = -width / 2; i < (width+2) / 2; ++i)
	{
		DrawFullCell(Location{ xCenter + i, yCenter + height / 2 }, Color(255, 255, 255));
		DrawFullCell(Location{ xCenter + i, yCenter - height / 2 }, Color(255, 255, 255));
	}
	for (int j = -(height-2) / 2; j < height / 2; ++j)
	{
		DrawFullCell(Location{ xCenter + width / 2, yCenter + j }, Color(255, 255, 255));
		DrawFullCell(Location{ xCenter - width / 2, yCenter + j }, Color(255, 255, 255));
	}
}

int Board::GetBoardWidth() const
{
	return width;
}

int Board::GetBoardHeight() const
{
	return height;
}

Location Board::GetBoardCenter() const
{
	return Location{ xCenter, yCenter };
}
