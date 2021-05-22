#pragma once
#include "Board.h"

class Snake
{
private:
	class Segment
	{
	public:
		void InitHead(const Location& locInput);
		void InitBody(const Location& locInput, const int i);
		void Follow(const Segment& next);
		void MoveBy(const Location& deltaLoc);
		void Draw(Board& brd) const;
		Location& GetPos();
		void SetPos(const Location& newLoc);
	private:
		Location loc;
		Color c;
	};
public:
	Snake(const Location& loc);
	void MoveBy(const Location& deltaLoc);
	void Grow();
	void Draw(Board& brd) const;
	Location& GetSnakeHeadPos();
	void CheckHeadInBoard(const Board& brd);

private: 
	static constexpr int maxSnakeSize = 100;
	static constexpr Color headColor = Colors::Yellow;
	static constexpr Color bodyColor = Colors::Green;
	Segment segments[maxSnakeSize];
	int nSegments = 3;
	bool isAlive = true;
};
