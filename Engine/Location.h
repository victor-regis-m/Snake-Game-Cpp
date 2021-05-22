#pragma once
struct Location
{
	Location operator+=( const Location& rhs)
	{
		x = x + rhs.x;
		y = y + rhs.y;
		return *this;
	}
	friend Location operator+(const Location& lhs, const Location& rhs)
	{
		return Location{ lhs.x + rhs.x, lhs.y + rhs.y };
	}
	friend Location operator-(const Location& lhs, const Location& rhs)
	{
		return Location{ lhs.x - rhs.x, lhs.y - rhs.y };
	}
	bool operator!=( const Location& rhs)
	{
		return x != rhs.x || y != rhs.y;
	}
	bool operator==(const Location& rhs)
	{
		return x == rhs.x && y == rhs.y;
	}
	int x;
	int y;
};