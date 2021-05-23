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
	void CheckSelfCollision();
	bool CheckIfAlive();
	int GetSnakeSize();
	bool CheckConflictingSnakePosition(Location loc);
	void Score();
	int GetPoints();

private: 
	static constexpr int maxSnakeSize = 150;
	static constexpr Color headColor = Color(255, 255, 0);
	static constexpr Color bodyColor1 = Color(0, 130, 0);
	static constexpr Color bodyColor2 = Color(0, 170, 0);
	static constexpr Color bodyColor3 = Color(0, 210, 0);
	static constexpr Color bodyColor4 = Color(0, 255, 0);
	static constexpr Color bodyColor5 = Color(0, 90, 0);
	Segment segments[maxSnakeSize];
	int nSegments = 3;
	bool isAlive = true;
	int points = 0;
};
