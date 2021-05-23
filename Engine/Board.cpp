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
	gfx.DrawRectDim(loc.x * dimension+1, loc.y * dimension+1, dimension-2, dimension-2, c);
}

void Board::DrawCollectible(const Location& loc)
{
	gfx.DrawRectDim(loc.x * dimension +1 , loc.y * dimension +1, dimension-2, dimension-2, Color(255,255,255));
	gfx.DrawRectDim((loc.x + 0.35)* dimension , (0.35+loc.y) * dimension, dimension*(0.3), dimension * (0.3), Color(0,0,0));

	gfx.DrawRectDim((loc.x) * dimension, (loc.y) * dimension, dimension * (0.2), dimension * (0.2), Color(0, 0, 0));

	gfx.DrawRectDim((loc.x + 0.8) * dimension, (loc.y) * dimension, dimension * (0.2), dimension * (0.2), Color(0, 0, 0));

	gfx.DrawRectDim((loc.x ) * dimension, (0.8 + loc.y) * dimension, dimension * (0.2), dimension * (0.2), Color(0, 0, 0));

	gfx.DrawRectDim((loc.x + 0.8) * dimension, (0.8 + loc.y) * dimension, dimension * (0.2), dimension * (0.2), Color(0, 0, 0));
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
