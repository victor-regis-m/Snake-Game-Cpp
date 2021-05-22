#pragma once
#include "Graphics.h"
#include "Location.h"
class Board
{
public:
	Board(Graphics& gfx);
	void DrawFullCell(const Location& loc, Color c);
	void DrawOutlinedCell(const Location& loc, Color c);
	void DrawTitle(const Location& loc);
	void DrawBoardEdges();
	int GetBoardWidth() const;
	int GetBoardHeight() const;
	Location GetBoardCenter() const;
private:
	static constexpr int dimension=20;
	static constexpr int width=32;
	static constexpr int height=20;
	static constexpr int xCenter = Graphics::ScreenWidth / (2 * dimension);
	static constexpr int yCenter = Graphics::ScreenHeight / (2 * dimension);
	Graphics& gfx;
};