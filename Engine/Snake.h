#pragma once
#include "Board.h"

class Snake
{
private:
	class Segment
	{
	public:
		void InitHead(const Location& locInput);
		void InitBody();
		void Follow(const Segment& next);
		void MoveBy(const Location& deltaLoc);
		void Draw(Board& brd) const;
	private:
		Location loc;
		Color c;
	};
public:
	Snake(const Location& loc);
	void MoveBy(const Location& deltaLoc);
	void Grow();
	void Draw(Board& brd) const;

private: 
	static constexpr int maxSnakeSize = 100;
	static constexpr Color headColor = Colors::Green;
	static constexpr Color bodyColor = Colors::Red;
	Segment segments[maxSnakeSize];
	int nSegments = 1;
};
