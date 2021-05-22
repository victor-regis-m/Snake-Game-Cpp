#pragma once

#include "Graphics.h"
#include "Snake.h"

class SpriteCodex
{
public:
	static void DrawGameOver(int x, int y, Graphics& gfx);
	static void DrawTitle(int x, int y, Graphics& gfx);
	static void ShowScore(int x, int y, Snake& snake, Graphics& gfx);
	static void DrawNumber(int num, int x, int y, Color c, Graphics& gfx);
};