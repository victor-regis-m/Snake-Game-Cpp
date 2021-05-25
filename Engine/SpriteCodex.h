#pragma once

#include "Graphics.h"
#include "Snake.h"
#include "HighscoreTracker.h"

class SpriteCodex
{
public:
	static void DrawGameOver(int x, int y, Graphics& gfx);
	static void DrawTitle(int x, int y, Graphics& gfx);
	static void DrawScore(int x, int y, Snake& snake, Graphics& gfx);
	static void DrawNumber(int num, int x, int y, Color c, Graphics& gfx);
	static void DrawHighscore(int x, int y, HighscoreTracker& highscoreTracker, Graphics& gfx);
};